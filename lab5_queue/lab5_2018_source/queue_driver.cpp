#include "queue.h"
#include <iostream>

using namespace std;

int main()
{
int item; 

Queue A_queue(100);

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
}
