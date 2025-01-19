#include <iostream>
#include "Subjects.hpp"

using namespace std;

//constructor
Subjects::Subjects()
{
	//Primary subjects
	Subject s1("Math", 3);
	Subject s2("Science", 3);
	Subject s3("English", 3);
	Subject s4("History", 3);
	Subject s5("Computer Science", 3);
	Subject s6("Computer", 3);
	Subject s7("Home Economics", 3);
	Subject s8("Foreign Language (German)", 3);
	Subject s9("Physical Education", 3);
	Subject s10("Art", 3);

	//Secondary subjects
	Subject s11("Physics", 3);
	Subject s12("Chemistry", 3);
	Subject s13("Biology", 3);
	Subject s14("Geography", 3);

	//add subjects to the vector
	subjects.push_back(s1);
	subjects.push_back(s2);
	subjects.push_back(s3);
	subjects.push_back(s4);
	subjects.push_back(s5);
	subjects.push_back(s6);
	subjects.push_back(s7);
	subjects.push_back(s8);
	subjects.push_back(s9);
	subjects.push_back(s10);
	subjects.push_back(s11);
	subjects.push_back(s12);
	subjects.push_back(s13);
	subjects.push_back(s14);
}

//destructor
Subjects::~Subjects()
{

}

//Function
vector<Subject> Subjects::get_all_subjects()
{
	return subjects;
}