#include "BSTree.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

TreeType::TreeType()
{
  root = NULL;
}

void Destroy (TreeNode*& tree)
// Post: tree is empty; nodes have been deallocated.
{
  if (tree!= NULL)
  {
    Destroy(tree->left);
    Destroy(tree->right);
    delete tree;    
  }
}

TreeType::~TreeType()
{
  Destroy(root);
}

TreeType::TreeType(const TreeType& originalTree)
{

}

void TreeType::MakeEmpty()
{
  Destroy(root);
  root = NULL;
}

bool TreeType::IsEmpty() const
{

}

bool TreeType::IsFull() const
{
  TreeNode* location;
  try
  {
    location = new TreeNode;
    delete location;
    return false;
  }
  catch ( std::bad_alloc )
  {
    return true;
  }
}

int TreeType::LengthIs() const
{

}

/*void TreeType::RetrieveItem (ItemType& item, bool& found)
{

}*/

void InsertDuplicate2(TreeNode*& tree, ItemType item);

void TreeType::InsertDuplicate(ItemType item)
// Calls recursive function Insert to insert item into tree.
{
  InsertDuplicate2(root, item);
}

void InsertDuplicate2 (TreeNode*& tree, ItemType item)
// Inserts (possibly duplicate) item into tree
// Post: item is in tree; search property is maintained
{
}


//--------------------------------------------------------------------------------------------------------------------



// added by kulick

void Insert(TreeNode*& tree, ItemType item);

void TreeType::InsertItem(ItemType item)
// call Insert recursively
{
Insert (root, item);
}




//body of inserter

void Insert (TreeNode*& tree, ItemType item)
// Inserts item into tree
{
if(tree==NULL)
{
// insertion place found 
tree = new TreeNode;
tree->right = NULL;
tree->left  = NULL;
tree->info  = item;
}
else if (item == tree->info)
     { 
     cout << "duplicate " << item << endl;
     return;
     }
else if(item < tree->info)
    Insert(tree->left, item);
else 
    Insert(tree->right, item);
}



void CountDuplicate2 (TreeNode*& tree, int classnum, int* count);

void TreeType::CountDuplicate(int classnum, int* count)
{
  CountDuplicate2(root, classnum, count);
}

void CountDuplicate2 (TreeNode*& tree, int classnum, int* count)
{
}

// ------------------------------------------------------------------------------------------------------------------------

void TreeType::DeleteItem (ItemType item)
{

}

void TreeType::ResetTree (OrderType order)
{

}

/*void TreeType::GetNextItem (ItemType& item, OrderType order, bool& finished
{

}*/

void Print (TreeNode* tree)
// Print into member of items in tree in sorted order on outFile
{
  if (tree != NULL)
  {
    Print(tree->left);       // Print left subtree.
    cout << tree->info <<  " " << endl;
    Print(tree->right);      // Print right subtree.
  }
}

void TreeType::PrintItem() 
// Calls recursive function Print to print items in tree.
{
  Print(root);
}
