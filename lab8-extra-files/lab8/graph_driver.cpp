#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

//#ifndef GRAPH_H
//#define GRAPH_H
#include "graph.h"

using namespace std;
//int main(int argc, char** argv)
int main() 
{
  const int MAX_V = 1965206;  // We have 1965206 Nodes
  /*if (argc != 3) {
    cout << "./graph_driver input_filename output_filename\n";
    return 1; // break
  }
  
  ifstream input(argv[1]);
  ofstream output(argv[2]);
  */

  ifstream input;
  ofstream output;
  input.open("words2xx.txt");
  output.open("out1.txt");
  
  cout << "things work here" << endl;
  cout << "both gdb and valgrind don't determine the problem" << endl;
  GraphType<int> intGraph(MAX_V); // set max input for vertices as 100 for testing
  cout << "things don't work here" << endl;
  
  int arcLength = 1; // Weight = ArcLength
  int vFrom, vTo, i = 0;

  cout << "Starting the Graph by List Program" << endl;

  // Test 1
  input >> vFrom >> vTo;
  cout << "vfrom: " << vFrom << " vTo: " << "\n";
  //intGraph.AddEdge(vFrom, vTo, arcLength);

  // Test 2
  input >> vFrom >> vTo;
  cout << "vfrom: " << vFrom << " vTo: " << "\n";
  //intGraph.AddEdge(vFrom, vTo, arcLength);

  // Test 3
  input >> vFrom >> vTo;
  cout << "vfrom: " << vFrom << " vTo: " << "\n";
  //intGraph.AddEdge(vFrom, vTo, arcLength);

  for(i=0; i<MAX_V; i++)
  {
    input >> vFrom >> vTo;
    //intGraph.AddEdge(vFrom, vTo, arcLength);
    //intGraph.AddEdge(v, /*toVertex,*/ w);
  }
  cout << endl;
  //cout << "Max Node Value is: " << intGraph.MaxNode() << endl;
  cout << "Min Node Value is: "; // Node with smallest number of edges / connections
  //intGraph.MinNode();
  output.close();
  input.close();
  cout << endl;
  return 0;
}

//#endif
