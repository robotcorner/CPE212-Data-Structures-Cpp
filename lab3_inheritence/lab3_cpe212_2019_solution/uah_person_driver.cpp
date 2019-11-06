// thanks to mr cody holland for this very clear solution 
//
// note that the original code is still left in for regression testing
// to make sure nothing got broken during the modifications

#include <iostream>
#include "uah_person.h"
#include "uah_employee.h"
#include "uah_student.h"

using namespace std;

int main()
{// commenting out provided code to show only new code
/*
uah_person jeff1;
uah_person jeff2("jeff2", "jeffemail", "jeffanumber");

uah_employee jeff3;
uah_employee jeff4 ("jeff4", "jeffmail", "jeffanumber", "jeffsalary");

uah_student  jeff5;
uah_student  jeff6 ("jeff6", "jeffmail", "jeffanumber", "jeffgpa");

//cout << "trying to create  person jeff1 " << endl;
//cout << "trying to create person jeff2 " << endl;
//cout << "trying to create employee jeff3 " << endl;
//cout << "trying to create employee jeff4 " << endl;

//cout << "trying to create employee jeff5 " << endl;
//cout << "trying to create employee jeff6 " << endl;
cout <<"  jeff1  " << endl;
jeff1.print(); 
cout << endl;

cout <<"  jeff2  " << endl;
jeff2.print(); 
cout << endl;

cout <<"  jeff3  " << endl;
jeff3.print();
cout << endl;

cout <<"  jeff4  " << endl;
jeff4.print();
cout << endl;

cout <<"  jeff5  " << endl;
jeff5.print();
cout << endl;

cout <<"  jeff6  " << endl;
jeff6.print();
cout << endl;
*/

// test cases for enrolled courses function
// creating students
uah_student student1("Ricky","Ricky@gmail.com","A00000001","4.0");
uah_student student2("Bobby","Bobby@gmail.com","A00000002","3.9");
uah_student student3("Jimbo","Jimbo@gmail.com","A00000003","3.8");
uah_student student4("Casio","Casio@gmail.com","A00000004","3.7");

// case for 1 class
cout << endl << "\tRicky\t" << endl;
cout << "Trying to add class..." << endl;
student1.add_enrolled_class(100);

cout << endl;
student1.print();
cout << endl;

//case for 5 classes
cout << endl << "\tBobby\t" << endl;
cout << "Trying to add class..." << endl;
student2.add_enrolled_class(100);
cout << "Trying to add class..." << endl;
student2.add_enrolled_class(200);
cout << "Trying to add class..." << endl;
student2.add_enrolled_class(300);
cout << "Trying to add class..." << endl;
student2.add_enrolled_class(400);
cout << "Trying to add class..." << endl;
student2.add_enrolled_class(500);

cout << endl;
student2.print();
cout << endl;

// case for 10 classes
cout << endl << "\tJimbo\t" << endl;
student3.add_enrolled_class(109);
student3.add_enrolled_class(159);
student3.add_enrolled_class(209);
student3.add_enrolled_class(259);
student3.add_enrolled_class(309);
student3.add_enrolled_class(359);
student3.add_enrolled_class(409);
student3.add_enrolled_class(459);
student3.add_enrolled_class(509);
student3.add_enrolled_class(559);

cout << endl;
student3.print();
cout << endl;

cout << endl << "\tCasio\t" << endl;
// case for 11 classes (checking for error)
cout << "Trying to add class..." << endl;
student4.add_enrolled_class(109);
cout << "Trying to add class..." << endl;
student4.add_enrolled_class(159);
cout << "Trying to add class..." << endl;
student4.add_enrolled_class(209);
cout << "Trying to add class..." << endl;
student4.add_enrolled_class(259);
cout << "Trying to add class..." << endl;
student4.add_enrolled_class(309);
cout << "Trying to add class..." << endl;
student4.add_enrolled_class(359);
cout << "Trying to add class..." << endl;
student4.add_enrolled_class(409);
cout << "Trying to add class..." << endl;
student4.add_enrolled_class(459);
cout << "Trying to add class..." << endl;
student4.add_enrolled_class(509);
cout << "Trying to add class..." << endl;
student4.add_enrolled_class(559);
cout << "Trying to add class..." << endl;
student4.add_enrolled_class(999); // error should be printed here

cout << endl;
student4.print();
cout << endl;

return (0);
}

