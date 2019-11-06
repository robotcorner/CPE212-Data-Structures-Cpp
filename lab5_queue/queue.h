/*
  * queue.h header
  * modify to use new methods in class queue
*/
#include<string>
using namespace std;

struct student{
    string name;
    int aNumber;
    float gpa;
};

typedef student ItemType;

class Queue
{
  private:
    ItemType* items;	// Queue items
    int maxQue;			// Max number of queue items + 1
    int front;		  	// Index of element before the front of queue
    int rear;			// Index of rear element of queue

  public:
    Queue();			// Constructor
    Queue(int max);		// Parameterized constructor

    ~Queue();			// Destructor

    void MakeEmpty();	            	  // Initialize queue to empty
    bool IsEmpty() const;       		  // Determine if queue is empty
    bool IsFull() const;	        	  // Determine if queue is full
    void Enqueue(ItemType newItem); 	  // Add item to rear of queue
    void Dequeue(ItemType& item);	      // Remove item from front of queue
};
