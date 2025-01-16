#ifndef _PERSON_H_
#define _PERSON_H_
#include <iostream>

using namespace std;


//Abstract base class Person for Student, Teacher and Admin
class Person
{
	//protected access specifier to allow derived classes to access these attributes
protected:
	//common attributes for Student, Teacher and Admin
	int id;
	string name;
	int age;
	string gender;
	int phone_number;
public:

	//default constructor
	Person() {};

	//overloaded constructor
	Person(int id, string name, int age, string gender, int phone_number)
		: id(id), name(name), age(age), gender(gender), phone_number(phone_number) {};
	
	//common methods for Student, Teacher and Admin to print their information
	virtual void display_info() const = 0;

	//destructor
	virtual ~Person() {};
};


#endif