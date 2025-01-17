#include <iostream>
#include <vector>
#include <cstdlib> //Used for system --> to clear the terminal screen using 'cls'
#include <string>
#include "Functions_Implementation.hpp"
#include "Admins.hpp"
#include "Students.hpp"
#include "Teachers.hpp"
#include "Subjects.hpp"
#include "My_Stack.hpp"


using namespace std;

Admins admins;

//============================================Admin functions============================================
void take_admin_info(int& id, string& name, string& password, string& username, string& gender, int& age, int& phone_number)
{
	do
	{
		try
		{
			cout << "Enter ID: ";
			string id_str;
			getline(cin, id_str);

			for (char c : id_str)
			{
				if (!isdigit(c))
				{
					throw invalid_argument("Invalid input, id should include numbers only!");
				}
			}

			id = stoi(id_str);

			vector<Admin> dataset = admins.get_dataset();


			int temp = admins.binary_search_by_id(dataset, id, 0, admins.get_length());

			if (temp != -1)
			{
				throw invalid_argument("Invalid id, this id is already exists!");
			}

			if (id <= 0)
			{
				throw invalid_argument("Invalid input, age should be a positive number!");
			}

			break; // Exit the loop if input is valid
		}
		catch (invalid_argument r) // Catches exception
		{
			// r.what() means that it will display the content of the error message
			cout << r.what() << endl;
		}

	} while (true);

	do
	{
		try
		{
			cout << "Enter your name: ";
			cin >> name;

			//Iterating through all characters of the name to check if it contains any numbers
			for (char c : name)
			{
				//Checking each character
				if (isdigit(c))
				{
					//Throws an exception that happened during runtime telling what is the problem
					throw runtime_error("Invalid input, name should be a string only!");
				}
			}
			break; //Exit the loop if input is valid
		}
		catch (runtime_error r) //Catches exception from type runtime_error called r
		{
			//r.what() means that it will display the content of the error message
			cout << r.what() << endl;
		}

	} while (true);

	do
	{
		try
		{
			cout << "Enter your password: ";
			cin >> password;

			//Checking each character
			if (password.length() < 8)
			{
				throw invalid_argument("Invalid input, password should contain more than 8 characters!");
			}
			break; //Exit the loop if input is valid
		}
		catch (invalid_argument r) //Catches exception
		{
			//r.what() means that it will display the content of the error message
			cout << r.what() << endl;
		}

	} while (true);

	do
	{
		try
		{
			cout << "Enter your username: ";
			cin >> username;

			vector<Admin> dataset = admins.get_dataset();

			int temp = admins.binary_search_by_username(dataset, username, 0, admins.get_length());

			if (temp != -1)
			{
				throw invalid_argument("Invalid username, this username is already exists!");
			}

			break;
		}
		catch (invalid_argument r)
		{
			cout << r.what();
		}

	} while (true);

	do
	{
		try
		{
			cout << "Gender(Male/Female): ";
			cin >> gender;

			string temp;

			for (char c : gender)
			{
				if (isdigit(c))
				{
					throw invalid_argument("Invalid input, gender cannot contain any numbers!");
				}
				else
				{
					temp += tolower(c);
				}
			}

			if (temp != "male" && temp != "female")
			{
				throw invalid_argument("Invalid input, must be (male/female)");
			}

			gender = temp;

			break; //Exit the loop if input is valid
		}
		catch (invalid_argument r) //Catches exception
		{
			//r.what() means that it will display the content of the error message
			cout << r.what() << endl;
		}

	} while (true);

	do
	{
		try
		{
			cout << "Enter your age: ";
			cin.ignore();
			string str_age;
			getline(cin, str_age);

			for (char c : str_age)
			{
				if (!isdigit(c))
				{
					throw invalid_argument("Invalid input, age should be a a number only!");
				}
			}

			age = stoi(str_age);

			if (age <= 0)
			{
				throw invalid_argument("Invalid input, age should be a positive number!");
			}


			break; // Exit the loop if input is valid
		}
		catch (invalid_argument r) // Catches exception
		{
			// r.what() means that it will display the content of the error message
			cout << r.what() << endl;
		}

	} while (true);

	do
	{
		try
		{
			cout << "Enter your phone number(+60): ";
			string str_phone_number;
			getline(cin, str_phone_number);

			for (char c : str_phone_number)
			{
				if (isalpha(c))
				{
					throw invalid_argument("Invalid input, phone number should contain digits only!");
				}
			}

			phone_number = stoi(str_phone_number);

			if (str_phone_number.length() != 9)
			{
				throw invalid_argument("Invalid input, phone number should contain 9 digits!");
			}

			break; // Exit the loop if input is valid
		}
		catch (invalid_argument r) // Catches exception
		{
			// r.what() means that it will display the content of the error message
			cout << r.what() << endl;
		}
	} while (true);
}


Admin add_new_admin()
{
	string name, username, gender, password;
	int id = 0, age = 0, phone_number = 0;

	system("cls");

	take_admin_info(id, name, password, username, gender, age, phone_number);

	Admin new_admin{ id, name, age, gender, phone_number, username, password };

	return new_admin;
}

void delete_admin()
{
	string username;

	system("cls");

	do
	{
		char ans;

		try
		{
			cout << "Do you want to proceed(Y/N): ";
			cin >> ans;

			if (tolower(ans) != 'y' && tolower(ans) != 'n')
			{
				throw invalid_argument("Invalid input");
			}

			if (tolower(ans) == 'n')
			{
				return;
			}
			else
			{
				break;
			}
		}
		catch (invalid_argument r)
		{
			cout << r.what();
			system("pause");
		}

	} while (true);

	do
	{
		try
		{
			cout << "Enter admin's username you want to delete: ";
			cin >> username;

			vector<Admin> dataset = admins.get_dataset();

			int temp = admins.binary_search_by_username(dataset, username, 0, admins.get_length());

			if (temp == -1)
			{
				throw invalid_argument("Invalid username, this username doesn't exist!");
			}

			break;
		}
		catch (invalid_argument r)
		{
			cout << r.what();
		}

	} while (true);

	admins.remove_admin(username);
}

void edit_admin_info()
{
	string name, username, new_username, gender, password;
	int id = 0, age = 0, phone_number = 0;

	system("cls");

	do
	{
		char ans;

		try
		{
			cout << "Do you want to proceed(Y/N): ";
			cin >> ans;

			if (tolower(ans) != 'y' && tolower(ans) != 'n')
			{
				throw invalid_argument("Invalid input");
			}

			if (tolower(ans) == 'n')
			{
				return;
			}
			else
			{
				break;
			}
		}
		catch (invalid_argument r)
		{
			cout << r.what();
			system("pause");
		}
	} while (true);

	do
	{
		try
		{
			cout << "Enter admin's username you want to edit: ";
			cin >> username;

			vector<Admin> dataset = admins.get_dataset();

			int temp = admins.binary_search_by_username(dataset, username, 0, admins.get_length());

			if (temp == -1)
			{
				throw invalid_argument("Invalid username, this username doesn't exist!");
			}

			break;
		}
		catch (invalid_argument r)
		{
			cout << r.what();
		}

	} while (true);

	system("cls");

	cout << "Enter new data" << endl;
	cout << "=================" << endl;

	take_admin_info(id, name, password, new_username, gender, age, phone_number);

	admins.edit_admin_info(username, id, name, age, gender, phone_number, new_username, password);
}

void display_all_admins()
{
	system("cls");

	admins.display_all_admins();
}

void display_admin_by_username()
{
	string username;

	system("cls");

	do
	{
		try
		{
			cout << "Enter admin's username you want to delete: ";
			cin >> username;

			vector<Admin> dataset = admins.get_dataset();

			int temp = admins.binary_search_by_username(dataset, username, 0, admins.get_length());

			if (temp == -1)
			{
				throw invalid_argument("Invalid username, this username doesn't exist!");
			}

			break;
		}
		catch (invalid_argument r)
		{
			cout << r.what() << endl;
		}

	} while (true);

	admins.display_admin_info(username);
}

void admin_management()
{
	Stack<Admin> stack;

	do
	{
		int choice = 0;

		system("cls");
		cout << "Admin functions" << endl;
		cout << "===============" << endl;
		cout << "1) Add new admin" << endl;
		cout << "2) Delete admin" << endl;
		cout << "3) Edit admin information" << endl;
		cout << "4) Remove last added admin" << endl;
		cout << "5) Display admin by username" << endl;
		cout << "6) Display all admins" << endl;
		cout << "7) Save new admins" << endl;
		cout << "8) Back" << endl;

		try
		{
			cout << "Choose the desired option: ";
			string str_choice;
			getline(cin, str_choice);

			for (char c : str_choice)
			{
				if (!isdigit(c))
				{
					throw invalid_argument("Invalid input, choice must be a number only");
				}
			}

			choice = stoi(str_choice);

			if (choice > 6 || choice < 1)
			{
				throw invalid_argument("Invalid input, choice must be between 1 and 6");
			}
		}
		catch (invalid_argument r)
		{
			cout << r.what();
		}

		switch (choice)
		{
		case 1:
			stack.push(add_new_admin());
			break;
		case 2:
			delete_admin();
			admins.save_admins();
			break;
		case 3:
			edit_admin_info();
			admins.save_admins();
			break;
		case 4:
			stack.pop();
			break;
		case 5:
			display_admin_by_username();
			system("pause");
			break;
		case 6:
			display_all_admins();
			system("pause");
			break;
		case 7:
			for (int i = 0; i < stack.size(); i++)
			{
				Admin temp;
				stack.pop(temp);
				admins.add_admin(temp);
			}

			admins.save_admins();
			break;
		}

		if (choice == 8)
		{
			break;
		}

	} while (true);
}

//============================================Student functions============================================

void student_management()
{

}

//============================================Teachers functions============================================

void teacher_management()
{

}

void menu()
{
	cout << "School Management System\n\n";

	string username, password;

	try
	{
		admins.load_admins();
	}
	catch (invalid_argument r)
	{
		admins.add_admin(add_new_admin());
		admins.save_admins();
	}

	system("cls");

	cout << "Login:" << endl;

	do
	{
		try
		{
			cout << "Enter the username: ";
			cin >> username;

			vector<Admin> dataset = admins.get_dataset();
			int temp = admins.binary_search_by_username(dataset, username, 0, admins.get_length());

			if (temp == -1)
			{
				throw invalid_argument("Invalid username");
			}

			break;
		}
		catch (invalid_argument r)
		{
			cout << r.what() << endl;
		}


	} while (true);

	do
	{
		try
		{
			cout << "Enter your password: ";
			cin >> password;

			//Checking each character
			if (password.length() < 8)
			{
				throw invalid_argument("Invalid input, password should contain more than 8 characters!");
			}

			vector<Admin> dataset = admins.get_dataset();
			int temp = admins.binary_search_by_username(dataset, username, 0, admins.get_length());

			if (temp == -1)
			{
				throw invalid_argument("Invalid password");
			}

			if (admins.get_password(dataset.at(temp)) != password)
			{
				throw invalid_argument("Invalid password");
			}

			break; //Exit the loop if input is valid
		}
		catch (invalid_argument r) //Catches exception
		{
			//r.what() means that it will display the content of the error message
			cout << r.what() << endl;
		}

	} while (true);

	do
	{
		system("cls"); //Cleaning the terminal screen

		vector<Admin> dataset = admins.get_dataset();

		int temp = admins.binary_search_by_username(dataset, username, 0, admins.get_length());

		if (admins.get_gender(dataset.at(temp)) == "male")
		{
			cout << "Welcome Mr. " << username << endl;
		}
		else
		{
			cout << "Welcome Ms. " << username << endl;
		}
		endl(cout);

		int choice = 0;

		cout << "System functions" << endl;
		cout << "================" << endl;
		cout << "1) Admin management" << endl;
		cout << "2) Student management" << endl;
		cout << "3) Teacher management" << endl;
		cout << "4) Exit" << endl;
		endl(cout);
		cout << "Choose the desired options: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			admin_management();
			break;
		case 2:
			student_management();
			break;
		case 3:
			teacher_management();
			break;
		case 4:
			endl(cout);

			cout << "Exiting system........" << endl;
			cout << "Bye :)";
			exit(0); //exit will terminate the prgram
		default:
			cout << "Invalid input!";
		}
	} while (true);
}
