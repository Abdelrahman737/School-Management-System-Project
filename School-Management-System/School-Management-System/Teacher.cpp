#include <iostream>
#include "Teacher.hpp"
#include "Subject.hpp"

using namespace std;

//Default constructor
Teacher::Teacher()
{

}

//overloaded constructor
Teacher::Teacher(int id, string name, int age, string gender, int phone_number, string email, Subject subs[], string date_of_joining, string qualification)
	: Person(id, name, age, gender, phone_number), email(email), date_of_joining(date_of_joining), qualification(qualification)
{
	this->subs[0] = subs[0];
	this->subs[1] = subs[1];
}

//display information of the teacher
void Teacher::display_info() const
{
	cout << "Teacher Information" << endl;
	cout << "===================" << endl;
	cout << "Teacher ID: " << id << endl;
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
	cout << "Gender: " << gender << endl;
	cout << "Phone Number: " << phone_number << endl;
	cout << "Email: " << email << endl;
	cout << "Subject 1: " << subs[0].name << endl;
	cout << "Subject 2: " << subs[1].name << endl;
	cout << "Date of Joining: " << date_of_joining << endl;
	cout << "Qualification: " << qualification << endl;
}


//destructor
Teacher::~Teacher()
{

}