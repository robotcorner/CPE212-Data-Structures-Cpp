#include<string>
// #include "LList.h"    // needed
#include <iostream>

template<class VertexType>
GraphType<VertexType>::GraphType()
// Post: Arrays of size 50 are dynamically allocated for
//       marks and vertices. currentVertex is set to 0;
//       maxVertices is set to 50.
{
  currentVertex = 0;
  maxVertices = 50;
  vertices = new VertexType[50];
  marks = new bool[50];
}

template<class VertexType>
GraphType<VertexType>::GraphType(int maxV)
// Post: Arrays of size maxV are dynamically allocated for
//       marks and vertices.
//       currentVertex is set to 0; maxVertices is set to maxV.
{
  currentVertex = 0;
  maxVertices = maxV;
  vertices = new VertexType[maxV];
  marks = new bool[maxV];
}

template<class VertexType>
GraphType<VertexType>::~GraphType()
// Post: Arrays for vertices and marks have been deallocated.
{
  delete [] vertices;
  delete [] marks;
}

const int NULL_EDGE = 0;

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

template<class VertexType>
int GraphType<VertexType>::IndexIs(VertexType* vertices, VertexType vertex)
{
  int index = 0;

  while (!(vertex == vertices[index]))
    index++;
  return index; // Returns the index of vertex in vertices.
}

template<class VertexType>
void GraphType<VertexType>::AddEdge(VertexType fromVertex, VertexType toVertex, int weight)
// Post: Edge (fromVertex, toVertex) is stored in edges.
{
  int row;
  int col;

  // ADD NODE TO GRAPH WITH VALUE
  // MODIFY SOMETHING RIGHT HERE

  // THIS TRANSLATES THE NAME INTO AN INTEGER - REMOVE IT
  row = IndexIs(vertices, fromVertex);
  col = IndexIs(vertices, toVertex);

  // REPLACED BY AN OPERATION THAT ADDS AND ELEMENT TO A LINKED LIST
  // ROW REPACED WITH LINKED LIST  
  edges[row][col] = weight; // putting the weights in the edges
}

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

template<class VertexType>
void GraphType<VertexType>::GetToVertices(VertexType vertex, Queue& adjVertices)
{
  int fromIndex;
  int toIndex;

  // REPLACE THE BELOW WITH CODE THAT WALKS THROUGH THE LINKED LIST.  
  fromIndex = IndexIs(vertices, vertex);
  for (toIndex = 0; toIndex < currentVertex; toIndex++)
    if (edges[fromIndex][toIndex] != NULL_EDGE)
      adjVertices.Enqueue(vertices[toIndex]);

  

}

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

template<class VertexType>
void GraphType<VertexType>::ClearMarks()
{
  for (int i = 0; i < currentVertex; i++)
  {
    marks[i] = false;
  } 
}

template<class VertexType>
void GraphType<VertexType>::MarkVertex(VertexType vertex) //marks vertex when its passed in the search
{
  for (int i = 0; i < currentVertex; i++)
  {
    if (vertex == vertices[i])
    {
      marks[i] = true;
    }
  } 
}

template<class VertexType>
bool GraphType<VertexType>::IsMarked(VertexType vertex) // checks if vertex is marked
{
  for (int i = 0; i < currentVertex; i++)
  {
    if (vertex == vertices[i])
    {
      return (marks[i]);
    }
  }

  return false; // Should never happen
}

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

// INCLUDE void MinNode(); // find one with the smallest number and largest number of outward arcs
// Include void MaxNode();
// can just return one of them
/*
#include "graphx.cpp"
#endif
*/
