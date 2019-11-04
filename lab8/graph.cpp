//#ifndef GRAPH_H
//#define GRAPH_H
//#include "graph.h"
//#include "LList.h"
#include <string>
#include <iostream>

using namespace std;

LList int_array[1965206];  // llist array of 2 million, not good when not all nodes exist

template<class VertexType>
// Assumption: VertexType is a type for which the "=", "==", 
// and "<<" are defined
GraphType<VertexType>::GraphType()
{
  int i;
  currentVertex = 0;
  maxVertices = 50;
  count = new int[50];
  marks = new bool[50]; // right? well see
  for (i = 0; i < maxVertices++; ++i) marks[i] = 0;
  for (i = 0; i < maxVertices++; ++i) count[i] = 0;
  // vertices = new VertexType[50];
}

template<class VertexType>
GraphType<VertexType>::GraphType(int max)
// Post: Arrays of size maxV are dynamically allocated for marks and vertices.
//       currentVertex is set to 0; maxVertices is set to maxV.
{
  int i;
  currentVertex = 0;
  maxVertices = max;  
  marks = new bool[max];
  count = new int[max];
  for (i = 0; i < maxVertices; ++i) marks[i] = 0;
  for (i = 0; i < maxVertices; ++i) count[i] = 0;  
  // vertices = new VertexType[maxV];

}

template<class VertexType>
GraphType<VertexType>::~GraphType()
// Post: Arrays for vertices and marks have been deallocated.
{
  // delete [] vertices;
  delete [] marks;
  delete [] count;
  // delete [] int_array;
}

const int NULL_EDGE = 0;

/*****************************************/
// NO NEED for AddVertex as all vertex names are numbers 0,1,2,3,  */
/*

template<class VertexType>
void GraphType<VertexType>::AddVertex(VertexType vertex)
// Post: Vertex has been stored in vertices.
//       Corresponding row and column of edges has been set
//       to NULL_EDGE.
//       currentVertex has been incremented.
{
  vertices[currentVertex] = vertex;

  // Looks through edges and finds a null edge.
  for (int index = 0; index < currentVertex; index++)
  {
    edges[currentVertex][index] = NULL_EDGE;
    edges[index][currentVertex] = NULL_EDGE;
  }
  currentVertex++;
}

*/

/*****************************************/
// NO NEED for AddVertex as all vertex names are numbers 0,1,2,3,  */
/*

template<class VertexType>
int GraphType<VertexType>::IndexIs(VertexType* vertices, VertexType vertex)
{
  int index = 0;

  while (!(vertex == vertices[index]))
    index++;
  return index; // Returns the index of vertex in vertices.
}

*/

template<class VertexType>
void GraphType<VertexType>::AddEdge(VertexType fromVertex, VertexType toVertex, int weight)
// Post: Edge (fromVertex, toVertex) is stored in edges.
{
  // THIS TRANSLATES THE NAME INTO AN INTEGER - comment it
  // int row;
  // int col;
  // row = IndexIs(vertices, fromVertex);
  // col = IndexIs(vertices, toVertex);
  // edges[row][col] = weight; // putting the weights in the edges

  count[fromVertex] ++; // add to the count

// TODO: Modify Stuff Here
// ---- Add the node to the linked list for this from Node
// add a linked list element at the fromVertex list for toVertex
  int_array[fromVertex].InsertasFirst(toVertex);
}

/* ---- ALL THE WEIGHTS ARE 1 ----------------------

template<class VertexType>
int GraphType<VertexType>::WeightIs(VertexType fromVertex, VertexType toVertex)
// Post: Returns the weight associated with the edge
//       (fromVertex, toVertex).
{
  int row;
  int col;

  row = IndexIs(vertices, fromVertex);
  col = IndexIs(vertices, toVertex);
  return edges[row][col]; // check the weight in the edge
}
*/

// TODO: WILL NEED TO HANDLE INTEGERS INSTEAD OF NAMES - NO HELP PROVIDED
/*template<class VertexType>
void GraphType<VertexType>::GetToVertices(VertexType vertex, Queue& adjVertices)
{
  int fromIndex;
  int toIndex;

  // REPLACE THE BELOW WITH CODE THAT WALKS THROUGH THE LINKED LIST.  
  fromIndex = IndexIs(vertices, vertex);
  for (toIndex = 0; toIndex < currentVertex; toIndex++)
    if (edges[fromIndex][toIndex] != NULL_EDGE)
      adjVertices.Enqueue(vertices[toIndex]);
}*/

// TODO: DepthFirstSearch WILL NOT WORK UNTIL GetToVertices IS FIXED
/*
template<class VertexType>
void GraphType<VertexType>::DepthFirstSearch(GraphType<VertexType> graph, VertexType startVertex, VertexType endVertex)
// Assumes VertexType is a type for which the "==" and "<<"
// operators are defined
{
  // Couts vertecies along the path. depth 1st
  using namespace std;
  Stack stack;
  Queue vertexQ;

  bool found = false;
  VertexType vertex;
  VertexType item;

  graph.ClearMarks();
  stack.Push(startVertex);
  do
  {
    stack.Pop(vertex);
    if (vertex == endVertex)
    {
      cout << vertex;
      found = true;
    }
    else
    {
      if (!graph.IsMarked(vertex))
      {
        graph.MarkVertex(vertex);
        cout << vertex;
        graph.GetToVertices(vertex, vertexQ);

        while (!vertexQ.IsEmpty())
        {
          vertexQ.Dequeue(item);
          if (!graph.IsMarked(item))
            stack.Push(item);
        }
      }
    }
  } while (!stack.IsEmpty() && !found);
  if (!found)
    cout << "Path not found." << endl;
}
*/

/* TODO: MIHGT WORK if GetToVertices IS FIXED

template<class VertexType>
void GraphType<VertexType>::BreadthFirstSearch(GraphType<VertexType> graph, VertexType startVertex, VertexType endVertex)
// Assumption: VertexType is a type for which the "==" and "<<" operators are defined.
{
  // Couts vertecies along the path. breadth 1st
  using namespace std;
  Queue queue;
  Queue vertexQ;

  bool found = false;
  VertexType vertex;
  VertexType item;
  graph.ClearMarks();
  queue.Enqueue(startVertex);

  do
  {
    queue.Dequeue(vertex);

    if (vertex == endVertex)
    {
      cout << vertex;
      found = true;
    }
    else
    {
      if (!graph.IsMarked(vertex))
      {
        graph.MarkVertex(vertex);
        cout << vertex;
        graph.GetToVertices(vertex, vertexQ);

        while (!vertexQ.IsEmpty())
        {
          vertexQ.Dequeue(item);
          if (!graph.IsMarked(item))
            queue.Enqueue(item);
        }
      }
    }
  } while (!queue.IsEmpty() && found);
  if (!found)
    cout << "Path not found." << endl;
}
*/

/*template<class VertexType>
void GraphType<VertexType>::ClearMarks()
{
  for (int i = 0; i < currentVertex; i++)
  {
    marks[i] = false;
  } 
}*/

/*template<class VertexType>
void GraphType<VertexType>::MarkVertex(VertexType vertex) //marks vertex when its passed in the search
{
  marks[vertex] = true;
  // OLD CODE
  /* for (int i = 0; i < currentVertex; i++)
  {
    if (vertex == vertices[i])
    {
      marks[i] = true;
    }
  }
  
}*/

/*template<class VertexType>
bool GraphType<VertexType>::IsMarked(VertexType vertex) // checks if vertex is marked
{
  return(marks[vertex]);
  // OLD CODE
  /* for (int i = 0; i < currentVertex; i++)
  {
    if (vertex == vertices[i])
    {
      return (marks[i]);
    }
  }
  
  // return false; // Should never happen
}*/

// TODO: 
// Needs rewrite because edges is replaced by a linked list
//  also index is no longer needed as all vertice
/*
template<class VertexType>
void GraphType<VertexType>::ShortestPath(VertexType startVertex, VertexType endVertex, Queue& path)
{
  using namespace std;
  Queue queue;
  Queue vertexQ;

  bool found = false;
  VertexType vertex;
  VertexType item;
  ClearMarks();
  queue.Enqueue(startVertex);

  do
  {
    queue.Dequeue(vertex);
    int vertexIndex = IndexIs(vertices, vertex);
    int endVertexIndex = IndexIs(vertices, endVertex);
    if (vertex == endVertex)
    {
      path.Enqueue(vertex);
      found = true;
    }
    else if (edges[vertexIndex][endVertexIndex] != NULL_EDGE)
    {
      path.Enqueue(vertex);
      path.Enqueue(endVertex);
      found = true;
    }
    else
    {
      if (!IsMarked(vertex))
      {
        MarkVertex(vertex);
        path.Enqueue(vertex);
        GetToVertices(vertex, vertexQ);
        while (!vertexQ.IsEmpty())
        {
          vertexQ.Dequeue(item);
          if (!IsMarked(item))
          {
            queue.Enqueue(item);
          }
        }
      }
    }
  } while (!queue.IsEmpty() && !found);
  if (!found)
  {
    cout << "Path not found." << endl;
    path.MakeEmpty();
    return;
  }
}
*/

template<class VertexType>
void GraphType<VertexType>::MaxNode() {
  // chose the first node as the max 
  int i;
  int max = count[0];
  int maxnodex = 0;
  for(i = 0; i < maxVertices; i++) {
    if(max < count[i]) {
      max = count[i];
      maxnodex = i;
    }
  }
  cout << "max node was " << maxnodex << " max count was " << max << endl;
}

// INCLUDE void MinNode(); 
// find one with the smallest number and largest number of outward arcs
// can just return one of them


// TODO: Fix the logic inside this
template<class VertexType>
void GraphType<VertexType>::MinNode() {
  // chose the first node as the min
  int i;
  int min = count[0];
  int minNode = 0;
  for(i = 0; i < maxVertices; i++) {
    /*
    if(min < count[i]) {
      min = count[i];
      minNode = i;
    }
    */
    if((count[i]) == 1)
    {
      min = count[i];
      minNode = i;
    }
  }
  cout << "Min node was " << minNode << " Min count was " << min << endl;
}
//#endif
