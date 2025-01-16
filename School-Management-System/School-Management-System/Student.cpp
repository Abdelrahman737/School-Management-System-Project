#include <iostream>
#include <vector>
#include "Student.hpp"
#include "Subjects.hpp"
#include "Subject.hpp"

using namespace std;

//default constructor
Student::Student() : Person()
{

}

//overloaded constructor
Student::Student(int id, string name, int age, string gender, int phone_number, int grade)
	: Person(id, name, age, gender, phone_number), grade(grade)
{
	Subjects subs;

	//High school subjects
	if(grade > 8)
	{
		subjects.push_back(subs.subjects.at(0)); //Math
		subjects.push_back(subs.subjects.at(2)); //English
		subjects.push_back(subs.subjects.at(3)); //History
		subjects.push_back(subs.subjects.at(4)); //Computer Science
		subjects.push_back(subs.subjects.at(6)); //Home Economics
		subjects.push_back(subs.subjects.at(7)); //Foreign Language (German)
		subjects.push_back(subs.subjects.at(8)); //Physical Education
		subjects.push_back(subs.subjects.at(10)); //Physics
		subjects.push_back(subs.subjects.at(11)); //Chemistry
		subjects.push_back(subs.subjects.at(12)); //Biology
		subjects.push_back(subs.subjects.at(13)); //Geography
	}
	//Middle and primary school subjects
	else
	{
		subjects.push_back(subs.subjects.at(0)); //Math
		subjects.push_back(subs.subjects.at(1)); //Science
		subjects.push_back(subs.subjects.at(2)); //English
		subjects.push_back(subs.subjects.at(3)); //History
		subjects.push_back(subs.subjects.at(5)); //Computer
		subjects.push_back(subs.subjects.at(6)); //Home Economics
		subjects.push_back(subs.subjects.at(7)); //Foreign Language (German)
		subjects.push_back(subs.subjects.at(8)); //Physical Education
	}

}

//function to display the information of the student
void Student::display_info() const
{
	cout << "Student information: " << endl;
	cout << "======================" << endl;
	cout << "Student ID: " << id << endl;
	cout << "Student Name: " << name << endl;
	cout << "Student Age: " << age << endl;
	cout << "Student gender: " << gender << endl;
	cout << "Student Phone Number: " << phone_number << endl;
	cout << "Student Grade: " << grade << endl;
	cout << "Student Attendance Percentage: " << attendance_percentage << endl;

	for (int i{ 0 }; i < marks_per_subject.size(); i++)
	{
		cout << "Subject " << i + 1 << " Marks: " << marks_per_subject.at(i) << "%" << endl;
	}
}

//destructor
Student::~Student()
{

}