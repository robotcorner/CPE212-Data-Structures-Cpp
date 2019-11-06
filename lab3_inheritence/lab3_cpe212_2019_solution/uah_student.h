#ifndef UAH_STUDENT_H
#define UAH_STUDENT_H

/* this is the uah_student include file */

#include <iostream>
#include <string>
#include "uah_person.h"
using namespace std;





class uah_student: public uah_person
{
private:  /* private members */
  int enrolled_courses[10];
  int number_enrolled_courses;
  string u_gpa;

public:  /* public members */

uah_student();        /* null constructor */

uah_student(string somename, string somemail, string someanumber, string gpa); /* not null constructor */


void set(string somename, string somemail, string someanumber, string gpa);

void print() const ;

void add_enrolled_class(int course_number);
};
#endif

