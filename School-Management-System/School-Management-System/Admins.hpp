#ifndef _ADMINS_HPP_
#define _ADMINS_HPP_
#include <iostream>
#include <vector>
#include "Admin.hpp"

using namespace std;

class Admins
{
private:
	vector<Admin> admins;
public:
	//constructor
	Admins();

	//destructor
	~Admins();

	//add a new Admin
	void add_admin(Admin my_admin);

	//remove an Admin
	void remove_admin(string username);

	// Merges two subarrays of admins.
	// First subarray is admins[left..middle]
	// Second subarray is admins[middle+1..right]
	void merge(vector<Admin>& admins, int left, int middle, int right);

	// Implements merge sort algorithm to sort admins based on a specific criterion.
	// left is the starting index, right is the ending index of the subarray to be sorted
	void merge_sort(vector<Admin>& admins, int left, int right);


	// Performs binary search on the sorted vector of admins to find the admin with the given name.
	// Returns the index of the admin if found, otherwise returns -1.
	// left is the starting index, right is the ending index of the subarray to be searched
	int binary_search_by_name(vector<Admin>& admins, string name, int left, int right);
	
	//display all the Admins
	void display_all_admins() const;

	//display the information of a specific Admin
	void display_admin_info(string username);

	//edit the information of a specific Admin
	void edit_admin_info(int id, string name, int age, string gender, int phone_number, string new_username, string password);

	//save the information of all the Admins to a txt file
	void save_admins();

	// Loads the information of all the Admins from a txt file.
	void load_admins();

	int get_length();

	int get_id(const Admin& my_admin);

	//Returns the password of the admin
	string get_password(const Admin& my_Admin);

	string get_username(const Admin& my_admin);

	//Returns the password of the admin
	string get_gender(const Admin& my_Admin);

	//Returns the vector of admins
	vector<Admin> get_dataset();
};

#endif
