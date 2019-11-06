#ifndef UAH_STUDENT_H
#define UAH_STUDENT_H

/* this is the uah_student include file */

#include <iostream>
#include <string>
using namespace std;

#include "uah_person.h"

class uah_student: virtual public uah_person
{
  private:  /* private members */
    string u_gpa;
    int enrolled_courses[10];
    int number_enrolled_courses;


  public:  /* public members */
    uah_student();        /* null constructor */

    uah_student(string somename, string somemail, string someanumber, string gpa); /* not null constructor */

    void set(string somename, string somemail, string someanumber, string gpa, int num_courses);
    void add_enrolled_class(int courseNum);
    void print() const ;
};
#endif

