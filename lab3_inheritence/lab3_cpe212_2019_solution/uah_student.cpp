/*            uah_employee.cpp  class structure for all UAH employees  */


#include <iostream>

#include "uah_person.h"
#include "uah_student.h"

using namespace std;

uah_student::uah_student ()   /* default null constructor */
{
  cout << "null student's not allowed" << endl;
for(int i = 0; i<10; i++)
{
enrolled_courses[i] = 0;
}
number_enrolled_courses = 0;

}  	                     /* end default null constructor   */

/* non null constructors calls uah_person's constructor with the right data */

uah_student::uah_student(string name, string email, string a_number, string gpa) : uah_person (name, email, a_number)
{
 
/* update an student's only value unique to employees */
for(int i = 0; i<10; i++)
{
enrolled_courses[i] = 0;
}
number_enrolled_courses = 0;
u_gpa = gpa;

}

void uah_student:: set(string name, string email, string a_number, string gpa)
{
/* use the person's set function to change data unique to person */
uah_person::set(name, email, a_number);
u_gpa = gpa;
}

void uah_student::print( ) const
{
  uah_person::print();
  cout << "GPA: " << u_gpa << endl;
if(number_enrolled_courses>0)
{
  cout << "Enrolled Courses: " << endl;
  for(int i = 0; i < number_enrolled_courses; i++)
  {
	cout << enrolled_courses[i] << endl;
  }
}
}

void uah_student::add_enrolled_class(int course_number)
{
if(course_number >= 100 && course_number < 1000)
{
  if(number_enrolled_courses < 10)
  {
	int i = (number_enrolled_courses);
	enrolled_courses[i] = course_number;
	number_enrolled_courses++;
	cout << "Course #" << course_number << " successfully added!" << endl;
  }
  else
  {
	cout << "Only 10 courses allowed" << endl << endl;
  }
}
else
	cout << "Invalid course number" << endl << endl;
}

