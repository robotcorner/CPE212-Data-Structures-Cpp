#include <iostream>
#include "uah_person.h"
#include "uah_employee.h"
#include "uah_student.h"

using namespace std;

int main()
{
uah_person jeff1;
uah_person jeff2("jeff2", "jeffemail", "jeffanumber");

uah_employee jeff3;
uah_employee jeff4 ("jeff4", "jeffmail", "jeffanumber", "jeffsalary");

uah_student  jeff5;
uah_student  jeff6 ("jeff6", "jeffmail", "jeffanumber", "jeffgpa");

//cout << "trying to create  persone jeff1 " << endl;
//cout << "trying to create person jeff2 " << endl;
//cout << "trying to create employee jeff3 " << endl;
//cout << "trying to create employee jeff4 " << endl;

//cout << "trying to create employee jeff5 " << endl;
//cout << "trying to create employee jeff6 " << endl;
cout <<"  jeff1  " ;
jeff1.print(); 
cout << endl;

cout <<"  jeff2  " ;
jeff2.print(); 
cout << endl;

cout <<"  jeff3  " ;
jeff3.print();
cout << endl;

cout <<"  jeff4  " ;
jeff4.print();
cout << endl;

cout <<"  jeff5  " ;
jeff5.print();
cout << endl;

cout <<"  jeff6  " ;
jeff6.print();
cout << endl;

return (0);;
}

