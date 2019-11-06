#include <fstream>

/* 
struct info
{
  int count;
  int namenum;
  int classnum;
  int gradenum;
};
*/

typedef int ItemType;

struct TreeNode
{
  ItemType info;
  TreeNode* left;
  TreeNode* right;
  TreeNode* equal;
};

enum OrderType {PRE_ORDER, IN_ORDER, POST_ORDER};

class TreeType
{
  private:
    TreeNode* root;

  public:
    TreeType();                                                  // constructor
    ~TreeType();                                                 // destructor
    TreeType (const TreeType& originalTree);                     // copy constructor
    void operator=(const TreeType& originalTree);
    void MakeEmpty();
    bool IsEmpty() const;
    bool IsFull() const;
    int LengthIs() const;
    void RetrieveItem (ItemType& item, bool& found);
    void InsertDuplicate(ItemType item);
// inserted by kulick 
    void InsertItem(ItemType item);
    void CountDuplicate(int namenum, int* count);
    void DeleteItem (ItemType item);
    void ResetTree (OrderType order);
    void GetNextItem (ItemType& item, OrderType order, bool& finished);
    void PrintItem ();
};

