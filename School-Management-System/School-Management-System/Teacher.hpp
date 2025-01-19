#ifndef _TEACHER_HPP_
#define _TEACHER_HPP_
#include <iostream>
#include "Person.hpp"
#include "Subject.hpp"

class Teachers;

using namespace std;

class Teacher : public Person
{
	//allow Subject class to access the attributes of Teacher class
	friend class Teachers;
	friend class Subject;
private:
	string email;
	Subject subs[2];
	string date_of_joining;
	string qualification;
public:
	//Default constructor
	Teacher();
	//overloaded constructor
	Teacher(int id, string name, int age, string gender, int phone_number, string email, Subject subs[], string date_of_joining, string qualification);

	//display information of the teacher
	virtual void display_info() const override;

	//destructor
	virtual ~Teacher();

};

#endif