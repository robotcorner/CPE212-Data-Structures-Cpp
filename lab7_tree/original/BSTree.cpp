#include "BSTree.h"
#include <fstream>
#include <string>

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

void TreeType::DuplicateItem (ItemType item) 
{
  if (TreeNode.info 
}


/*void TreeType::GetNextItem (ItemType& item, OrderType order, bool& finished
{

}*/

void Print (TreeNode* tree, std::ofstream& outFile)
// Print into member of items in tree in sorted order on outFile
{
  if (tree != NULL)
  {
    Print(tree->left, outFile);       // Print left subtree.
    outFile << tree->info.namenum << " ";
    outFile << tree->info.classnum << " ";
    outFile << tree->info.gradenum << "\n";
    if (tree->equal != NULL)
    {
      Print(tree->equal, outFile);
    }
    Print(tree->right, outFile);      // Print right subtree.
  }
}

void TreeType::PrintItem(std::ofstream& outFile) const
// Calls recursive function Print to print items in tree.
{
  Print(root, outFile);
}
