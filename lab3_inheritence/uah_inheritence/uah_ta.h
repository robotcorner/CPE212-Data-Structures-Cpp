// TA HEADER FILE
#ifndef UAH_TA_H
#define UAH_TA_H

#include <iostream>
#include <string>
#include "uah_person.h"
#include "uah_employee.h"
#include "uah_student.h"

using namespace std;

class uah_ta: public uah_employee, public uah_student {
    public:
        uah_ta(); /* null constructor */
        uah_ta(string somename, string somemail, string someanumber, string gpa, string somesalary);

        void uah_ta::set(string name, string email, string a_number, string gpa, string salary)
        void add_enrolled_class(int);
        void print() const;
};
#endif