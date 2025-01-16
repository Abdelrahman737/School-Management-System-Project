#ifndef _SUBJECTS_H_
#define _SUBJECTS_H_

#include <iostream>
#include <vector>
#include "Subject.hpp"

using namespace std;

class Student;
class Teachers;

class Subjects
{
	friend class Student;
	friend class Teachers;

private:
	vector<Subject> subjects;

public:
	//constructor
	Subjects();
	//destructor
	~Subjects();
};

#endif
