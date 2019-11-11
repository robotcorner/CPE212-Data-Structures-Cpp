/*            uah_employee.cpp  class structure for all UAH employees  */


#include <iostream>

#include "uah_person.h"
#include "uah_student.h"

using namespace std;

uah_student::uah_student ()   /* default null constructor */
{
  cout << "null student 's not allowed" << endl;

}  	                     /* end default null constructor   */

/* non null constructors calls uah_person's constructor with the right data */

uah_student::uah_student(string name, string email, string a_number, string gpa) : uah_person (name, email, a_number)
{
 
/* update an student's only value unique to employees */

u_gpa = gpa;

}

void uah_student:: set(string name, string email, string a_number, string gpa)
{
/* use the person's set function to change data unique to person */
uah_person::set(name, email, a_number);
u_gpa = gpa; /* set the salary here */
}

void uah_student:: print( ) const
{
  cout << "insert code here to print out all values of a student " << endl;         // DO STUFF HERE
        // PRINT OUT THE PRIVATE VALUES
        // USE THE PUBLIC METHOD FOR PRINTING OUT THE BASE CLASS VALUES

}


// know how to create tar file and un tar a file

