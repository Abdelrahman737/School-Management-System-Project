#ifndef _Students_H_
#define _Students_H_

#include <iostream>
#include <vector>
#include "Subject.hpp"

using namespace std;

class Student;

class Students
{
private:
	vector<Student> students;

public:
	//constructor
	Students();

	//destructor
	~Students();

	//add a new student
	void add_student(Student my_student);

	//display the information of a specific student
	void display_student_info(string name);

	//display the information of all the students
	void display_all_students();

	//remove a student
	void remove_student(string name);

	//edit the information of a student
	void edit_student_info(string search_input,string name, int id, int age, int grade, string gender, int phone_number);

	//Set the attendance percentage of a student
	void set_attendance_percentage(string name, float attendance_percentage);

	//Set the marks of a student
	void set_marks(string name, vector<float> marks);

	//save the information of all the students to a txt file
	void save_students();

	//load the information of all the students from a txt file
	void load_students();

	//Merge function that merges to sorted functions
	void merge(vector<Student>& students, int left, int middle, int right);
	
	//Recursive merge sort function
	void merge_sort(vector<Student>& students, int left, int right);

	//Binary search function for the students by name
	int binary_search_by_name(vector<Student>& students, string name, int left, int right);

	//Binary search function for the students by id
	int binary_search_by_id(vector<Student>& students, int id, int left, int right);
	
	int get_length();

	vector<Student> get_dataset();

	vector<Subject> get_subjects(Student my_student);
};

#endif