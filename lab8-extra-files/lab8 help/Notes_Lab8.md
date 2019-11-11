# Lab 8 Notes

* The original code was set up for an ajacency matrix which should be used for more dense graphs than this one with also less data.

* California road network
* This is a Bi-Directed graph (each unordered pair of nodes is saved once)
* This is a very sparse data set
* Our data does not have weights
* We Know:
  * Nodes: 1965206
  * Edges: 5533214
  * Format: FromNodeId      ToNodeId

```C++
[LList1, LList2, LList3]
[{1,2,469},{469,0,385}, ...]
      0         1  
```

## To-Do
* [ ] Add the LinkedList File
* [ ] Modify the AddVertex Graph
      * [ ] vertex in the old code will need to be replace with the new code that references the names
* [ ] Mark each node to make sure you don't process the same node.
* [ ] Each row should be replaced with a linked list
* [ ] Attempt the problem with the first 100 values or so for testing initially.
* [ ] Count the number of entries, add one to the count every time you add an entry.
* [ ] can't generate code for a structure if it doens't know what to include. #include "graph.cpp" in the driver file

**Constructor**

```C++
{
  numVertices = 0;
  maxVertices = maxV;
  marks = new bool[maxV];
  count = new int[maxV];

  for(int i = 0; i < maxVertices; i++)
      marks[i] = 0;
  for(int i = 0; i < maxVertices; i++)
      count[i] = 0;
}
```

**Constructor**

```C++
template<class VertexType>
GraphType<VertexType>::GraphType()
// Post: Arrays of size 50 are dynamically allocated for
//       marks and vertices. numVertices is set to 0;
//       maxVertices is set to 50.
{
  numVertices = 0;
  maxVertices = 50;
  vertices = new VertexType[50];
  marks = new bool[50];
  count = new int[50];
  
  for(int i = 0; i < maxVertices; i++)
      marks[i] = 0;
  for(int i = 0; i < maxVertices; i++)
      count[i] = 0;
}

template<class VertexType>
GraphType<VertexType>::GraphType(int maxV)
// Post: Arrays of size maxV are dynamically allocated for
//       marks and vertices.
//       numVertices is set to 0; maxVertices is set to maxV.
{
  numVertices = 0;
  maxVertices = maxV;
  marks = new bool[maxV];
  count = new int[maxV];

  for(int i = 0; i < maxVertices; i++)
      marks[i] = 0;
  for(int i = 0; i < maxVertices; i++)
      count[i] = 0;
}
```

## Other Notes

### Class Templates

```C++
<class VertexType> allow the class builder to 
class<bracket>  // what type of class that you want to use
classname<int>  // generates code for that class for integer arguments
                // this class will handle any of those datatypes
```

* Templates of classes allow you to not have to write the class library multiple types for all the ItemTypes (ints, floats, bools, doubles)
* C++ Libraries are templated, which is why they are very versatile

### Adjacency List

* Each row is replaced with a linked list

```C++
[0] -> [11][pointer1] -> [200][pointer2]
```

* Do NOT Walk the Linked List
* Walk the Array and Determine which is the Minimum
* If num < 10000 , make min = 1 have the index of the node with the smallest number of entries

### Edge List

* arcs point to the nodes
* not very useful for geographic data, slow
* good to know all the ways you could traverse the graph

### Random

* Before templeted classes, used typedef
* Greedy Algorithms, make the local best descision
