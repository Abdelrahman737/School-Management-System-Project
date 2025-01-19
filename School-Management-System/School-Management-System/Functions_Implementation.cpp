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

Stack<Admin> admin_stack;
Stack<Student> student_stack;
Stack<Teacher> teacher_stack;
Admins admins;
Students students;
Teachers teachers;
Subjects subjects;

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

			if (id_str.length() > 10)
			{
				throw invalid_argument("Invalid input, id must be less than 10 digits!");
			}

			for (char c : id_str)
			{
				if (!isdigit(c))
				{
					throw invalid_argument("Invalid input, id should include numbers only!");
				}
			}

			id = stoi(id_str);

			bool id_exists = false;

			vector<Admin> dataset = admins.get_dataset();

			for (Admin s : dataset)
			{
				if (admins.get_id(s) == id)
				{
					id_exists = true;
					break;
				}
			}

			if (id_exists)
			{
				throw invalid_argument("Invalid id, this id already exists!");
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
			getline(cin, name);

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
			getline(cin, password);

			for (char c : password)
			{
				if (c == ' ')
				{
					throw invalid_argument("Invalid input, password cannot contain spaces!");
				}
			}

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
			getline(cin, username);

			for (char c : username)
			{
				if (c == ' ')
				{
					throw invalid_argument("Invalid input, password cannot contain spaces!");
				}
			}

			bool username_exists = false;

			vector<Admin> dataset = admins.get_dataset();

			for (Admin s : dataset)
			{
				if (admins.get_username(s) == username)
				{
					username_exists = true;
					break;
				}
			}

			if (username_exists)
			{
				throw invalid_argument("Invalid username, this username already exists!");
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
			cout << "Gender(Male/Female): ";
			getline(cin, gender);

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
	string name;

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
			getline(cin, name);

			vector<Admin> dataset = admins.get_dataset();

			int temp = admins.binary_search_by_name(dataset, name, 0, admins.get_length() - 1);

			if (temp == -1)
			{
				throw invalid_argument("Invalid username, this name doesn't exist!");
			}

			break;
		}
		catch (invalid_argument r)
		{
			cout << r.what() << endl;
			system("pause");
		}

	} while (true);

	admins.remove_admin(name);
}

void edit_admin_info()
{
	string name, username, gender, password;
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
			cout << "Enter admin's name you want to edit: ";
			getline(cin, name);

			vector<Admin> dataset = admins.get_dataset();

			int temp = admins.binary_search_by_name(dataset, name, 0, admins.get_length() - 1);

			if (temp == -1)
			{
				throw invalid_argument("Invalid username, this name doesn't exist!");
			}

			break;
		}
		catch (invalid_argument r)
		{
			cout << r.what() << endl;
			system("pause");
		}

	} while (true);

	system("cls");

	cout << "Enter new data" << endl;
	cout << "=================" << endl;

	take_admin_info(id, name, password, username, gender, age, phone_number);

	admins.edit_admin_info(id, name, age, gender, phone_number, username, password);
}

void display_all_admins()
{
	system("cls");

	admins.display_all_admins();
}

void display_admin_by_username()
{
	string name;

	system("cls");

	do
	{
		try
		{
			cout << "Enter admin's username you want to display: ";
			getline(cin, name);

			vector<Admin> dataset = admins.get_dataset();

			int temp = admins.binary_search_by_name(dataset, name, 0, admins.get_length() - 1);

			if (temp == -1)
			{
				throw invalid_argument("Invalid username, this name doesn't exist!");
			}

			break;
		}
		catch (invalid_argument r)
		{
			cout << r.what() << endl;
		}

	} while (true);

	admins.display_admin_info(name);
}

void admin_management()
{
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
			admin_stack.push(add_new_admin());
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
			admin_stack.pop();
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
			for (int i = 0; i < admin_stack.size(); i++)
			{
				Admin temp;
				admin_stack.pop(temp);
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

void take_student_info(int& id, string& name, int& age, int& grade, string& gender, int& phone_number)
{
	do
	{
		try
		{
			cout << "Enter ID: ";
			string id_str;
			getline(cin, id_str);

			if (id_str.length() > 10)
			{
				throw invalid_argument("Invalid input, id must be less than 10 digits!");
			}

			for (char c : id_str)
			{
				if (!isdigit(c))
				{
					throw invalid_argument("Invalid input, id should include numbers only!");
				}
			}

			id = stoi(id_str);
			bool id_exists = false;

			vector<Student> dataset = students.get_dataset();

			for (Student s : dataset)
			{
				if (students.get_id(s) == id)
				{
					id_exists = true;
					break;
				}
			}

			if (id_exists)
			{
				throw invalid_argument("Invalid id, this id already exists!");
			}

			if (id <= 0)
			{
				throw invalid_argument("Invalid input, id should be a positive number!");
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
			getline(cin, name);

			for (char c : name)
			{
				if (isdigit(c))
				{
					throw runtime_error("Invalid input, name should be a string only!");
				}
			}
			break;
		}
		catch (runtime_error r)
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
			string str_age;
			getline(cin, str_age);

			for (char c : str_age)
			{
				if (!isdigit(c))
				{
					throw invalid_argument("Invalid input, age should be a number only!");
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
			cout << "Enter your grade: ";
			string str_grade;
			getline(cin, str_grade);

			for (char c : str_grade)
			{
				if (!isdigit(c))
				{
					throw invalid_argument("Invalid input, grade should be a number only!");
				}
			}

			grade = stoi(str_grade);

			if (grade < 1 || grade > 12)
			{
				throw invalid_argument("Invalid input, grade should be between 1 and 12!");
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
			cout << "Gender(Male/Female): ";
			getline(cin, gender);

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

void set_attendance_precentage()
{
	string name;
	float attendance_percentage = 0;

	system("cls");

	do
	{
		try
		{
			cout << "Enter student's name: ";
			getline(cin, name);

			vector<Student> dataset = students.get_dataset();

			int temp = students.binary_search_by_name(dataset, name, 0, students.get_length() - 1);

			if (temp == -1)
			{
				throw invalid_argument("Invalid name, this student doesn't exist!");
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
			cout << "Enter attendance percentage: ";
			string str_att;
			getline(cin, str_att);

			for (char c : str_att)
			{
				if (!isdigit(c))
				{
					throw invalid_argument("Invalid input, attendance must be number only!");
				}
			}

			attendance_percentage = stof(str_att);

			if (attendance_percentage < 0 || attendance_percentage > 100)
			{
				throw invalid_argument("Invalid input, attendance percentage must be between 0 and 100!");
			}

			break;
		}
		catch (invalid_argument r)
		{
			cout << r.what() << endl;
		}

	} while (true);

	students.set_attendance_percentage(name, attendance_percentage);
	cout << "Attendance percentage set successfully!" << endl;
}

void set_marks()
{
	string name;
	vector<float> marks;

	system("cls");

	vector<Student> dataset = students.get_dataset();

	vector<Subject> subs;
	
	do
	{
		try
		{
			cout << "Enter student's name: ";
			getline(cin, name);

			int temp = students.binary_search_by_name(dataset, name, 0, students.get_length() - 1);

			if (temp == -1)
			{
				throw invalid_argument("Invalid name, this student doesn't exist!");
			}

			subs = students.get_subjects(dataset.at(temp));

			break;
		}
		catch (invalid_argument r)
		{
			cout << r.what() << endl;
		}

	} while (true);


	cout << "Student subjects:" << endl;

	int count = 1;

	for (Subject sub : subs)
	{
		cout << count << ")" << sub.get_name() << endl;
		count++;
	}

	for (int i = 0; i < subs.size(); ++i)
	{
		float mark;
		do
		{
			try
			{
				cout << "Enter mark for subject " << i + 1 << ": ";
				string str_mark;
				getline(cin, str_mark);

				for (char c : str_mark)
				{
					if (!isdigit(c))
					{
						throw invalid_argument("Invalid input, marks must be a number!");
					}
				}

				mark = stof(str_mark);

				if (mark < 0 || mark > 100)
				{
					throw invalid_argument("Invalid input, mark must be between 0 and 100!");
				}

				marks.push_back(mark);
				break;
			}
			catch (invalid_argument r)
			{
				cout << r.what() << endl;
			}
		} while (true);
	}

	students.set_marks(name, marks);
	cout << "Marks set successfully!" << endl;
}


void delete_student()
{
	string name;

	system("cls");

	do
	{
		char ans = ' ';

		try
		{
			cout << "Do you want to proceed(Y/N): ";
			getline(cin, name);

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
			cout << "Enter student's name you want to delete: ";
			cin >> name;

			vector<Student> dataset = students.get_dataset();

			int temp = students.binary_search_by_name(dataset, name, 0, students.get_length() - 1);

			if (temp == -1)
			{
				throw invalid_argument("Invalid name, this student doesn't exist!");
			}

			break;
		}
		catch (invalid_argument r)
		{
			cout << r.what() << endl;
			system("pause");
		}

	} while (true);

	students.remove_student(name);
}

void display_all_students()
{
	system("cls");

	students.display_all_students();
}

void display_student_by_name()
{
	string name;

	system("cls");

	do
	{
		try
		{
			cout << "Enter student's name you want to display: ";
			getline(cin, name);

			vector<Student> dataset = students.get_dataset();

			int temp = students.binary_search_by_name(dataset, name, 0, students.get_length() - 1);

			if (temp == -1)
			{
				throw invalid_argument("Invalid name, this student doesn't exist!");
			}

			break;
		}
		catch (invalid_argument r)
		{
			cout << r.what() << endl;
		}

	} while (true);

	students.display_student_info(name);
}

void edit_student_info()
{
	string name, search_input, gender;
	int id = 0, age = 0, grade = 0, phone_number = 0;

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
		}
	} while (true);

	do
	{
		try
		{
			cout << "Enter student's name you want to edit: ";
			getline(cin, search_input);

			vector<Student> dataset = students.get_dataset();

			int temp = students.binary_search_by_name(dataset, search_input, 0, students.get_length() - 1);

			if (temp == -1)
			{
				throw invalid_argument("Invalid name, this student doesn't exist!");
			}

			break;
		}
		catch (invalid_argument r)
		{
			cout << r.what() << endl;
			system("pause");
		}

	} while (true);

	system("cls");

	cout << "Enter new data" << endl;
	cout << "=================" << endl;

	take_student_info(id, name, age, grade, gender, phone_number);

	students.edit_student_info(search_input, name, id, age, grade, gender, phone_number);
}

Student add_new_student()
{
	string name, gender;
	int id = 0, age = 0, grade = 0, phone_number = 0;

	system("cls");

	take_student_info(id, name, age, grade, gender, phone_number);

	Student new_student{ id, name, age, gender, phone_number, grade };

	return new_student;
}

void student_management()
{
	do
	{
		int choice = 0;

		system("cls");
		cout << "Student functions" << endl;
		cout << "=================" << endl;
		cout << "1) Add new student" << endl;
		cout << "2) Delete student" << endl;
		cout << "3) Edit student information" << endl;
		cout << "4) Display student by name" << endl;
		cout << "5) Display all students" << endl;
		cout << "6) Set attendance percentage for a student" << endl;
		cout << "7) Set marks for a student" << endl;
		cout << "8) Remove last added student" << endl;
		cout << "9) Save students" << endl;
		cout << "10) Back" << endl;

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

			if (choice < 1 || choice > 10)
			{
				throw invalid_argument("Invalid input, choice must be between 1 and 10");
			}
		}
		catch (invalid_argument r)
		{
			cout << r.what() << endl;
			system("pause");
		}

		switch (choice)
		{
		case 1:
			student_stack.push(add_new_student());
			break;
		case 2:
		{
			delete_student();
			students.save_students();
			break;
		}
		case 3:
		{
			edit_student_info();
			students.save_students();
			break;
		}
		case 4:
		{
			display_student_by_name();
			system("pause");
			break;
		}
		case 5:
			display_all_students();
			system("pause");
			break;
		case 6:
			set_attendance_precentage();
			system("pause");
			students.save_students();
			break;
		case 7:
			set_marks();
			system("pause");
			students.save_students();
			break;
		case 8:
			student_stack.pop();
		case 9:
			for (int i = 0; i < student_stack.size(); i++)
			{
				Student temp;
				student_stack.pop(temp);
				students.add_student(temp);
			}

			students.save_students();
			break;
		case 10:
			return;
		}

	} while (true);
}

//============================================Teachers functions============================================

void take_teacher_info(int& id, string& name, int& age, string& gender, int& phone_number, string& email, Subject subs[2], string& date_of_joining, string& qualification)
{
	do
	{
		try
		{
			cout << "Enter ID: ";
			string id_str;
			getline(cin, id_str);

			if (id_str.length() > 10)
			{
				throw invalid_argument("Invalid input, id must be less than 10 digits!");
			}

			for (char c : id_str)
			{
				if (!isdigit(c))
				{
					throw invalid_argument("Invalid input, id should include numbers only!");
				}
			}

			id = stoi(id_str);
			bool id_exists = false;

			vector<Teacher> dataset = teachers.get_dataset();

			for (Teacher t : dataset)
			{
				if (teachers.get_id(t) == id)
				{
					id_exists = true;
					break;
				}
			}

			if (id_exists)
			{
				throw invalid_argument("Invalid id, this id already exists!");
			}

			if (id <= 0)
			{
				throw invalid_argument("Invalid input, id should be a positive number!");
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
			cout << "Enter teacher's name: ";
			getline(cin, name);

			for (char c : name)
			{
				if (isdigit(c))
				{
					throw runtime_error("Invalid input, name should be a string only!");
				}
			}
			break;
		}
		catch (runtime_error r)
		{
			//r.what() means that it will display the content of the error message
			cout << r.what() << endl;
		}

	} while (true);

	do
	{
		try
		{
			cout << "Enter teacher's age: ";
			string str_age;
			getline(cin, str_age);

			for (char c : str_age)
			{
				if (!isdigit(c))
				{
					throw invalid_argument("Invalid input, age should be a number only!");
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
			cout << "Gender(Male/Female): ";
			getline(cin, gender);

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
			cout << "Enter teacher's phone number(+60): ";
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

	do
	{
		try
		{
			cout << "Enter teacher's email: ";
			getline(cin, email);

			for (char c : email)
			{
				if (c == ' ')
				{
					throw invalid_argument("Invalid input, email cannot contain any spaces!");
				}
			}

			char found1 = false;
			char found2 = false;

			for (char c : email)
			{
				if (c == '@')
				{
					found1 = true;
				}
				if (c == '.')
				{
					found2 = true;
				}
			}

			if (!found1 && !found2)
			{
				throw invalid_argument("Invalid input, email must contail '@' and '.' !");
			}

			break;
		}
		catch (invalid_argument r)
		{
			// r.what() means that it will display the content of the error message
			cout << r.what() << endl;
		}
	} while (true);

	for (int i = 0; i < 2; i++)
	{
		string subject_name;
		Subject subject;

		system("cls");

		//Displaying all subjects
		vector<Subject> all_subjects = subjects.get_all_subjects();
		cout << "Available subjects:" << endl;
		for (int j = 0; j < all_subjects.size(); ++j)
		{
			cout << j + 1 << ") " << all_subjects[j].get_name() << endl;
		}

		do
		{
			try
			{
				cout << "Enter subject " << i + 1 << " name: ";
				getline(cin, subject_name);

				bool found = false;

				for (Subject s : all_subjects)
				{
					if (s.get_name() == subject_name)
					{
						subject = s;
						found = true;
						break;
					}
				}

				if (!found)
				{
					throw invalid_argument("Invalid input, subject not found!");
				}

				break;
			}
			catch (invalid_argument r)
			{
				// r.what() means that it will display the content of the error message
				cout << r.what() << endl;
			}
		} while (true);

		subs[i] = subject;
	}

	do
	{
		try
		{
			cout << "Enter date of joining (YYYY-MM-DD): ";
			getline(cin, date_of_joining);

			if (date_of_joining.length() != 10 || date_of_joining[4] != '-' || date_of_joining[7] != '-')
			{
				throw invalid_argument("Invalid input, date of joining must be in the format YYYY-MM-DD!");
			}

			break;
		}
		catch (invalid_argument r)
		{
			// r.what() means that it will display the content of the error message
			cout << r.what() << endl;
		}
	} while (true);

	do
	{
		try
		{
			cout << "Enter your qualification: ";
			getline(cin, qualification);

			for (char c : qualification)
			{
				if (isdigit(c))
				{
					throw invalid_argument("Invalid input, qualificaion must be a string only!");
				}
				if (c == ' ')
				{
					throw invalid_argument("Invalid input, qualification cannot contain any spaces!");
				}
			}

			break;
		}
		catch (invalid_argument r)
		{
			// r.what() means that it will display the content of the error message
			cout << r.what() << endl;
		}
	} while (true);
}

Teacher add_new_teacher()
{
	string name, gender, email, date_of_joining, qualification;
	int id = 0, age = 0, phone_number = 0;
	Subject subs[2];

	system("cls");

	take_teacher_info(id, name, age, gender, phone_number, email, subs, date_of_joining, qualification);

	Teacher new_teacher{ id, name, age, gender, phone_number, email, subs, date_of_joining, qualification };

	return new_teacher;
}

void delete_teacher()
{
	string name;

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
			cout << r.what() << endl;
			system("pause");
		}

	} while (true);

	do
	{
		try
		{
			cout << "Enter teacher's name you want to delete: ";
			getline(cin, name);

			vector<Teacher> dataset = teachers.get_dataset();

			int temp = teachers.binary_search(dataset, name, 0, teachers.get_length() - 1);

			if (temp == -1)
			{
				throw invalid_argument("Invalid name, this teacher doesn't exist!");
			}

			break;
		}
		catch (invalid_argument r)
		{
			cout << r.what() << endl;
			system("pause");
		}

	} while (true);

	teachers.remove_teacher(name);
}

void display_all_teachers()
{
	system("cls");

	teachers.display_all_teachers();
}

void display_teacher_by_name()
{
	string name;

	system("cls");

	do
	{
		try
		{
			cout << "Enter teacher's name you want to display: ";
			getline(cin, name);

			vector<Teacher> dataset = teachers.get_dataset();

			int temp = teachers.binary_search(dataset, name, 0, teachers.get_length() - 1);

			if (temp == -1)
			{
				throw invalid_argument("Invalid name, this teacher doesn't exist!");
			}

			teachers.dispaly_teacher_info(name);
			break;
		}
		catch (invalid_argument r)
		{
			cout << r.what() << endl;
			system("pause");
		}

	} while (true);
}

void edit_teacher_info()
{
	string name, gender, email, date_of_joining, qualification;
	int id = 0, age = 0, phone_number = 0;
	Subject subs[2];

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
			cout << "Enter teacher's name you want to edit: ";
			cin.ignore();
			getline(cin, name);

			vector<Teacher> dataset = teachers.get_dataset();

			int temp = teachers.binary_search(dataset, name, 0, teachers.get_length() - 1);

			if (temp == -1)
			{
				throw invalid_argument("Invalid name, this teacher doesn't exist!");
			}

			break;
		}
		catch (invalid_argument r)
		{
			cout << r.what() << endl;
			system("pause");
		}

	} while (true);

	system("cls");

	cout << "Enter new data" << endl;
	cout << "=================" << endl;

	take_teacher_info(id, name, age, gender, phone_number, email, subs, date_of_joining, qualification);

	teachers.edit_teacher_info(id, name, age, gender, phone_number, email, subs, date_of_joining, qualification);
}


void teacher_management()
{
	do
	{
		int choice = 0;

		system("cls");
		cout << "Teacher functions" << endl;
		cout << "=================" << endl;
		cout << "1) Add new teacher" << endl;
		cout << "2) Delete teacher" << endl;
		cout << "3) Edit teacher information" << endl;
		cout << "4) Display teacher by name" << endl;
		cout << "5) Display all teachers" << endl;
		cout << "6) Remove last added teacher" << endl;
		cout << "7) Save teachers" << endl;
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

			if (choice < 1 || choice > 8)
			{
				throw invalid_argument("Invalid input, choice must be between 1 and 8");
			}
		}
		catch (invalid_argument r)
		{
			cout << r.what() << endl;
			system("pause");
		}

		switch (choice)
		{
		case 1:
			teacher_stack.push(add_new_teacher());
			break;
		case 2:
		{
			delete_teacher();
			teachers.save_teachers();
			break;
		}
		case 3:
		{
			edit_teacher_info();
			teachers.save_teachers();
			break;
		}
		case 4:
		{
			display_teacher_by_name();
			system("pause");
			break;
		}
		case 5:
			display_all_teachers();
			system("pause");
			break;
		case 6:
			teacher_stack.pop();
			break;
		case 7:
			for (int i = 0; i < teacher_stack.size(); i++)
			{
				Teacher temp;
				teacher_stack.pop(temp);
				teachers.add_teacher(temp);
			}

			teachers.save_teachers();
			break;
		case 8:
			return;
		}

	} while (true);
}


//==================================================Menu======================================================

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
		cout << "Signup:" << endl;
		system("pause");
		admins.add_admin(add_new_admin());
		admins.save_admins();
	}

	system("cls");

	cout << "Login:" << endl;

	Admin temp;

	do
	{
		try
		{
			cout << "Enter the username: ";
			getline(cin, username);

			bool found = false;

			vector<Admin> dataset = admins.get_dataset();
			
			for (Admin a : dataset)
			{
				if (admins.get_username(a) == username)
				{
					found = true;
					temp = a;
					break;
				}
			}

			if (!found)
			{
				throw invalid_argument("Invalid username, username not found!");
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
			getline(cin, password);

			//Checking each character
			if (password.length() < 8)
			{
				throw invalid_argument("Invalid input, password should contain more than 8 characters!");
			}

			vector<Admin> dataset = admins.get_dataset();

			if (admins.get_password(temp) != password)
			{
				throw invalid_argument("Invalid input, wrong password!");
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

		if (admins.get_gender(temp) == "male")
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
			cout << r.what() << endl;
			system("pause");
		}

		switch (choice)
		{
		case 1:
			admin_management();
			break;
		case 2:
			students.load_students();
			student_management();
			break;
		case 3:
			teachers.load_teachers();
			teacher_management();
			break;
		case 4:
			endl(cout);

			cout << "Exiting system........" << endl;
			cout << "Bye :)" << endl;
			exit(0); //exit will terminate the prgram
		default:
			cout << "Invalid input!";
		}
	} while (true);
}
