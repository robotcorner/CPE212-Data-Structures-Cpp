//*******  stack.h Standard Header Information Here **********

//const int MAX_SIZE = 100;		// Maximum stack size 
const int MAX_SIZE = 3;			  // Maximum stack size for testing throw
typedef char ItemType;
class Stack			// Array-based Stack class
{
 private:
  ItemType data[MAX_SIZE];		// Head of linked list
  int top;			// Top of stack indicator

 public:
  Stack();			// Default constructor
  				// Postcondition: Empty stack created

  bool IsEmpty() const;		// Checks to see if stack is empty
				// Postcondition: Returns TRUE if empty, FALSE otherwise

  bool IsFull() const;		// Checks to see if stack is full
				// Postcondition: Returns TRUE if full, FALSE otherwise

  void Push(ItemType item);		// Adds item to top of stack

  void Pop();			// Removes top item from stack

  ItemType Top() const;		// Returns a copy of top item on stack
				// Postcondition: item still on stack, copy returned

  void MakeEmpty();			// Removes all items from stack
};
