#ifndef GRAPH_H
#define GRAPH_H

// Forward declaration of ItemType
typedef char ItemType;

#include "queue.h"
#include "stack.h"
#include <iostream>
#include <string>


template<class VertexType>
// Assumption: VertexType is a type for which the "=", "==", and "<<" are defined
// graph of ints, floats or characters works by default, but if you wanted to have a graph of data structrures then you need to define these.
class GraphType
{
  private:
    int currentVertex;
    int maxVertices;
    VertexType* vertices; // implemented as array (possibly)
    int edges[50][50]; //2d 2500 elements
    bool* marks; // marks[i] is mark for vertices[i].
  public:
    GraphType();
    GraphType(int maxV);
    ~GraphType();
    void MakeEmpty();
    bool IsEmpty() const;
    bool IsFull() const;
    void AddVertex(VertexType);
    void AddEdge(VertexType, VertexType, int);
    int WeightIs(VertexType, VertexType);
    int IndexIs(VertexType* vertices, VertexType vertex);
    void GetToVertices(VertexType, Queue&);
    void ClearMarks();
    void MarkVertex(VertexType);
    bool IsMarked(VertexType);
    void DepthFirstSearch(GraphType<VertexType> graph, VertexType startVertex, VertexType endVertex);
    void BreadthFirstSearch(GraphType<VertexType> graph, VertexType startVertex, VertexType endVertex);
    void ShortestPath(VertexType startVertex, VertexType endVertex, Queue& path);   
};
#include "graph.cpp"

#endif
