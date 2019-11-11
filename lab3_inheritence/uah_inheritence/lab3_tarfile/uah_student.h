#ifndef UAH_STUDENT_H
#define UAH_STUDENT_H

/* this is the uah_student include file */

#include <iostream>
#include <string>
using namespace std;

#include "uah_person.h"



class uah_student: public uah_person
{
private:  /* private members */
  string u_gpa;

public:  /* public members */

uah_student();        /* null constructor */

uah_student(string somename, string somemail, string someanumber, string gpa); /* not null constructor */
    // WHAT IF I DON'T HAVE GPA????

void set(string somename, string somemail, string someanumber, string gpa);

void print() const ;

};
#endif

