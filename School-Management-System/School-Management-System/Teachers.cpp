#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include "Teachers.hpp"
#include "Subjects.hpp"

using namespace std;

//=========================================constructor and destructor============================================

Teachers::Teachers()
{

}

Teachers::~Teachers()
{

}

//==========================================Sort and search functions=========================================

//Merge function that merges two sorted subarrays
/*
Explanation how this work in details:
1. The function takes the vector teachers and the indexes of the left, middle, and right subarrays.
2. It calculates the sizes of the left and right subarrays.
3. It creates two vectors L and R to store the left and right subarrays.
4. It copies the data from the teachers vector to the left and right subarrays.
5. It compares the current elements of the left and right subarrays.
6. If the element from the left subarray is smaller (or equal) ==> it is placed into the vector teachers.
7. Otherwise, the element from the right subarray is placed into the vector teachers.
8. The remaining elements in both left and right subarrays are stored into vector teachers.
9. The function is called recursively until the left index is smaller than the right index.
*/
void Teachers::merge(vector<Teacher>& teachers, int left, int middle, int right)
{
	int i, j, k; //Indexes for the left, right, and merged subarrays
	int n1 = middle - left + 1; //Size of the left subarray
	int n2 = right - middle; //Size of the right subarray

	vector<Teacher> L; //Left subarray
	vector<Teacher> R; //Right subarray

	//Copy the data to the left and right subarrays
	for (i = 0; i < n1; i++) //Copy to left array
	{
		L.push_back(teachers.at(left + i));
	}

	for (j = 0; j < n2; j++) //Copy to right array
	{
		R.push_back(teachers.at(middle + 1 + j));
	}

	i = 0;
	j = 0;
	k = left;

	// This loop compares the current elements of the left and right sub-arrays.
	// If the element from the left sub-array is smaller (or equal) ==> it is placed into the vector teachers.
	// Otherwise, the element from the right sub-array is placed into the vector teachers.
	while (i < n1 && j < n2)
	{
		if (L.at(i).name <= R.at(j).name)
		{
			teachers.at(k) = L.at(i);
			i++;
		}
		else
		{
			teachers.at(k) = R.at(j);
			j++;
		}
		k++;
	}

	//These loops are used to store the remaining elements in both left and right sub-arrays into vector teachers.
	while (i < n1)
	{
		teachers.at(k) = L.at(i);
		i++;
		k++;
	}
	while (j < n2)
	{
		teachers.at(k) = R.at(j);
		j++;
		k++;
	}
}

//Recursive merge sort function
/*
Explanation how this work in details:
1. The function takes the vector teachers and the indexes of the left and right subarrays.
2. It calculates the middle of the array.
3. It divides the array from the right and left.
4. It sorts and merges the two sub-arrays into one sorted array.
5. The function is called recursively until the left index is smaller than the right index.
*/
void Teachers::merge_sort(vector<Teacher>& teachers, int left, int right)
{
	if (left < right)
	{
		//Used to get the middle of the array.
		//Applied in this way because the start of the array may differ as we will divide it many times.
		int middle = left + (right - left) / 2;

		// Divide the array from the right and left
		merge_sort(teachers, left, middle);
		merge_sort(teachers, middle + 1, right);

		//Sort and merge the two sub-arrays into one sorted array
		merge(teachers, left, middle, right);
	}
}

//Binary search function for the teachers by name
/*
Explanation how this work in details :
1. The function takes the vector teachers, the name of the teacher, and the indexes of the left and right subarrays.
2. It calculates the middle of the array.
3. It checks if the name is present at the middle.
4. If the name is greater, it ignores the left half.
5. If the name is smaller, it ignores the right half.
6. The function is called recursively until the left index is smaller than the right index.
7. If the name is not found, the function returns -1.
*/
int Teachers::binary_search(vector<Teacher>& teachers, string name, int left, int right)
{
	while (left <= right)
	{
		//Get the middle of the array
		int middle = left + (right - left) / 2;

		// Check if the name is present at the middle
		if (teachers.at(middle).name == name)
		{
			return middle;
		}

		// If the name is greater, ignore the left half
		if (teachers.at(middle).name < name)
		{
			left = middle + 1;
		}
		// If the name is smaller, ignore the right half
		else
		{
			right = middle - 1;
		}
	}

	// Name not found
	return -1;
}

//===========================================Functions for the teachers=========================================

//add a new Teacher
void Teachers::add_teacher(Teacher my_teacher)
{
	Teacher teacher{my_teacher};

	teachers.push_back(teacher);

	merge_sort(teachers, 0, teachers.size() - 1);
}

//remove a Teacher by name
void Teachers::remove_teacher(string name)
{
	int index = binary_search(teachers, name, 0, teachers.size() - 1);
	if (index == -1)
	{
		cout << "The teacher is not found!" << endl;
	}
	else
	{
		// Removes the intended teacher
		teachers.erase(teachers.begin() + index);
		cout << "The teacher was removed successfully!" << endl;
	}
}

//display all the Teachers
void Teachers::display_all_teachers() const
{
	/*
	* 'setw' stands for "Set Width." It defines the minimum space (width) a value will occupy when displayed.
	* If the value is shorter than the specified width, extra spaces are added to the left.
	* If the value is longer than the width, it is displayed fully
	*/
	cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
	cout << left << setw(5) << "ID" << setw(20) << "Name" << setw(5) << "Age" << setw(10) << "Gender" << setw(15) << "Phone Number" << setw(25) << "Email" << setw(20) << "Date of Joining" << setw(20) << "Qualification" << endl;
	cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i{ 0 }; i < teachers.size(); i++)
	{
		cout << left << setw(5) << teachers.at(i).id << setw(20) << teachers.at(i).name << setw(5) << teachers.at(i).age << setw(10) << teachers.at(i).gender << setw(15) << teachers.at(i).phone_number << setw(25) << teachers.at(i).email << setw(20) << teachers.at(i).date_of_joining << setw(20) << teachers.at(i).qualification << endl;
	}
}

//display the information of a specific Teacher using name
void Teachers::dispaly_teacher_info(string name)
{
	int index = binary_search(teachers, name, 0, teachers.size() - 1);
	if (index == -1)
	{
		cout << "The teacher is not found!" << endl;
	}
	else
	{
		teachers.at(index).display_info();
	}
}

//Edit the information of a specific Teacher using name
void Teachers::edit_teacher_info(int id, string name, int age, string gender, int phone_number, string email, Subject subs[2], string date_of_joining, string qualification)
{
	int index = binary_search(teachers, name, 0, teachers.size() - 1);
	if (index == -1)
	{
		cout << "The teacher is not found!" << endl;
	}
	else
	{
		teachers.at(index).id = id;
		teachers.at(index).name = name;
		teachers.at(index).age = age;
		teachers.at(index).gender = gender;
		teachers.at(index).phone_number = phone_number;
		teachers.at(index).email = email;
		teachers.at(index).subs[0] = subs[0];
		teachers.at(index).subs[1] = subs[1];
		teachers.at(index).date_of_joining = date_of_joining;
		teachers.at(index).qualification = qualification;

		cout << "Teacher information was edited successfully!" << endl;

		merge_sort(teachers, 0, teachers.size() - 1);
	}
}

//save the information of all the Teachers to a txt file
void Teachers::save_teachers()
{
	ofstream file;
	file.open("teachers.txt");
	if (file.is_open())
	{
		for (int i{ 0 }; i < teachers.size(); i++)
		{
			file << teachers.at(i).id << " "
				<< teachers.at(i).name << ", "
				<< teachers.at(i).age << " "
				<< teachers.at(i).gender << " "
				<< teachers.at(i).phone_number << " "
				<< teachers.at(i).email << " "
				<< teachers.at(i).subs[0].name << " "
				<< teachers.at(i).subs[1].name << " "
				<< teachers.at(i).date_of_joining << " "
				<< teachers.at(i).qualification << endl;
		}

		file.close();

		cout << "Teachers information saved successfully!" << endl;
	}
	else
	{
		cout << "The file could not be opened!" << endl;
	}
}

// Loads the information of all the Teachers from a txt file.
void Teachers::load_teachers()
{
	ifstream file("teachers.txt");
	if (file.is_open())
	{
		teachers.clear();

		int id;
		string name;
		int age;
		string gender;
		int phone_number;
		string email;
		string sub1_name;
		string sub2_name;
		string date_of_joining;
		string qualification;
		Subject subs[2];
		Subjects subjects;

		while (file >> id >> ws && getline(file, name, ',') >> age >> gender >> phone_number >> email >> sub1_name >> sub2_name >> date_of_joining >> qualification)
		{
			for (int i = 0; i < 2; i++)
			{
				string sub_name;
				if (i == 0)
				{
					sub_name = sub1_name;
				}
				else
				{
					sub_name = sub2_name;
				}
				for (const Subject& subject : subjects.subjects)
				{
					if (subject.name == sub_name)
					{
						subs[i] = subject;
						break;
					}
				}
			}

			Teacher teacher(id, name, age, gender, phone_number, email, subs, date_of_joining, qualification);
			teachers.push_back(teacher);
		}

		file.close();
	}
}

vector<Teacher> Teachers::get_dataset()
{
	return teachers;
}

int Teachers::get_id(const Teacher& my_teacher)
{
	return my_teacher.id;
}

int Teachers::get_length()
{
	return teachers.size();
}