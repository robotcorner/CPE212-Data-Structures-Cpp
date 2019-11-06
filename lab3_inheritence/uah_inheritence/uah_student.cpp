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

uah_student::uah_student(string name, string email, string a_number, string gpa):uah_person(name, email, a_number)
{
  /* update an student's only value unique to employees */
  u_gpa = gpa;
}

void uah_student::set(string name, string email, string a_number, string gpa, int num_courses)
{
  /* use the person's set function to change data unique to person */
  uah_person::set(name, email, a_number);
  u_gpa = gpa; /* set the salary here */
  number_enrolled_courses = num_courses;
}

void uah_student::print( ) const
{
  uah_person::print();
  cout << u_gpa << endl;
  if(number_enrolled_courses > 0) 
  {
    for (int i = 0; i < number_enrolled_courses; ++i) 
    {   
      if (i >= 10) 
      {
       cout << "You cannot take more than 10 classes at a time!" << endl;
       break;       
      }
      cout << enrolled_courses[i] << " ";
    }  
  }
  cout << endl;
}

void uah_student::add_enrolled_class(int course_number) 
{    
    if((course_number <= 900) && (course_number >= 100)) 
    {
        enrolled_courses[number_enrolled_courses] = course_number;
        number_enrolled_courses += 1;
    }
}

// ALL TEST BUILT INTO DRIVER FILE
