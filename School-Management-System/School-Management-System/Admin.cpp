#include <iostream>
#include "Admin.hpp"

using namespace std;

//Default constructor
Admin::Admin()
{

}

//overloaded constructor
Admin::Admin(int id, string name, int age, string gender, int phone_number, string username, string password)
	: Person(id, name, age, gender, phone_number), username(username), password(password)
{

};

//common method for Student, Teacher and Admin to print their information
void Admin::display_info() const
{
	cout << "Admin information" << endl;
	cout << "===================" << endl;
	cout << "ID: " << id << endl;
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
	cout << "Gender: " << gender << endl;
	cout << "Phone number: " << phone_number << endl;
}

//destructor
Admin::~Admin()
{

}