// STEPHEN STAMMEN
// JAKOB HENSON
/* DIRECTIONS

Ascendingsort, which sorts a linked list that is unsorted.

For this laboratory you might want to keep track of the number of elements in the list since there will be no sort if the list is empty or has only one element. 

I suggest a sort similar to one used for other structures.  You start at the first list element, search the list  for the smallest element less than the current one, and swap them if there is any.  You repeat this process starting at the second element, third element until all elements have been placed in the right position.  
*/

#include <iostream>
#include <cstddef>  // Allows use of NULL, which is normally zero, cannot read or right to it.
#include "LList.h"

using namespace std;


struct NodeType
{
  ItemType      component;
  NodeType*     nextNode;     
};

LList::LList()		  // Default Constructor	
{				
  head = NULL;      // Empty list created
  tail = NULL;      // Added tail to print to previousNode
  position = 0;
}

bool LList::IsEmpty() const		// Checks to see if list is empty
{				
  return (head == NULL);        // Returns TRUE if empty, FALSE otherwise
}

void LList::Print() const		// Prints the current list
{				
  NodeType* currentNodePtr = head;
  
  while (currentNodePtr != NULL)
  {
    cout << currentNodePtr->component << endl;  
    currentNodePtr = currentNodePtr->nextNode;      // Make the currentnodePtr POINT to the nextNode
  }
    if(IsEmpty())
        cout<<"list is empty\n";
    cout<<"end of print\n" << endl;
}


// Summary Assumption: 
// This function extracts the pointer listItem and head, then assigns the head value to the pointer values
void LList::InsertasFirst(ItemType listItem)
{				
  NodeType* tempPtr = new NodeType;	        // pointer object tempPtr declared and allocated space
                                            // tempPtr contains nextnoded, previousNode and component
  tempPtr->component = listItem;                // (*tempPtr).component = listItem || pointer component = listItem
  tempPtr->nextNode = head;                 // tempPtr nextNode = head
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
void LList::AscendingSort() {

  NodeType *i,*j;
  int temp;
  if(!IsEmpty())
  {
      for(i=head; i->nextNode!=NULL; i=i->nextNode)
      {
        for(j=i->nextNode; j!=NULL; j=j->nextNode)
        {
          if(i->component > j->component)
          {
          temp = i->component;
          i->component = j->component;
          j->component = temp;
          }
        }
      }
  }
} // End List::AscendingSort()


LList::~LList() // Destructor
{
    // Write soemthing to deallocates space.
    ItemType listItem;
    while(!IsEmpty()) {     // loop deallocates all list times.
        RemoveFirst(listItem);
    }
}

// Space is returned when the program is exited.

