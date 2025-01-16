#ifndef _TEACHERS_HPP_
#define _TEACHERS_HPP_

#include <iostream>
#include <vector>
#include "Teacher.hpp"

using namespace std;

class Teachers
{
private:

	vector<Teacher> teachers;

public:

	//constructor
	Teachers();

	//destructor
	~Teachers();

	//add a new teacher
	void add_teacher(int id, string name, int age, string gender, int phone_number, string email, Subject subs[2], string date_of_joining, string qualification);

	//remove a teacher
	void remove_teacher(string name);

	// Merges two subarrays of teachers.
	// First subarray is teachers[left..middle]
	// Second subarray is teachers[middle+1..right]
	void merge(vector<Teacher>& teachers, int left, int middle, int right);

	// Implements merge sort algorithm to sort admins based on a specific criterion.
	// left is the starting index, right is the ending index of the subarray to be sorted
	void merge_sort(vector<Teacher>& teachers, int left, int right);


	// Performs binary search on the sorted vector of teachers to find the teacher with the given name.
	// Returns the index of the teacher if found, otherwise returns -1.
	// left is the starting index, right is the ending index of the subarray to be searched
	int binary_search(vector<Teacher>& teachers, string name, int left, int right);

	//display the information of a specific teacher
	void dispaly_teacher_info(string name);

	//display the information of all the teachers
	void display_all_teachers() const;

	//edit the information of a teacher
	void edit_teacher_info(int id, string name, int age, string gender, int phone_number, string email, Subject subs[2], string date_of_joining, string qualification);

	//save the information of all the teachers to a txt file
	void save_teachers();

	//Loads the information of all the Admins from a txt file.
	void load_teachers();
};

#endif