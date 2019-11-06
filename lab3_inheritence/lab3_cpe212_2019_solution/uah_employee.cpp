/*            uah_employee.cpp  class structure for all UAH employees  */


#include <iostream>

#include "uah_person.h"
#include "uah_employee.h"

using namespace std;

uah_employee::uah_employee ()   /* default null constructor */
{
  cout << "null employee's not allowed" << endl;

}  	                     /* end default null constructor   */

/* non null constructors calls uah_person's constructor with the right data */

uah_employee::uah_employee(string name, string email, string a_number, string salary) : uah_person (name, email, a_number)
{
 
/* update an employee's only value unique to employees */

u_salary = salary;

}

void uah_employee:: set(string name, string email, string a_number, string salary)
{
/* use the person's set function to change data unique to person */
uah_person::set(name, email, a_number);
u_salary = salary; /* set the salary here */
}

void uah_employee:: print( ) const
{
  uah_person::print();
  cout <<  "Salary: " << uah_employee::u_salary << endl;
}

