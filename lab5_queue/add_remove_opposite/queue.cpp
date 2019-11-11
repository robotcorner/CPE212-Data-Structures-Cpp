//*******  queue.cpp header Circular Queue Implementation **********
#include "queue.h"

Queue::Queue()					// Constructor
{
  maxQue = 501;					// Want a queue which stores 500 elements
  front = maxQue - 1;				// front == rear implies Empty
  rear = maxQue -1;
  items = new ItemType[maxQue];			// Allocate array for queue
} 						// End Queue::Queue()


Queue::Queue(int max)				// Parameterized constructor
{	
  maxQue = max + 1;				// Want a queue which stores max elements
  front = maxQue - 1;				// front == rear implies Empty
  rear = maxQue -1;
  items = new ItemType[maxQue];			// Allocate array for queue
} 						// End Queue::Queue(…)


Queue::~Queue()					// Destructor
{	
  delete [] items;				// Deallocate the queue array
} 						// End Queue::~Queue()


void Queue::MakeEmpty()				// Initialize queue to empty
{
  front = maxQue - 1;		
  rear = maxQue -1;
} 						// Queue::MakeEmpty()


bool Queue::IsEmpty() const			// Determine if queue is empty
{
  return (front == rear);
} 						// End Queue::IsEmpty()


bool Queue::IsFull() const			// Determine if queue is full
{
  return ((rear + 1) % maxQue == front);
} 						// End Queue::IsFull()


void Queue::Enqueue(ItemType newItem) 		// Add item to rear of queue
{						// Precondition:  the queue is not empty
  rear = (rear+1) % maxQue;
  items[rear] = newItem;
} 						// End Queue::Enqueue(…)

void Queue::Enqueue_Opposite(ItemType newItem) 	// Add item to front of queue
{	
  items[front] = newItem;			// Precondition: the queue is not full
  front = (front - 1) % maxQue;
} 						// End Queue::Enqueue(…)


void Queue::Dequeue(ItemType& item)		// Remove item from front of queue
{						// Precondition:  the queue is not empty
  front = (front + 1) % maxQue;
  item = items[front];
} 						// End Queue::Dequque(…)

void Queue::Dequeue_Opposite(ItemType& item)	// Remove item from rear of queue
{
  item = items[rear];				// Precondition: the queue is not empty
  rear = (rear - 1) % maxQue;
} 						// End Queue::Dequque(…)
