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

Admin add_new_admin()
{
	string name, password, username, gender;
	int id = 0, age = 0, phone_number = 0;

	do
	{
		try
		{
			cout << "Enter ID: ";
			cin >> id;

			string temp = to_string(id);

			//Check if the input failed (if the user entered a string)
			if (cin.fail())
			{
				//Used to prevent runtime errors that could happen (espically infinit loops)

				cin.clear(); //Clears the error state
				cin.ignore(); //Discard invalid input
			}

			for (char c : temp)
			{
				if (isalpha(c))
				{
					throw invalid_argument("Invalid input, age should be a a number!");
				}
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
			cin >> age;

			string temp = to_string(age);

			//Check if the input failed (if the user entered a string)
			if (cin.fail())
			{
				//Used to prevent runtime errors that could happen (espically infinit loops)

				cin.clear(); //Clears the error state
				cin.ignore(); //Discard invalid input
			}

			for (char c : temp)
			{
				if (isalpha(c))
				{
					throw invalid_argument("Invalid input, age should be a a number!");
				}
			}
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
			cin >> phone_number;

			string temp = to_string(phone_number);

			if (cin.fail())
			{
				//Used to prevent runtime errors that could happen (espically infinit loops)

				cin.clear(); //Clears the error state
				cin.ignore(); //Discard invalid input
			}

			for (char c : temp)
			{
				if (isalpha(c))
				{
					throw invalid_argument("Invalid input, phone number should contain digits only!");
				}
			}
			if (temp.length() != 9)
			{
				throw invalid_argument("Invalid input, phone number should contain 10 digits!");
			}

			break; // Exit the loop if input is valid
		}
		catch (invalid_argument r) // Catches exception
		{
			// r.what() means that it will display the content of the error message
			cout << r.what() << endl;
		}
	} while (true);

	Admin new_admin{ id, name, age, gender, phone_number, username, password };

	return new_admin;
}

void delete_admin()
{

}

void edit_admin_info()
{

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
		cout << "5) Save new admins" << endl;
		cout << "6) Back" << endl;

		try
		{
			cout << "Choose the desired option: ";
			cin >> choice;

			if (cin.fail())
			{
				cin.clear();
				cin.ignore();

				throw invalid_argument("Invalid input, choice must be a number");
			}

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
				for (int i = 0; i < stack.size(); i++)
				{
					Admin temp;
					stack.pop(temp);
					admins.add_admin(temp);
				}

				admins.save_admins();
				break;
		}

		if (choice == 6)
		{
			break;
		}

	} while (true);
}

void student_management()
{

}

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
	catch(invalid_argument r)
	{
		admins.add_admin(add_new_admin());
	}

	do 
	{
		
		cout << "Enter the username: ";
		cin >> username;

		do
		{
			cout << "Enter the password: ";
			cin >> password;

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

		vector<Admin> dataset = admins.get_dataset();
		int temp = admins.binary_search_by_username(dataset, username, 0, admins.get_length());

		if (temp == -1)
		{
			cout << "Invalid username";
		}
		else
		{
			if (admins.get_password(dataset.at(temp)) == password)
			{
				break;
			}
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
		}
	} while (true);
}
