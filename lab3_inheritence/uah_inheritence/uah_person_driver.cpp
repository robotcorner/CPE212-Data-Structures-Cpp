// THIS FILE TESTS THE UAH PERSON CPP
#include <iostream>
#include "uah_person.h"
#include "uah_employee.h"
#include "uah_student.h"
#include "uah_ta.h"
using namespace std;

int main()
{
// TESTING PERSON, EMPLOYEE AND STUDENT CLASSES
  //cout << "trying to create  persone jeff1 " << endl;
  uah_person jeff1;
  //cout << "trying to create person jeff2 " << endl;
  uah_person jeff2("jeff2", "jeffemail", "jeffanumber");
  //cout << "trying to create employee jeff3 " << endl;
  uah_employee jeff3;
  //cout << "trying to create employee jeff4 " << endl;
  uah_employee jeff4("jeff4", "jeffmail", "jeffanumber", "jeffsalary");
  //cout << "trying to create employee jeff5 " << endl;
  uah_student jeff5;

  cout <<"  jeff1  ";
  jeff1.print(); 
  cout << endl;

  cout <<"  jeff2  ";
  jeff2.print(); 
  cout << endl;

  cout <<"  jeff3  ";
  jeff3.print();
  cout << endl;

  cout <<"  jeff4  ";
  jeff4.print();
  cout << endl;

  cout <<"  jeff5  ";
  jeff5.print();
  cout << endl;

// STUDENT 1 - 1 COURSE
  uah_student student1("bob1", "mail1", "anumber1", "gpa1");
  cout <<"  Student1  ";
  student1.add_enrolled_class(104);
  student1.print();
  cout << endl;

// STUDENT 2 - 5 COURSES
  uah_student student2("bob2", "mail2", "anumber2", "gpa2");
  cout <<"  Student2  ";
  int student2_courses[] = {115, 244, 214, 212, 299};
  for (int course=0; course<5; ++course) {
    student2.add_enrolled_class(student2_courses[course]);
  }
  student2.print();
  cout << endl;

// STUDENT 3 - 10 COURSES
  uah_student student3("bob3", "mail3", "anumber3", "gpa3");
  cout <<"  Student3  ";
  int student3_courses[] = {101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
  for (int course=0; course<10; ++course) {
    student3.add_enrolled_class(student3_courses[course]);
  }
  student3.print();
  cout << endl;

// STUDENT 4 - 11 COURSES, SHOULD NOT ALLOW MORE THAN 10
  uah_student student4("bob4", "mail4", "anumber4", "gpa4");
  cout <<"  Student4  ";
  int student4_courses[] = {101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111};
  for (int course=0; course<10; ++course) {
    student4.add_enrolled_class(student4_courses[course]);
  }
  student4.print();
  cout << endl;

// TA CLASS TESTING
  cout << "TA CLASS TESTING" << endl;
  uah_ta ta1;
  uah_ta ta2("TA Name", "abc001@uah.edu", "A25000000", "3.6","1500");
  int ta2_teaching[] = {211, 212, 353};
  bool done = false;
  int courses = 0;
  while (!done) {
    cout << "Course List" << endl;
    for (int course=0; course<3; ++course) {
      ta2.add_enrolled_class(ta2_teaching[course]);
      cout << ta2_teaching[course] << " ";
      courses++;
    }
    done = true;
  }
  cout << "Course Enrolled: " << courses << endl;

  return 0;
}

