#include <iostream>
#include <cstdlib>
#include "graph.h"
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
  const int MAX_V = 100;  // Set to 2000000 later
  
  if (argc != 3) {
    cout << "./graph_driver input_filename output_filename\n";
    return 1; // break
  }

  ifstream input(argv[1]);
  ofstream output(argv[2]);
  
  GraphType<int> intGraph(MAX_V); // set max input for vertices as 100 for testing

  int arcLength = 1; // Weight = ArcLength
  int vFrom, vTo, i = 0;

  cout << "Starting the Graph by List Program" << endl;

  // Test 1
  input >> vFrom >> vTo;
  cout << "vfrom: " << vFrom << " vTo: " << "\n";
  intGraph.AddEdge(vFrom, vTo, arcLength);

  // Test 2
  input >> vFrom >> vTo;
  cout << "vfrom: " << vFrom << " vTo: " << "\n";
  intGraph.AddEdge(vFrom, vTo, arcLength);

  // Test 3
  input >> vFrom >> vTo;
  cout << "vfrom: " << vFrom << " vTo: " << "\n";
  intGraph.AddEdge(vFrom, vTo, arcLength);

  for(i=0; i<MAX_V; i++)
  while (i < MAX_V) {
    input >> vFrom >> vTo;
    intGraph.AddEdge(vFrom, vTo, arcLength);
    //charGraph.AddEdge(v, /*toVertex,*/ w);
    i++;
  }
  cout << endl;
  // cout << "Max Node Value is: " << intGraph.MaxNode() << endl;
  cout << "Min Node Value is: " << intGraph.MinNode() << endl; // Node with smallest number of edges / connections
  
  return 0;
}

