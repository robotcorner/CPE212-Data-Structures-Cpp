#ifndef UAH_EMPLOYEE_H
#define UAH_EMPLOYEE_H
/* this is the uah_employee include file */

#include <iostream>
#include <string>
using namespace std;

#include "uah_person.h"

class uah_employee: virtual public uah_person
{
  private:  /* private members */
    string u_salary;
  public:  /* public members */
  uah_employee();        /* null constructor */
  uah_employee(string somename, string somemail, string someanumber, string somesalary); /* not null constructor */
  void set(string somename, string somemail, string someanumber, string somesalary);
  void print() const ;
  void printSal() const;
};
#endif

