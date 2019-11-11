#include <iostream>
#include <cstddef>  // Allows use of NULL, which is normally zero, cannot read or right to it.
#include "LList.h"

using namespace std;


struct NodeType
{
  ItemType      component;
  NodeType*     nextNode;       // 
  NodeType*     previousNode;   // Added Tail Node
};

LList::LList()		  // Default Constructor	
{				
  head = NULL;      // Empty list created
  tail = NULL;      // Added tail to print to previousNode
}

bool LList::IsEmpty() const		// Checks to see if list is empty
{				
  return (head == NULL);        // Returns TRUE if empty, FALSE otherwise
}

void LList::Print() const		// Prints the current list
{				
  NodeType* currentNodePtr = head;
  NodeType* previousNodePtr = tail; // Added previous node ptr

  while (currentNodePtr != NULL)
  {
    cout << currentNodePtr->component << endl;  
    currentNodePtr = currentNodePtr->nextNode;      // Make the currentnodePtr POINT to the nextNode
  }
    if(IsEmpty())
        cout<<"list is empty\n";
    cout<<"end of print\n";
}


// Summary Assumption: 
// This function extracts the pointer listItem and head, then assigns the head value to the pointer values
void LList::InsertasFirst(ItemType listItem)
{				
  NodeType* tempPtr = new NodeType;	        // pointer object tempPtr declared and allocated space
                                            // tempPtr contains nextnoded, previousNode and component
  tempPtr->component = listItem;                // (*tempPtr).component = listItem || pointer component = listItem
  tempPtr->nextNode = head;                 // tempPtr nextNode = head
  tempPtr->previousNode = tail;             // Added for doubly linked list
  head = tempPtr;
  tail = tempPtr;                           // Added for Doubly linked list
}

void LList::RemoveFirst(ItemType& listItem)	
{				
  NodeType* tempPtr = head;	
  listItem = head->component;
  head = head->nextNode;
  
  delete tempPtr;
}

void LList::Insert(ItemType listItem)	
{				
    NodeType* temp = new NodeType;      // Allocates space for a NodeType structure pointer called temp
    temp->component = listItem;         // temp component = the value passes in as listItem
    bool isEnd = false;    
    NodeType* made = head;              // TODO: What the heck is made.

    if(head==NULL || temp->component<=head->component)   // If head is NULL or the temporary component is less than the front component 
    {                   
        InsertasFirst(temp->component);                  // input that component as the first one in the list
    } else {       
        while(!isEnd && (made->component)<=(temp->component) && made->nextNode->component <= temp->component) // while not the end and the 
        {   
            made=made->nextNode;
            if(made->nextNode==NULL)
                isEnd=true;
        }
        temp->nextNode=made->nextNode;
        made->nextNode=temp;
    }
}

void LList::Delete(ItemType listItem)	
{				
    NodeType* made=head;
    NodeType* before=head;

    bool isEnd=false;
    bool found=false;  

    while(!isEnd &&(made->component!=listItem))   // While not the end and 
    {   
        made=made->nextNode;
        if(made->nextNode==NULL)
            isEnd=true;        
    }

    if(made->component==listItem)
            found=true;

    while(made!=head && before->nextNode!=made)
    {   
        before=before->nextNode;
    }
    if(found)
    {
        if(made==head)
        {
            RemoveFirst(made->component);
        } else {
            before->nextNode=made->nextNode;
            made->nextNode=NULL;
            delete made;
        }
    }
    else
    {
        cout<<"listItem not found. Could not delete.\n";
    }
}

LList::~LList() // Destructor
{
    // Write soemthing to deallocates space.
    /*NodeType.component list;
    while(listItem.!isEmpty()) {     // loop deallocates all list times.
        RevoveFirst(listItem);
    }
    */
}

// Space is returned when the program is exited.

