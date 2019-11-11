#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;



//************************************************************
// new stuff 
//***********************************************************


// create a new swap function which takes two student record pointers and swaps the values. Test on 
// students s1 and s2.  

// print the values of the new student record pointers s1, s2 , s3 to ensure the swap took place correctly

// you may delete all the old stuff to make your code clearer

// upload your cpp file to canvas


struct student_record
{ 
string  name;
int * Anumber;
float * gpa;
};


void print_student_record (student_record *);
void swap(student_record & , student_record & );

int main () 
{
// create three student record pointers, s1, s2, s3, each pointing to 
// an instance of student_record.  you must use new here

student_record *s1;
student_record *s2;
student_record *s3;


s1 = new (struct  student_record);
s2 = new (struct  student_record);
s3 = new (struct  student_record);

// assign the first one the values "jeff",12345,5.1
// assign the second one the values "umesh", 12346,6.1
// assign the third one the valuus "noah", 12347,8.1
// with a student record pointer test the print function with 
//     student record pointers s1, s2, and s3 


s1->name =   "jeff";
s1->Anumber = new int;
*(s1->Anumber) = 12345;
s1->gpa = new float;
*(s1->gpa) = 5.1 ;

s2->name =  "umesh";
s2->Anumber = new int;
*(s2->Anumber) = 12346;
s2->gpa = new float;
*(s2->gpa) = 6.1 ;

s3->name =  "noah";
s3->Anumber = new int;
*(s3->Anumber) = 12347;
s3->gpa = new float;
*(s3->gpa) = 8.1 ;

//print out their values before swap

cout << "before swap " << endl;

 print_student_record(s1);
 print_student_record(s2);
 print_student_record(s3);

 swap (s1, s2);

cout << "after swap of 1 and 2 " << endl;

 print_student_record(s1);
 print_student_record(s2);
 print_student_record(s3);


  	return 0;
}

void swap(student_record * sa, student_record * sb)
{
student_record * temp;
cout << "before swap " << sa <<  " " << sb << endl;
temp = sa;
sa = sb;
sb = temp;
cout << "after swap " << sa <<  " " << sb << endl;
}
 

void print_student_record(student_record * student)
{

cout << "name "    << student->  name << endl;;
cout << "Anumber " << *(student->  Anumber) << endl;
cout << "gpa "     << *(student->  gpa) << endl;
cout << "end print " << endl;
}
