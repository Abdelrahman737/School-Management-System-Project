#ifndef _STUDENT_HPP_
#define _STUDENT_HPP_

#include <iostream>
#include <vector>
#include "Person.hpp"


// Forward declaration
class Students;
class Subject;

using namespace std;

class Student : public Person
{
	friend class Students;
	// Attributes of the Student class
private:
    int grade;
    vector<Subject> subjects;
    float attendance_percentage = 0;
    vector<int> marks_per_subject;
public:
	// Default constructor
	Student();

    // Overloaded constructor
    Student(int id, string name, int age, string gender, int phone_number, int grade);

    // Function to display the information of the student
    virtual void display_info() const override;

    // Destructor
    ~Student();
};

#endif
