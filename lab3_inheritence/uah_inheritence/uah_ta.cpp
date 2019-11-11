/* Modify our existing classes for person, student 
and instructor to include a TA class which is both 
a student and instructor and all classes require 
non-null initializers as per our original design. 

https://www.geeksforgeeks.org/multiple-inheritance-in-c/ */

// TA_IMPLEMENTATION / DEFINITION FILE

#include <iostream>
#include "uah_person.h"
#include "uah_student.h"
#include "uah_employee.h"
#include "uah_ta.h"

using namespace std;

uah_ta::uah_ta() {
    cout << "Null TA contructor not allowed" << endl;
}

uah_ta::uah_ta(string somename, string somemail, string someanumber, string gpa, string somesalary) : 
    uah_student(name, email, a_number, gpa), uah_employee(u_name, u_email, u_anumber, salary) {
    // change the student only value unique to employees
    // change salary
    // uah_ta::ta_salary = somesalary;
}

void uah_ta::set(string name, string email, string a_number, string gpa, string salary) {
    uah_student::set(name, a_number, gpa);
    uah_employee::set(name, email, a_number, salary);
}

void uah_ta::add_enrolled_class(int coursenumber) {
    uah_student::add_enrolled_class(coursenumber);
}

void uah_ta::print() {
    uah_student::print();
    uah_employee::printSal();
}