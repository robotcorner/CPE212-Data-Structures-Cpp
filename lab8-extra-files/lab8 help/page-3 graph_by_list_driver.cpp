#include <iostream>
#include "graph.h"

using namespace std;

int main()
{

// note that we are going to declare at the beginning the space for the vertex array
//  this declares an instance of the graphx class of size 2000000.
//  it might be better to grow one as new nodes are found but this is within
//  the requirements
GraphXType<int>  mygraph(2000000);

// declare variables used by the driver progra
int vfrom;
int  vto;
// this program is run as ./graph_by_list_driver <words2xx
//  it would be better to read in the file name 
//  and open it within the driver file. I just 
//  redirected it to cin

// set the default arc length to 1
int ArcLength = 1;

// tell the user the program is starting
cout << "starting graph by list " << endl;

// read three items to ensure reading is ok and the class does not crash
// just inform the user the program is running ok with three nodes.
//  remove this code from the final product


// this code is very sloppy and does not check that the node numbers are 
//   between 0 and 2000000.  It would not be hard to crash this program with
//   say a node number like 4000000
cin >> vfrom >> vto ;
cout << "from vertex " << vfrom << "to vertex " << vto << endl;
mygraph.AddEdge (vfrom, vto, ArcLength);

cin >> vfrom >> vto ;
cout << "from vertex " << vfrom << "to vertex " << vto << endl;
mygraph.AddEdge(vfrom, vto, ArcLength);

cin >> vfrom >> vto ;
cout << "from vertex " << vfrom << "to vertex " << vto << endl;
mygraph.AddEdge(vfrom, vto, ArcLength);

// now for the heavy lifting read in the data file and put into the graph
// we should read in until cin reaches end of file but this is quick
for(int i = 0;i<1000000;i++)
{
cin >> vfrom >> vto ;
//cout << "from vertex " << vfrom << "to vertex " << vto << endl;
mygraph.AddEdge (vfrom, vto, ArcLength);
}


// at the end print out the node with the maximum number of edges
//    and the actual edge count

mygraph.MaxNode();

// at the end print out the node with the smallest number of edges 
//     and the actual edge count

//  	mygraph.MinNode(); 
}
