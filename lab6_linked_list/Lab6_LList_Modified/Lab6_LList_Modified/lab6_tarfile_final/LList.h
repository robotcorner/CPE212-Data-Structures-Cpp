//*******  LList.h Standard Header Information Here **********

struct NodeType;			// Forward declaration, complete declaration in LList.cpp 

typedef int ItemType;		// Data type of each item in list

class LList			// Linked List class
{
 private:
  NodeType* head;			// Head of linked list

 public:
  LList();			// Default constructor
  				// Postcondition: Empty list created

  bool IsEmpty() const;		// Checks to see if list is empty
				// Postcondition: Returns TRUE if empty, FALSE otherwise


  void Print() const;		// Prints list contents
				// Postcondition: list contents, if any, has been printed


  void InsertasFirst(ItemType item);	// Adds item to beginning of list
				// Precondition: item < first list item
				// Postcondition: item is first in List & 
				//	list items are in order
//*******  LList.h Continued Here **********


  void Insert(ItemType item);		// Adds item to correct place in list
				// Precondition: items in list are in ascending order
				// Postcondition: new node containing item added to list
				// 	& all list items in ascending order


  void RemoveFirst(ItemType& item);	// Removes first item occurrence from list if not empty
				// Postcondition: item set to first item on list &
				//	item is no longer in list & 
				// 	list items in ascending order


  void Delete(ItemType item);		// Removes item from the list
				// Precondition: item is in list
				// Postcondition: first occurrence of item is no longer
				//	in list & list items are in ascending order


  ~LList();			// Destructor  
				// Postcondition: List destroyed

};
