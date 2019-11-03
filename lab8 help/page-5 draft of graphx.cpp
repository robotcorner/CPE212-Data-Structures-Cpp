#include<string>
#include "graphx.h"
#include <iostream>
#include "LList.h"
using namespace std;

//   this is not too elegant
//   it creates an array of 2 million linked lists
//   it will work for this data set 
//   but probably is not too good when not all nodes exist

  LList  my_array[2000000];

template<class VertexType>
GraphXType<VertexType>::GraphXType()
// Post: Arrays of size 50 are dynamically allocated for
//       marks and vertices. numVertices is set to 0;
//       maxVertices is set to 50.
{
  int i;
  numVertices = 0;
  maxVertices = 50;
  marks = new bool[50];
  count = new int[50];

  for (i=0;i<maxVertices;i++)  marks[i] = 0;
  for (i=0;i<maxVertices;i++)  count[i] = 0;
}


template<class VertexType>
GraphXType<VertexType>::GraphXType(int maxV)
// Post: Arrays of size maxV are dynamically allocated for
//       marks and vertices.
//       numVertices is set to 0; maxVertices is set to maxV.
{
  int i;
  numVertices = 0;
  maxVertices = maxV;
  marks = new bool[maxV];
  count = new int[maxV];

  for (i=0;i<maxVertices;i++)   marks[i] = 0;
  for (i=0;i<maxVertices;i++)   count[i] = 0;
}

template<class VertexType>
GraphXType<VertexType>::~GraphXType()
// Post: Arrays for vertices and marks have been deallocated.
{
//  delete [] vertices;
  delete [] marks;
  delete [] count;
//  delete [] list_array;
}

 const int NULL_EDGE = 0;

/*****************************************/
/*****************************************/
/*  no need for AddVertex as all vertex names are numbers 0,1,2,3,  */

//template<class VertexType>
//void GraphXType<VertexType>::AddVertex(VertexType vertex)

//
//  no need for Indexis as all vertices are numbers 
//template<class VertexType>
//int GraphXType<VertexType>::IndexIs(VertexType* vertices, VertexType vertex)

template<class VertexType>  /* partly  fixed for 2M vertices */
  void GraphXType<VertexType>::AddEdge(VertexType fromVertex, VertexType toVertex, int weight)
// Post: Edge (fromVertex, toVertex) is stored in edges.
{
/* for now we will only add to count */
   count[fromVertex] ++;
//   cout << " count at vertex " << fromVertex << "is " << count[fromVertex] << endl;
// this is where YOU add the to node to the linked list for this from node 
    my_array[fromVertex].InsertasFirst(toVertex);
/* we need to // add a linked list element at the fromVertex list for toVertex */
}


//
// no need for this as all weights are 1 
//

//template<class VertexType>
//int GraphXType<VertexType>::WeightIs(VertexType fromVertex, VertexType toVertex)


/*   this might work if GetoVertices is fixed    */
/*
template<class VertexType>
void GraphXType<VertexType>::DepthFirstSearch(GraphXType<VertexType> graph, VertexType startVertex, VertexType endVertex)
// Assumes VertexType is a type for which the "==" and "<<"
// operators are defined
{
  using namespace std;
  Stack stack;
  Queue vertexQ;

  bool found = false;

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

/*  This might work if GetToVertices is fixed */
template<class VertexType>
void GraphXType<VertexType>::BreadthFirstSearch(GraphXType<VertexType> graph, VertexType startVertex, VertexType endVertex)
// Assumption: VertexType is a type for which the "==" and "<<" operators are defined.
{
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

template<class VertexType>
void GraphXType<VertexType>::ClearMarks()
{
  for (int i = 0; i < numVertices; i++)
  {
    marks[i] = false;
  } 
}

template<class VertexType>
void GraphXType<VertexType>::MarkVertex(VertexType vertex)
//
{
      marks[vertex] = true;
}

template<class VertexType>
bool GraphXType<VertexType>::IsMarked(VertexType vertex)
{
      return (marks[vertex]);

}

// Needs rewrite because edges is replaced by a linked list
//  also index is no longer needed as all vertices are numberical values now
/*
template<class VertexType>
void GraphXType<VertexType>::ShortestPath(VertexType startVertex, VertexType endVertex, Queue& path)
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
void  GraphXType<VertexType>::MaxNode()
{
// chose the first node as the max 
int i;
int max = count[0];
int maxnodex = 0;
for(i=0;i<maxVertices;i++)
{
if(max < count[i])
    {
    max = count[i];
    maxnodex = i;
    }
}
    cout << "max node was " << maxnodex << " max count was " << max << endl;
 return ;

}

