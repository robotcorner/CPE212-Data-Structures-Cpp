#include <iostream>
#include <cstddef>
#include "LList.h"

using namespace std;


struct NodeType
{
  ItemType      component;
  NodeType*     nextNode;
};

LList::LList()			
{				
  head = NULL;
}

bool LList::IsEmpty() const		
{				
  return (head == NULL);
}


void LList::Print() const		
{				
  NodeType* currentNodePtr = head;

  while (currentNodePtr != NULL)
  {
    cout << currentNodePtr->component << endl;
    currentNodePtr = currentNodePtr->nextNode;
  }
    if(IsEmpty())
        cout<<"list is empty\n";
    cout<<"end of print\n";
}



void LList::InsertasFirst(ItemType item)
{				
  NodeType* tempPtr = new NodeType;	
				
  tempPtr->component = item;
  tempPtr->nextNode = head;
  head = tempPtr;
}


void LList::RemoveFirst(ItemType& item)	
{				
  NodeType* tempPtr = head;		
				
  item = head->component;
  head = head->nextNode;
  delete tempPtr;
}





void LList::Insert(ItemType item)	
{				
				
    
    NodeType* temp=new NodeType; 
    temp->component=item;   
    bool isEnd=false;   
    NodeType* made=head;    

    if(head==NULL || temp->component<=head->component)    
    {                   
        InsertasFirst(temp->component);
    }


    else    
    {       
        while(!isEnd && (made->component)<=(temp->component) && made->nextNode->component <= temp->component)
        {   
            made=made->nextNode;
            if(made->nextNode==NULL)
                isEnd=true;
        }
        temp->nextNode=made->nextNode;
        made->nextNode=temp;
    }



}


void LList::Delete(ItemType item)	
{				
				

    NodeType* made=head;
    NodeType* before=head;

    bool isEnd=false;
    bool found=false;  

    while(!isEnd &&(made->component!=item))
    {   
        made=made->nextNode;
        if(made->nextNode==NULL)
            isEnd=true;        
    }

    if(made->component==item)
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
        }
        else
        {
            before->nextNode=made->nextNode;
            made->nextNode=NULL;
            delete made;
        }
    }
    else
    {
        cout<<"Item not found. Could not delete.\n";
    }

  

}

LList::~LList()
{
}




