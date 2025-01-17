#include <iostream>
#include <vector>
#include "Subject.hpp"
#include "Teacher.hpp"
#include "Student.hpp"

using namespace std;

//default constructor
Subject::Subject() 
{

}

//overloaded constructor
Subject::Subject(string name, float credit_hours)
	: name(name), credit_hours(credit_hours)
{

}

string Subject::get_name()
{
	return name;
}

//destructor
Subject::~Subject()
{

}