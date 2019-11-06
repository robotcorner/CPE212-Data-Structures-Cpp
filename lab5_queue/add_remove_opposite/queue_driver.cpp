#include "queue.h"
#include <iostream>

using namespace std;

int main()
{
int item; 

Queue A_queue(100);

cout << endl << "old methods" << endl << endl;
for(int i=0;i<10;i++)
  {
   cout << "pushed item was " << i << endl;
   A_queue.Enqueue(i);
  }
for(int i=0;i<10;i++)
  {
   A_queue.Dequeue(item);
   cout << "returned item was " << item << endl;
  }


cout << endl << "old enqueue with opposite dequeue" << endl << endl;

for(int i=0;i<10;i++)
  {
   cout << "pushed item was " << i << endl;
   A_queue.Enqueue(i);
  }
for(int i=0;i<10;i++)
  {
   A_queue.Dequeue_Opposite(item);
   cout << "returned item was " << item << endl;
  }
  

cout << endl << "opposite enqueue with old dequeue" << endl << endl;
  
for(int i=0;i<10;i++)
  {
   cout << "pushed item was " << i << endl;
   A_queue.Enqueue_Opposite(i);
  }
for(int i=0;i<10;i++)
  {
   A_queue.Dequeue(item);
   cout << "returned item was " << item << endl;
  }
}
  
