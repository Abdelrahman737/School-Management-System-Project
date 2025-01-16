#ifndef _ADMIN_H_
#define _ADMIN_H_
#include <iostream>
#include "Person.hpp"

using namespace std;

class Admin : public Person
{
	//class Admins is a friend class of Admin
	//so that Admins can access the private attributes of Admin
	//This class will be used to store all the Admins and control them
	friend class Admins;
private:
	//attributes for Admin
	string username;
	string password;
public:
	Admin();
	//overloaded constructor
	Admin(int id, string name, int age, string gender, int phone_number, string username, string password);

	//common method for Student, Teacher and Admin to print their information
	virtual void display_info() const override;

	//destructor
	virtual ~Admin();
};

#endif