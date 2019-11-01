#include <fstream>

struct info
{
  int count;
  int namenum;
  int classnum;
  int gradenum;
};

typedef info ItemType;

struct TreeNode
{
  ItemType info;  // What is HAPPENING
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
    void CountDuplicate(int namenum, int* count);
    void DeleteItem (ItemType item);
    void ResetTree (OrderType order);
    void GetNextItem (ItemType& item, OrderType order, bool& finished);
    void PrintItem (std::ofstream& outFile) const;
    struct TreeNode DuplicateItem (ItemType item);    // added duplicateItem
};

