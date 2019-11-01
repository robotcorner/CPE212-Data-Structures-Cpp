#include <iostream>
#include <cstdlib>
#include "graph.h"
#include <fstream>
#include <string>

// USES A MATRIX, MAKE IT NOT USE THAT MATRIX

using namespace std;

int main(int argc, char** argv)
{
  const int MAX_V = 25;
  if (argc != 3) {
    cout << "./graph_driver input_filename output_filename\n";
    return 1; //break
  }
  ifstream input(argv[1]); // blindly open files
  ofstream output(argv[2]);
  
  GraphType<int> charGraph(MAX_V); // set max input for vertices as 100 for testing

  // Read input in batches
  // charGraph.AddVertex
  int v, w, i = 0;
  while (i < MAX_V) {
    if(!(i%2)) { // i is even (left collumn)
      input >> v;
      cout << "vertex: " << v << endl;
      charGraph.AddVertex(v);
    } else { // i is odd
      input >> w; //edge weight (right collumn)
      cout << "edge: " << w << endl << endl;
      //charGraph.AddEdge(v, /*toVertex,*/ w);
    }
    i++;
  }
   
  // output if we need to
}

/* MORE NOTES
# Directed graph (each unordered pair of nodes is saved once): roadNet-CA.txt 
# California road network
# Nodes: 1965206 Edges: 5533214
# FromNodeId	ToNodeId

[{1,2,469},{469,0,385}, ]
//   0         1  

*/

/* ================= NOTES ==================================
MODIFIY THE ADD VERTEX GRAPH

VERY SPARSE DATA SET
OUR DATA DOESN'T HAVE WEIGHTS
MARK NODE TO MAKE SURE YOU DON'T REPROCESS THE SAME NODE.

GIVEN CODE FOR AN ADJACENCY MATRIX (USUALLY FOR DENSE GRAPHS)

NEED TO USE SOMETHING LIKE ADJACENCY LIST OR EDGE LIST INSTEAD PROBABLY

SUGGEST THAT WE DO AN ADJACENY LIST, BUT DON'T HAVE TO
BIDIRECTIONAL DATA

FIRST FEW LINES TELL YOU HOW MANY NODES THAT THERE ARE

DON'T HAVE TO USE 2 DIRECTIONS, USED METHOD ONE FROM THE SLIDES.

EDGE LIST
- ARCS POINT TO THE NODES
- NOT VERY USEFUL FOR GEOGRAPHIC DATA
- HOW MANY WAYS YOU CAN TRAVERSE GRAPH

THE TEMPLETE <class VertexType> allow the class builder to 
class<bracket>  // what type of class that you want to use
classname<int>  // generates code for that class for integer arguments
                // this class will handle any of those datatypes

Before templeted classes, used typedef

TEMPLATE OF THE CLASS ALLOWS YOU TO NOT RE-WRITE THE LIBRARY MULTIPLE TIMES
C++ LIBRARIES ARE TEMPLETED WHICH IS WHY THEY ARE VERY VERSATILE.

NAMES ARE 0-1.7 MILLION

PREBUILD 1.7 NODES / VERTEX / VERTICES

FIRST VALUE = NODE / VERTEX
2ND VALUE = FRIST VALUE->2ND VALUE

FIRST VALUE AGAIN, ADD ONTHER VALUE TO THAT VERTEX

ADJACENCY LIST  = EACH ROW REPLACED WITHA LINKED LIST
                = 1 DIM ARRAY = EACH NODE = IT'S OWN LINKED LIST

GREEDY ALGRORITHM - LOCAL BEST DECISION

TAKE THE DATA GIVEN AND ATTEMPT WITH THE FIRST 100 LINES OR SO INSTEAD WHEN TESTING

DECLARE USING NEW STRUCTURE OPERATION OR DECLARE OUTSIDE THE BODY OF THE CODE.

COUNT THE NUMBER OF ENTRIES, ADD ONE TO THE COUNT EVERY TIME YOU ADD ONE.

SOME CODE IS ON THE SLIDES FRO COUNTING THE NODES AND FOR ADDING AN ARC TO THE GRAPH

DO NOT WALK THE LINKED LIST
WALK THE ARRAY AND DETERMIN WHICH IS THE MINIMUM, IF NUM < 10000 MAKE MIN = 1, HAVE INDEX OF NODE WITH THE SMALLEST NUMBER OF ENTRIES

// vertex in the old code will need to be replace with the new code that references the names

// need code of templated class int he driver file so that it knows what kind of code to generate.
 can't generate code for a structure if it doens't know what to include.
 #include "graph.cpp" in the driver file

 Edges is walking through a row in a matrix
*/
