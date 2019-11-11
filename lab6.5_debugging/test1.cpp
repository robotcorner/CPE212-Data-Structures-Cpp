#include <iostream>
#include <ostream>

void queue_driver();

using namespace std;

int main()
{
int i;
int user_input;         // INT IS TOO SMALL - DOUBLE
int a[10];             
// int*  array = new int[100];  // MEMORY LEAK - NOT USED - ALLOCATES BUT NOT USED
cout << "hello1 " << endl;
for(i=0;i<10;i++) a[i]=0;   // CHANGED TO LESS THAN 10, NOT LESS OR EQUAL
cout << " hello2 " << endl;
a[1] = 0;             //CHANGED A[1000000] TO a[1] //set a[1] = 0
cout << "hello3 " << endl;

cout << "input a test value " << endl;
if(!(cin >> user_input)) {cin.clear();cin.ignore(1000,'\n');}  // INPUTS AND CHECK FOR FAIL STATE AT SAME TIME

while(user_input != 9999)
{
  if(user_input >1) cout << "greater than 1 " << endl;
  if(user_input == 1) cout << "a 1 was entered " << endl;
  if(user_input == 2) cout << "a 2 was entered " << endl;
  
  if(user_input > 100000) cout << "input ignored" << endl; // ADDING A IF STATMENT TO PREVENT ERROR FOR LARGE NUMS beyond int size
  
  if(user_input == 10) {
    cout << " a 10 was entered ";
    a[user_input] = 100; 
  }
  cout << "input next value " << endl;
  
  if(!(cin >> user_input)) {cin.clear();cin.ignore(1000,'\n');}  // THIS WILL KEEP TAKING VALUES FOR NO INPUT FOR SOME REASON
}
// now test the queue software 

queue_driver();
cout << "Program Finished";
return 0;
}


