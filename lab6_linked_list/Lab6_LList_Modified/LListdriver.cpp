//a driver for testing of the LList class

#include "LList.h"
#include <iostream>
#include <fstream>

using namespace std;

LList alist;

int main()
{
	cout<<"starting: \nadding first item:\n";
	alist.InsertasFirst(3);

	ItemType entry;
	
	cout<<"testing insert function:\n";
	for(int i=0; i<=6; i++)
	{
		item=i;
		alist.Insert(entry);
	}
	alist.Print();

	cout<<"testing removal of first item:\n";
	alist.Delete(0);
	alist.Print();
	
	cout<<"testing removal of item in list:\n";
	alist.Delete(3);
	alist.Print();
	
	cout<<"testing removal of last item in list:\n";
	alist.Delete(6);
	alist.Print();
	
	cout<<"testing attempted removal of item not in list:\n";
	alist.Delete(6);
	alist.Print();
	
	cout<<"testing removal of entire list:\n";
	for(int i=1; i<6; i++)
	{
		item=i;
		alist.Delete(entry);
	}
	alist.Print();
	
	alist.InsertasFirst(5);
	alist.Print();
	alist.InsertasFirst(3);
	alist.Print();
	alist.Insert(4);
	alist.Print();
	return 0;
}
