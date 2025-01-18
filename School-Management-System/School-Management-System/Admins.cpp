#include <iostream>
#include <fstream>
#include <iomanip> //We are using this for setw, to organize the data represented using display_all function
#include <string>
#include <vector>
#include "Admins.hpp"

using namespace std;

//=========================================constructor and destructor============================================

Admins::Admins()
{

}

Admins::~Admins()
{

}

//==========================================Sort and search functions=========================================

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
void Admins::merge(vector<Admin>& admins, int left, int middle, int right)
{
	int i, j, k; //Indexes for the left, right, and merged subarrays
	int n1 = middle - left + 1; //Size of the left subarray
	int n2 = right - middle; //Size of the right subarray

	vector<Admin> L; //Left subarray
	vector<Admin> R; //Right subarray

	//Copy the data to the left and right subarrays

	for (i = 0; i < n1; i++) //Copy to right array
	{
		L.push_back(admins.at(left + i));
	}

	for (j = 0; j < n2; j++) //Copy to left array
	{
		R.push_back(admins.at(middle + 1 + j));
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
			admins.at(k) = L.at(i);
			i++;
		}
		else
		{
			admins.at(k) = R.at(j);
			j++;
		}
		k++;
	}

	//These loops are used to store the remaining elements in both left and right sub-arrays into vector students.
	while (i < n1)
	{
		admins.at(k) = L.at(i);
		i++;
		k++;
	}
	while (j < n2)
	{
		admins.at(k) = R.at(j);
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
void Admins::merge_sort(vector<Admin>& admins, int left, int right)
{
	if (left < right)
	{
		//Used to get the middle of the array.
		//Applied in this way because the start of the array may differ as we will divide it many times.
		int middle = left + (right - left) / 2;

		// Divide the array from the right and left
		merge_sort(admins, left, middle);
		merge_sort(admins, middle + 1, right);

		//Sort and merge the two sub-arrays into one sorted array
		merge(admins, left, middle, right);
	}
}


//Binary search function for the admins by name
/*
Explanation how this work in details :
1. The function takes the vector admins, the name of the admin, and the indexes of the left and right subarrays.
2. It calculates the middle of the array.
3. It checks if the name is present at the middle.
4. If the name is greater, it ignores the left half.
5. If the name is smaller, it ignores the right half.
6. The function is called recursively until the left index is smaller than the right index.
7. If the name is not found, the function returns -1.
*/
int Admins::binary_search_by_name(vector<Admin>& admins, string name, int left, int right)
{
	while (left <= right)
	{
		//Get the middle of the array
		int middle = left + (right - left) / 2;

		// Check if the name is present at the middle
		if (admins.at(middle).name == name)
		{
			return middle;
		}

		// If the name is greater, ignore the left half
		if (admins.at(middle).name < name)
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

//===========================================Functions for the admins=========================================

//add a new Admin
void Admins::add_admin(Admin my_admin)
{
	Admin admin{my_admin};

	admins.push_back(admin);

	merge_sort(admins, 0, admins.size() - 1);
}

//remove an Admin by username
void Admins::remove_admin(string name)
{
	int index = binary_search_by_name(admins, name, 0, admins.size() - 1);
	if (index == -1)
	{
		cout << "The admin is not found!" << endl;
	}
	else
	{
		// Removes the intended admin
		admins.erase(admins.begin() + index);
		cout << "The admin was removed successfully!" << endl;
	}
}

//display all the Admins
void Admins::display_all_admins() const
{
	/*
	* 'setw' stands for "Set Width." It defines the minimum space (width) a value will occupy when displayed.
	* If the value is shorter than the specified width, extra spaces are added to the left.
    * If the value is longer than the width, it is displayed fully
	*/
	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
	cout << left << setw(5) << "ID" << setw(20) << "Name" << setw(5) << "Age" << setw(10) << "Gender" << setw(15) << "Phone Number" << setw(15) << "Username" << endl;
	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
	for (int i{ 0 }; i < admins.size(); i++)
	{
		cout << left << setw(5) << admins.at(i).id << setw(20) << admins.at(i).name << setw(5) << admins.at(i).age << setw(10) << admins.at(i).gender << setw(15) << admins.at(i).phone_number << setw(15) << admins.at(i).username << endl;
	}
}

//display the information of a specific Admin using username
void Admins::display_admin_info(string name)
{
	int index = binary_search_by_name(admins, name, 0, admins.size() - 1);
	if (index == -1)
	{
		cout << "The admin is not found!" << endl;
	}
	else
	{
		admins.at(index).display_info();
	}
}


//Edit the information of a specific Admin using username
void Admins::edit_admin_info(int id, string name, int age, string gender, int phone_number, string new_username, string password)
{
	int index = binary_search_by_name(admins, name, 0, admins.size() - 1);
	if (index == -1)
	{
		cout << "The admin is not found!" << endl;
	}
	else
	{
		admins.at(index).id = id;
		admins.at(index).name = name;
		admins.at(index).age = age;
		admins.at(index).gender = gender;
		admins.at(index).phone_number = phone_number;
		admins.at(index).username = new_username;
		admins.at(index).password = password;

		cout << "Admin information was edited successfully!" << endl;

		merge_sort(admins, 0, admins.size() - 1);
	}
}



//save the information of all the Admins to a txt file
void Admins::save_admins()
{
	ofstream file;
	file.open("admins.txt");
	if (file.is_open())
	{
		for (int i{ 0 }; i < admins.size(); i++)
		{
			file << admins.at(i).id << " "
				 << admins.at(i).name << ", "
				 << admins.at(i).age << " "
				 << admins.at(i).gender << " "
				 << admins.at(i).phone_number << " "
				 << admins.at(i).username << " "
				 << admins.at(i).password << endl;
		}

		file.close();

		cout << "Admins information saved successfully!" << endl;
	}
	else
	{
		cout << "The file could not be opened!" << endl;
	}
}


// Loads the information of all the Admins from a txt file.
void Admins::load_admins()
{
	ifstream file("admins.txt");
	if (file.is_open())
	{
		admins.clear();

		int id;
		string name;
		int age;
		string gender;
		int phone_number;
		string username;
		string password;

		/*
		This condition means that while the reading action from the file is correct and the variables
		can read valid data, then --> condition is true
		If the reading action stopped or it cannot read valid data, then --> condition is false
		*/
		/*
		* the ws is used to ignore any whitespaces before the name attribute
		* getline is used to take the full name inserted because it will include some spaces
		* if we used cin it will behave in incorrect way
		* getline takes three arguments file which is the source of the data, name is the variable that will store the data comming from the file and third argument is the delimeter which is the ','
		* when the getline face the ',' it will stop storing inside name variable
		*/
		while (file >> id >> ws && getline(file, name, ',') >> age >> gender >> phone_number >> username >> password)
		{
			Admin admin(id, name, age, gender, phone_number, username, password);
			admins.push_back(admin);
		}

		file.close();
		cout << "Admins information loaded successfully!" << endl;
	}
	else
	{
		throw invalid_argument("File is not exist!");
	}
}

int Admins::get_length()
{
	return admins.size();
}

string Admins::get_password(const Admin& my_Admin)
{
	return my_Admin.password;
}

string Admins::get_gender(const Admin & my_Admin)
{
	return my_Admin.gender;
}

int Admins::get_id(const Admin& my_admin)
{
	return my_admin.id;
}

string Admins::get_username(const Admin& my_admin)
{
	return my_admin.username;
}

vector<Admin> Admins::get_dataset()
{
	return admins;
}
