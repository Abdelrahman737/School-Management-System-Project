#ifndef FUNCTIONS_IMPLEMENTATION_HPP
#define FUNCTIONS_IMPLEMENTATION_HPP
#include <iostream>
#include "Students.hpp"
#include "Teachers.hpp"
#include "Subjects.hpp"
#include "Admin.hpp"


void menu();
void admin_management();
void take_admin_info(int& id, string& name, string& password, string& username, string& gender, int& age, int& phone_number);
Admin add_new_admin();
void delete_admin();
void display_all_admins();
void display_admin_by_username();
void edit_admin_info();
void student_management();
void teacher_management();

#endif
