// ---- Keeps Compiler from Redefining Things -------------
#ifndef GRAPH_H
#define GRAPH_H

// Forward declaration of ItemType
typedef int ItemType;

#include "queue.h"
#include "stack.h"
#include <iostream>
#include "LList.h"  
#include <string>

template<class VertexType>
// Assumption: VertexType is a type for which the "=", "==", and "<<" are defined
// graph of ints, floats or characters works by default, but if you wanted to have a graph of data structrures then you need to define these.

class GraphType
{
  private:
    int currentVertex;
    int maxVertices;
    int* count;  // count[i] is count of length if this node's linked list
    bool* marks; // marks[i] is mark for vertices[i].

    // Won't Use
    //VertexType* vertices; // implemented as array (possibly)    
    //int edges[50][50]; //2d 2500 elements

  public:
    GraphType();
    GraphType(int);
    ~GraphType();
    void MakeEmpty();
    bool IsEmpty() const;
    bool IsFull() const;
    //void AddVertex(VertexType);
    void AddEdge(VertexType, VertexType, int);
    //int WeightIs(VertexType, VertexType);
    //int IndexIs(VertexType* vertices, VertexType vertex);
    //void GetToVertices(VertexType, Queue&);  // Needs Fixed if want Searching
    //void ClearMarks();    // Fix this
    //void MarkVertex(VertexType);    // Fix this
    //bool IsMarked(VertexType);    // Fix this
    //void DepthFirstSearch(GraphType<VertexType> graph, VertexType startVertex, VertexType endVertex); // Fix this
    //void BreadthFirstSearch(GraphType<VertexType> graph, VertexType startVertex, VertexType endVertex); // Fix this
    //void ShortestPath(VertexType startVertex, VertexType endVertex, Queue& path); // Fix this   
    void MaxNode();  // Find the maxiumum number of connections to a node
    void MinNode();  // Find the minimum number of connections to a node
};

#include "graph.cpp"
#endif
