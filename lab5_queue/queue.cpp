/*
  * queue.cpp header 
  * Circular Queue Implementation
  * modify the queue class to perform some other method
  * write derived class that can handle exceptions 
*/
#include "queue.h"
using namespace std;

// DEFAULT QUEUE CREATION
Queue::Queue()		    			    // Constructor
{
  maxQue = 501;					        // Want a queue which stores 100 elements
  front = maxQue - 1;				  
  rear = maxQue -1;             // front == rear (this can be used to check for an empty queue)
  items = new ItemType[maxQue]; // Allocate array of pointers for queue
}            						        // End Queue::Queue()

// CUSTOM QUUE LENGTH
Queue::Queue(int max)				  // Parameterized constructor
{	
  maxQue = max + 1;				    // Want a queue which stores max elements
  front = maxQue - 1;				  // front == rear implies Empty
  rear = maxQue -1;
  items = new ItemType[maxQue];
} 						                // End Queue::Queue(…)

Queue::~Queue()					      // Destructor
{	
  delete [] items;				    // Deallocate the queue array
} 						                // End Queue::~Queue()

void Queue::MakeEmpty()				// Initialize queue to empty
{
  front = maxQue -1;		
  rear = maxQue -1;           // ? Why is this empty
} 						                // Queue::MakeEmpty()

bool Queue::IsEmpty() const		// Determine if queue is empty
{
  return (front == rear);               // If the front == the rear, then que is empty
} 						                // End Queue::IsEmpty()


bool Queue::IsFull() const		        // Determine if queue is full
{
  return ((rear + 1) % maxQue == front);
} 						                // End Queue::IsFull()

void Queue::Enqueue(ItemType newItem)   // Add item to rear of queue
{						                            // Precondition:  the queue is not empty
  rear = (rear+1) % maxQue;             // set the rear = to the beginning of array
  items[rear] = newItem;
  if(IsFull()) {       
    throw newItem;
  }
} 						                // End Queue::Enqueue(…)

void Queue::Dequeue(ItemType& item)	    // Remove item from front of queue
{						                // Precondition:  the queue is not empty
  front = (front + 1) % maxQue;
  item = items[front];
} 						                // End Queue::Dequque(…)


