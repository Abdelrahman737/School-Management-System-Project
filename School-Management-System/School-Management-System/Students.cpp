#include <iostream>
#include <vector>
#include <fstream>
#include "Students.hpp"
#include "Student.hpp"
#include "Subject.hpp"
#include "Subjects.hpp"

using namespace std;

//=========================================constructor and destructor============================================
Students::Students()
{

}

//destructor
Students::~Students()
{

}

//===========================================Sort and search functions=========================================

//Merge function that merges to sorted functions
/*
Explanation how this work in details:
1. The function takes the vector students and the indexes of the left, middle, and right subarrays.
2. It calculates the sizes of the left and right subarrays.
3. It creates two vectors L and R to store the left and right subarrays.
4. It copies the data from the students vector to the left and right subarrays.
5. It compares the current elements of the left and right subarrays.
6. If the element from the left subarray is smaller (or equal) ==> it is placed into the vector students.
7. Otherwise, the element from the right subarray is placed into the vector students.
8. The remaining elements in both left and right subarrays are stored into vector students.
9. The function is called recursively until the left index is smaller than the right index.
*/
void Students::merge(vector<Student>& students, int left, int middle, int right)
{
	int i, j, k; //Indexes for the left, right, and merged subarrays
	int n1 = middle - left + 1; //Size of the left subarray
	int n2 = right - middle; //Size of the right subarray

	vector<Student> L; //Left subarray
	vector<Student> R; //Right subarray

	//Copy the data to the left and right subarrays

	for (i = 0; i < n1; i++) //Copy to right array
	{
		L.push_back(students.at(left + i));
	}

	for (j = 0; j < n2; j++) //Copy to left array
	{
		R.push_back(students.at(middle + 1 + j));
	}

	i = 0;
	j = 0;
	k = left;

	// This loop compares the current elements of the left and right sub-arrays.
	// If the element from the left sub-array is smaller (or equal) ==> it is placed into the vector students.
	// Otherwise, the element from the right sub-array is placed into the vector students.
	while (i < n1 && j < n2)
	{
		if (L.at(i).name <= R.at(j).name)
		{
			students.at(k) = L.at(i);
			i++;
		}
		else
		{
			students.at(k) = R.at(j);
			j++;
		}
		k++;
	}

	//These loops are used to store the remaining elements in both left and right sub-arrays into vector students.
	while (i < n1)
	{
		students.at(k) = L.at(i);
		i++;
		k++;
	}
	while (j < n2)
	{
		students.at(k) = R.at(j);
		j++;
		k++;
	}
}

//Recursive merge sort function
/*
Explanation how this work in details:
1. The function takes the vector students and the indexes of the left and right subarrays.
2. It calculates the middle of the array.
3. It divides the array from the right and left.
4. It sorts and merges the two sub-arrays into one sorted array.
5. The function is called recursively until the left index is smaller than the right index.
*/
void Students::merge_sort(vector<Student>& students, int left, int right)
{
	if (left < right)
	{
		//Used to get the middle of the array.
		//Applied in this way because the start of the array may differ as we will divide it many times.
		int middle = left + (right - left) / 2;

		// Divide the array from the right and left
		merge_sort(students, left, middle);
		merge_sort(students, middle + 1, right);

		//Sort and merge the two sub-arrays into one sorted array
		merge(students, left, middle, right);
	}
}

//Binary search function for the students by name
/*
Explanation how this work in details :
1. The function takes the vector students, the name of the student, and the indexes of the left and right subarrays.
2. It calculates the middle of the array.
3. It checks if the name is present at the middle.
4. If the name is greater, it ignores the left half.
5. If the name is smaller, it ignores the right half.
6. The function is called recursively until the left index is smaller than the right index.
7. If the name is not found, the function returns -1.
*/
int Students::binary_search(vector<Student>& students, string name, int left, int right)
{
	while (left <= right)
	{
		//Get the middle of the array
		int middle = left + (right - left) / 2;

		// Check if the name is present at the middle
		if (students.at(middle).name == name)
		{
			return middle;
		}

		// If the name is greater, ignore the left half
		if (students.at(middle).name < name)
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


//===========================================Functions for the students=========================================

//add a new student
void Students::add_student(string name, int id, int age, int grade, string gender, int phone_number)
{
	Student student{id, name, age, gender, phone_number, grade};

	students.push_back(student);

	merge_sort(students, 0, students.size() - 1);
}

//display the information of a specific student
void Students::display_student_info(string name)
{
	int index = binary_search(students, name, 0, students.size() - 1);
	if (index == -1)
	{
		cout << "The student is not found!" << endl;
	}
	else
	{
		students.at(index).display_info();
	}
}

//Display the information of all the students
void Students::display_all_students()
{
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "ID" << "\t" << "Name" << "\t" << "Age" << "\t" << "Gender" << "\t" << "Phone Number" << "\t" << "Grade" << "\t" << "Attandance precentage" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i{ 0 }; i < students.size(); i++)
	{
		cout << students.at(i).id << "\t" << students.at(i).name << "\t" << students.at(i).age << "\t" << students.at(i).gender << "\t" << students.at(i).phone_number << "\t" << students.at(i).grade << "\t" << students.at(i).attendance_percentage << endl;
	}
}

//remove a student
void Students::remove_student(string name)
{
	int index = binary_search(students, name, 0, students.size() - 1);
	if (index == -1)
	{
		cout << "The student is not found!" << endl;
	}
	else
	{
		//Removes the intended student
		students.erase(students.begin() + index);
		cout << "The student was removed successfully!" << endl;
	}
}

//edit the information of a student
void Students::edit_student_info(string search_input, string name, int id, int age, int grade, string gender, int phone_number)
{
	int index = binary_search(students, search_input, 0, students.size() - 1);
	if (index == -1)
	{
		cout << "The student is not found!" << endl;
	}
	else
	{
		students.at(index).name = name;
		students.at(index).id = id;
		students.at(index).age = age;
		students.at(index).grade = grade;
		students.at(index).phone_number = phone_number;

		cout << "Student information was edited successfully!" << endl;
	}
}

//save the information of all the students to a txt file
void Students::save_students()
{
	ofstream file;
	file.open("students.txt");
	if (file.is_open())
	{
		for (int i{ 0 }; i < students.size(); i++)
		{
			file << students.at(i).id << " " 
				 << students.at(i).name << " " 
				 << students.at(i).age << " " 
				 << students.at(i).gender << " " 
				 << students.at(i).phone_number << " " 
				 << students.at(i).grade << " " 
				 << students.at(i).attendance_percentage;

			for (int j{ 0 }; j < students.at(i).marks_per_subject.size(); j++)
			{
				file << " " << students.at(i).marks_per_subject.at(j);
			}

			file << endl;
		}

		file.close();

		cout << "Students information saved successfully!" << endl;
	}
	else
	{
		cout << "The file could not be opened!" << endl;
	}
}


//load the information of all the students from a txt file
void Students::load_students()
{
	ifstream file;
	file.open("students.txt");
	if (file.is_open())
	{
		students.clear();

		while (!file.eof())
		{
			int id;
			string name;
			int age;
			string gender;
			int phone_number;
			int grade;
			float attendance_percentage;
			vector<int> marks_per_subject;

			file >> id >> name >> age >> gender >> phone_number >> grade >> attendance_percentage;

			Student student(id, name, age, gender, phone_number, grade);

			for (int i{ 0 }; i < student.subjects.size(); i++)
			{
				int marks;
				file >> marks;
				marks_per_subject.push_back(marks);
			}

			student.attendance_percentage = attendance_percentage;

			for (int i {0}; i < student.subjects.size(); i++)
			{
				student.marks_per_subject.push_back(marks_per_subject.at(i));
			}

			students.push_back(student);
		}

		file.close();

		cout << "Admins information loaded successfully!" << endl;
	}
	else
	{
		cout << "The file could not be opened!" << endl;
	}
}

//Set the attendance percentage of a student
void Students::set_attendance_percentage(string name, float attendance_percentage)
{
	int index = binary_search(students, name, 0, students.size() - 1);
	if (index == -1)
	{
		cout << "The student is not found!" << endl;
	}
	else
	{
		students.at(index).attendance_percentage = attendance_percentage;
		cout << "The attendance percentage was set successfully!" << endl;
	}
}

//Set the marks of a student
void Students::set_marks(string name, vector<int> marks)
{
	int index = binary_search(students, name, 0, students.size() - 1);
	if (index == -1)
	{
		cout << "The student is not found!" << endl;
	}
	else
	{
		students.at(index).marks_per_subject = marks;
		cout << "The marks were set successfully!" << endl;
	}
}