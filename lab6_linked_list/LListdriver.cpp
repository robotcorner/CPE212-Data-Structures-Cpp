// STEPHEN STAMMEN
// JAKOB HENSON
//a driver for testing of the LList class

#include "LList.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

#define MAX 10

main()
{
  ItemType randomitem;  
  LList alist; 
  
  srand(time(NULL));
  
  // Zero elements shouldn't work at all
  alist.AscendingSort();    // EMPTY LIST TEST
  alist.Print();

  //test on a list with one item  
  alist.InsertasFirst(0);
  alist.AscendingSort();   

  // test it on a list with many items
  // insert a20 random items   
  for(int i=0;i<MAX;i++)
  {  
      randomitem = (int) (rand() % 100);
      alist.InsertasFirst(randomitem);
  }
  alist.Print();
  alist.AscendingSort();
  alist.Print();
}

