#ifndef _SUBJECT_HPP_
#define _SUBJECT_HPP_

#include <iostream>
#include <vector>
#include "Student.hpp"

using namespace std;

// Forward declarations
class Students;
class Teachers;
class Teacher;

class Subject
{
    // Allow Teacher class to access the attributes of Subject class
    friend class Teachers;
    // Allow Teachers class to access the attributes of Subject class
    friend class Teacher;
    // Allow Student class to access the attributes of Subject class
    friend class Students;
private:
    string name;
    float credit_hours;
public:
    // Default constructor
    Subject();

    // Overloaded constructor
    Subject(string name, float credit_hours);

    // Destructor
    ~Subject();
};

#endif
