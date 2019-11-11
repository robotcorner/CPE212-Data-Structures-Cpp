#include <iostream>
#include <stdio.h>
using namespace std;


// old stuff
//void swap(int *x, int *y);
//void printvalue(int *x, int *y);
//void sum(int* array, int length) ;


// create a new print function which prints out the contents of the student records when called
// with a student record pointer test the print function with student record pointers s1, s2, and s3 

// create a new swap function which takes two student record pointers and swaps the values. Test on 
// students s1 and s2.  

// print the values of the new student record pointers s1, s2 , s3 to ensure the swap took place correctly

// you may delete all the old stuff to make your code clearer

// upload your cpp file to canvas


struct student_record { 
    string  name;
    int *Anumber;
    float *gpa;
};

void print(*SR);
void swap(student_record *pStruct1,student_record *PStruct2);

int main () 
{

// old stuff 
//	int a = 100;
//  int b = 200;
//	printvalue(&a, &b);
//   	swap(&a, &b);
//	printvalue(&a, &b);

    
    // DECLARE 3 STRUCTURES
    student_record *s1 = new student_record;            // provides address for pointer
    student_record *s2 = new student_record;    
    student_record *s3 = new student_record;
    
    s1->name = "jeff";
    s1->Anumber = new int;  // provides address for the pointer
    *s1->Anumber = 12345;
    s1->gpa = new float;    
    *s1->gpa = 5.1;
    
    s2->name = "umesh";
    s2->Anumber = new int;  // provides address for the pointer
    *s2->Anumber = 12346;
    s2->gpa = new float;    
    *s2->gpa = 6.1; 

    s3->name = "noah";
    s3->Anumber = new int;  // provides address for the pointer
    *s3->Anumber = 12347;
    s3->gpa = new float;    
    *s3->gpa = 8.1; 

    print(s1);
    print(s2);
    print(s3);
   
    delete s1, s2, s3;

   	return 0;
}

void print(student_record *s) {
    cout << SR->name << endl;
    cout << *SR->Anumber << endl;
    cout << *SR->gpa << "\n\n";
    return;
}

void swap(student_record *pS1,student_record *PS2); {
    cout << "nothing";
    return;
}

// old stuff
//void swap(int *x, int *y) 
//{
//   	int temp;
//   	temp = *x; 
//   	*x = *y; 
//   	*y = temp; 
//  
//	return;
//}

//old stuff
//void printvalue(int *x, int *y)
//{
//	cout << "Value of a :" << *x << endl;
//   	cout << "Value of b :" << *y << endl;
//	return;
//}

// old stuff
//void sum(int* array, int length) 
//{
//    	int i, sum_of_array = 0; 
//    	for (i = 0; i < length; i++) 
//        	sum_of_array = sum_of_array + *(array + i); 
//    	cout << "sum of array is = " << sum_of_array<< endl; 
//	return;
//}
