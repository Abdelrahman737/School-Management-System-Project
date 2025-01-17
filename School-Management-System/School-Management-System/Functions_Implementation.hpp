#ifndef FUNCTIONS_IMPLEMENTATION_HPP
#define FUNCTIONS_IMPLEMENTATION_HPP
#include <iostream>
#include "Students.hpp"
#include "Teachers.hpp"
#include "Subjects.hpp"
#include "Admin.hpp"


void menu();
void take_admin_info(int& id, string& name, string& password, string& username, string& gender, int& age, int& phone_number);
Admin add_new_admin();
void delete_admin();
void display_all_admins();
void display_admin_by_username();
void edit_admin_info();
void admin_management();
void set_attendance_precentage();
void set_marks();
void take_student_info(int& id, string& name, int& age, int& grade, string& gender, int& phone_number);
Student add_new_student();
void delete_student();
void display_all_students();
void display_student_by_name();
void edit_student_info();
void student_management();
void teacher_management();

#endif
