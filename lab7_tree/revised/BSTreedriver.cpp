#include <string>
#include <iostream>
#include <fstream>
#include "BSTree.h"
#include <ctime>
#include <cstdlib>
#include <time.h>

using namespace std;

//
// When you finish the project This program should  
//1- find out what time it is now (call this t1)
//   use "man 2 time" to find out how the time function works 
//   if you are very interested there are much finer timers in linux but seconds should do

//2- compute MAX1 random numbers and store them in a BSTree using
//   the code below.  The Insert function provided does not enter duplicate numbers.
//   choose a value for MAX that takes about 10 seconds to process - 100000 may work

//3- find out what time it is now and call this time t2
//   Determine how long it takes to store X numbers in the BSTree by computing t2-t1 
//   record these values. 

//4- write a new method for BSTree that determines whether a number is present or absent in the tree
//   you should start with the Insert method code which traverses the tree and rejects any duplicates
//   in the tree.  Modify the code to NOT make any entries in the tree and just report if 
//   the value you are searching for has been found.  You should probably use the same seed as you 
//   used for the data values or there may be no values found at all.

//5- compute MAX2 random numbers and search for them in 
//     the BSTree you built earlier. Using the techniques mastered in steps 1-3
//     determine how long it takes to search for MAX2 random numbers.  Chose a value for 
//     MAX2 that takes about 10 seconds to process.  Record these values

//6- repeat steps  1-5 for at least one data structure you have studied earlier in the term. You 
//   may  want to try two different data structures, one sorted and one unsorted.  
//   You will probably have to choose different values for MAX1 and MAX2 for some structures if
//   you hope to return the results by graduation.  Record these values
// -- linked list maybe, stacks, queues. report numbers stored and how much time.
// also search and do the same thing.

//   upload a tar file with your all your codes together with a short report containing the experiment 
//   values you determined above.  Run each experiment 5 times and report back each of the 5 measurments

// tar file + report

//#define MAX 100000
#define MAX 10




int main()
{
time_t t1 = time(0);
// Create BSTree  Tree 
  TreeType studentNameTree; 

cout << "starting tree driver " << endl;


// this code just stores 10 numbers in the tree from 0 to 9

for(int i=0;i<MAX;i++)
     studentNameTree.InsertItem( i);

// this code just stores 10 duplicate numbers in the tree from 0 to 9

for(int i=0;i<MAX;i++)
     studentNameTree.InsertItem( i);

// this code just prints out the tree.  Probably don't do this for 1000000 node trees but good
//   to see if your code works

studentNameTree.PrintItem();
time_t t2=time(0);
time_t ttotal = t2-t1;
cout << endl << ttotal;
}

