/* 
  * The Purpose of Queue Driver is to check that the class functions correctly:
*/
#include "queue.h"
#include <iostream>

using namespace std;

int main()
{
  student item;
  item.name = "Test";
  item.aNumber = 00000000;
  item.gpa = 4.0;
  
  Queue A_queue(100);        
  
  // MODIFIED to STORE 1000 RECORDS, NOW 900 records are lost but will stop at 100 because of exception.
  for(int i=0;i<1000;i++){
     //cout << "pushed item was " << i << endl;
     try {
       A_queue.Enqueue(item);    // add records past 100 to 1000 and throw an error when above the 100
       cout << "Added Item: " << i << endl;
     }
     catch (student item){
       cout << "Error / Exception: " << i << " encountered\n";
       cout << "End Program because no more values will be saved" << endl;  
       break;
     }
  }
  /*
  for(int i=0;i<1000;i++){
     A_queue.Dequeue(item);
     cout << "returned item was " << item << endl;
  }
  */
}