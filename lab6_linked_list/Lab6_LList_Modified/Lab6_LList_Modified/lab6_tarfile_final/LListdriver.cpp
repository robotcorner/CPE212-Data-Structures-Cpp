//a driver for testing of the LList class

#include "LList.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

#define MAX 10
LList alist;

main()
{


// insert a20 random items 
// //
ItemType randomitem;

srand(time(NULL));

// test on empty list 
// //alist.Ascendingsort();
//
alist.Print();

alist.InsertasFirst(0);
//test on a list with one item
// alist.Ascendingsort();
//
//
// test it on a list with many items
 for(int i=0;i<MAX;i++)
{  
randomitem = (int) (rand() % 100);
alist.InsertasFirst(randomitem);
}

alist.Print();

//alist.Ascendingsort();


alist.Print();
}

