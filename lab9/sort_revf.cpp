// Stephen Stammen and Jakob
#define DEBUG 0
#define SIZE 5000//000
#include <stdlib.h>
#include <iostream>
#include <sys/time.h>
#include <unistd.h>
#include <fstream>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

// Purpose: ?
void Swap(int& item1, int& item2)
// Post: Contents of item1 and item2 have been swapped
// Does this need dynamic?
{
  int tempItem;
  tempItem = item1;
  item1 = item2;
  item2 = tempItem;
}

// Purpose: To be used by the Bubble Sort Algorithm
void BubbleUp(int values[], int startindexVal, int endindexVal)
// Post: Adjacent pairs that are out of order have been 
//       switched between values[startindexVal]..values[endindexVal]
//       beginning at values[endindexVal].
{
  for (int indexVal = endindexVal; indexVal > startindexVal; indexVal--)
    if (values[indexVal] < values[indexVal-1])
      Swap(values[indexVal], values[indexVal-1]);
}

// Purpose: Performs the Bubble Sort Algorithm on an Array
void BubbleSort(int values[], int numValues)
// Post: The elements in the array values are sorted by key.
{
  int current = 0;
  while (current < numValues - 1)
  {
    BubbleUp(values, current, numValues-1);
    current++;
  }
}

// Split
void Split(int values[], int first, int last, int& splitPoint)
{
  int splitVal = values[first];
  int saveFirst = first;
  bool onCorrectSide;

  first++;
  do
  {
    onCorrectSide = true;
    while (onCorrectSide)        	   // Move first toward last.
      if (values[first] > splitVal)
        onCorrectSide = false;
      else
      {  
        first++;
        onCorrectSide = (first <= last);
      }

    onCorrectSide = (first <= last);
    while (onCorrectSide)             // Move last toward first.
      if (values[last] <= splitVal)
        onCorrectSide = false;
      else
      {
        last--;
        onCorrectSide = (first <= last);
      }
   
    if (first < last)
    {
      Swap(values[first], values[last]);
      first++;
      last--;
    }
  } while (first <= last);

  splitPoint = last;
  Swap(values[saveFirst], values[splitPoint]);
}

// sort 

// QuickSort
void QuickSort(int values[], int first, int last)
{
  if (first < last)
  {
    int splitPoint;

    Split(values, first, last, splitPoint);
    // values[first]..values[splitPoint-1] <= splitVal
    // values[splitPoint] = splitVal
    // values[splitPoint+1]..values[last] > splitVal

    QuickSort(values, first, splitPoint-1);
    QuickSort(values, splitPoint+1, last);
  }
}

void Merge (int values[], int leftFirst, int leftLast, int rightFirst, int rightLast)
// Post: values[leftFirst]..values[leftLast] and values[rightFirst]..values[rightLast] have been merged.
//       values[leftFirst]..values[rightLast] is now sorted.
{
  int* tempArray = new int[SIZE*10];  // SIZE NOT SIZE * 10
  int index = leftFirst;
  int saveFirst = leftFirst;

#if DEBUG == 1 
  cout << " in Merge values were " << leftFirst << " " << leftLast << " " << rightFirst << " " << rightLast << endl;
#endif

  while ((leftFirst <= leftLast) && (rightFirst <= rightLast))
  {
    if (values[leftFirst] < values[rightFirst])	 
    {
      tempArray[index] = values[leftFirst];
      leftFirst++;
    }  
    else
    {
      tempArray[index] = values[rightFirst];
      rightFirst++;
    }
    index++;
   } 
  while (leftFirst <= leftLast)
  // Copy remaining items from left half.
  {
    tempArray[index] = values[leftFirst];
    leftFirst++;
    index++;
  }
  while (rightFirst <= rightLast)	
  // Copy remaining items from right half.
  {
    tempArray[index] = values[rightFirst];
    rightFirst++;
    index++;
  }


for (index = saveFirst; index <= rightLast; index++)
    {
#if DEBUG == 1 
  cout << "in copyout index and values are " << index << " " << tempArray[index] << endl;
#endif
    values[index] = tempArray[index];
    }

    delete [] tempArray;
}

void MergeSort(int values[], int first, int last)
// first = starting index
// last = ending index
// Post: The elements in values are sorted by key.
{

#if DEBUG == 1  
cout << " in MergeSort first last were " << first  << " " << last << endl;
#endif

  if (first < last)
  {
    int middle = (first + last) / 2;		// Calculate split index
    MergeSort(values, first, middle);		// Sort left half of array 
    MergeSort(values, middle + 1, last);		// Sort right half of array 
    Merge(values, first, middle, middle + 1, last); // Combine the sorted halves
  }

}

/*
// Purpose: To be used by the MergeSort Algorithm
void Merge (int values[], int leftFirst, int leftLast, int rightFirst, int rightLast)
// Post: values[leftFirst]..values[leftLast] and values[rightFirst]..values[rightLast] have been merged.
//       values[leftFirst]..values[rightLast] is now sorted.
{
  // Initializes Elements to the Function Arguments
  int* tempArray = new int[SIZE]; // CHANGED: Modified this from: in tempArray[SIZE]
  int indexVal = leftFirst;
  int saveFirst = leftFirst;

  #if DEBUG == 1 
    cout << " in Merge values were " << leftFirst << " " << leftLast << " " << rightFirst << " " << rightLast << endl;
  #endif

  // ? Whats this do below ? - Stephen
  while ((leftFirst <= leftLast) && (rightFirst <= rightLast))
  {
    if (values[leftFirst] < values[rightFirst])	 
    {
      tempArray[indexVal] = values[leftFirst];
      leftFirst++;
    }  
    else
    {
      tempArray[indexVal] = values[rightFirst];
      rightFirst++;
    }
    indexVal++;
  } 

  while (leftFirst <= leftLast)
  // Copy remaining items from left half.
  {
    tempArray[indexVal] = values[leftFirst];
    leftFirst++;
    indexVal++;
  }

  while (rightFirst <= rightLast)	
  // Copy remaining items from right half.
  {
    tempArray[indexVal] = values[rightFirst];
    rightFirst++;
    indexVal++;
  }

  for (indexVal = saveFirst; indexVal <= rightLast; indexVal++)
  {
    #if DEBUG == 1 
    cout << "in copyout indexVal and values are " << indexVal << " " << tempArray[indexVal] << endl;
    #endif
    values[indexVal] = tempArray[indexVal];
  }
  delete [] tempArray;
}

void MergeSort(int values[], int first, int last)
{
  #if DEBUG == 1  
  cout << " in MergeSort first last were " << first  << " " << last << endl;
  #endif

  if (first < last) // (starting indexVal < ending indexVal)
  {
    int middle = (first + last) / 2;		// Calculate split indexVal
    MergeSort(values, first, middle);		// Sort left half of array 
    MergeSort(values, middle + 1, last);		// Sort right half of array 
    Merge(values, first, middle, middle + 1, last); // Combine the sorted halves
  }
  // Post: The elements in values are sorted by key.
}
*/
void InputArray(string filename, int arrayName[]) // ()
{
  ifstream inFile;
  int dataValue = 0;
  int i = 0;

  inFile.open(filename.c_str());
  while(i<SIZE) {   // (&& !inFile.eof())
      inFile >> arrayName[i];
      i++;
  }
  inFile.close();
}

void OutputArray(string filename, int arrayName[])
{
  ofstream outFile;
  outFile.open(filename.c_str());
  int i = 0;
  while(i<SIZE) {
      outFile << arrayName[i] << "\n";
      i++;
  }
  outFile.close();
}

int* arrSorted = new int[10*SIZE];
int* arr1 = new int[SIZE];  
int* arr2 = new int[SIZE];
int* arr3 = new int[SIZE];
int* arr4 = new int[SIZE];
int* arr5 = new int[SIZE];
int* arr6 = new int[SIZE];
int* arr7 = new int[SIZE];
int* arr8 = new int[SIZE];
int* arr9 = new int[SIZE];
int* arr10 = new int[SIZE];

// https://www.geeksforgeeks.org/quick-sort/
// https://www.geeksforgeeks.org/merge-two-sorted-arrays/

int main ()
{
  cout << "\n\nThis program: " <<
  "\n1) Takes in 10 arrays of 'SIZE' each created from different files" <<
  "\n2) Sorts each one with QuickSort" <<
  "\n3) Copies that memory of each sorted array to one large array" <<
  "\n4) Uses the MergeSort operation to sort the large array" <<
  "\n5) Outputs the time required for each step and the final sorted array as your chosen output file\n\n";

  int numValues = SIZE;
  int i, zero;
  zero = 0;
  
  time_t start_time, end_time; // ORIGINAL TIME METHOD  
  struct timeval start, end; // BETTER TIME METHOD
  long int seconds1, seconds2, seconds3, micro1, micro2, micro3;

  cout << "Times are as follows: \n1) gettimeofday(): \n2) time(NULL): \n";
   
// ---- INPUT ARRAYS AND TIME
  start_time = time(NULL);
  gettimeofday(&start, NULL); // get start time

  InputArray("xaa.txt", arr1);
  InputArray("xab.txt", arr2);
  InputArray("xac.txt", arr3);
  InputArray("xad.txt", arr4);
  InputArray("xae.txt", arr5);
  InputArray("xaf.txt", arr6);
  InputArray("xag.txt", arr7);
  InputArray("xah.txt", arr8);
  InputArray("xai.txt", arr9);
  InputArray("xaj.txt", arr10);

  end_time = time(NULL);
  gettimeofday(&end, NULL); // get end time
  seconds1 = end.tv_sec - start.tv_sec; // find elapsed time
  micro1 = end.tv_usec  - start.tv_usec;
  
  cout << endl << "Time to input 10 Arrays of integers: "<< seconds1 << " seconds, " << micro1 << "microseconds " <<endl;
  cout << "Time to input 10 Arrays of integers: "<< end_time-start_time << " seconds " << endl;

// ---- QUICKSORT ARRAYS AND TIME
  start_time = time(NULL);
  gettimeofday(&start, NULL); // get start time

  QuickSort(arr1, zero, numValues-1);
  QuickSort(arr2, zero, numValues-1);
  QuickSort(arr3, zero, numValues-1);
  QuickSort(arr4, zero, numValues-1);
  QuickSort(arr5, zero, numValues-1);
  QuickSort(arr6, zero, numValues-1);
  QuickSort(arr7, zero, numValues-1);
  QuickSort(arr8, zero, numValues-1);
  QuickSort(arr9, zero, numValues-1);
  QuickSort(arr10, zero, numValues-1);
  
  end_time = time(NULL);
  gettimeofday(&end, NULL); // get end time
  seconds2 = end.tv_sec - start.tv_sec; // find elapsed time
  micro2 = end.tv_usec  - start.tv_usec;
  
  cout << endl <<"Time to Quicksort 10 Arrays of "<< SIZE <<" integers: "<< seconds2 << " seconds, " << micro2 << "microseconds " <<endl;
  cout << "Time to Quicksort 10 Arrays of "<< SIZE<< " integers: "<< end_time-start_time << " seconds " << endl;
  
// ---- COPY EACH ARRAY TO BIG ARRAY OF 50,000,000

  memcpy(arrSorted, arr1, SIZE * sizeof(int));
  delete [] arr1;  

  memcpy(&arrSorted[SIZE], arr2, SIZE * sizeof(int));
  delete [] arr2;

  memcpy(&arrSorted[SIZE*2], arr3, SIZE * sizeof(int));
  delete [] arr3;

  memcpy(&arrSorted[SIZE*3], arr4, SIZE * sizeof(int));
  delete [] arr4;

  memcpy(&arrSorted[SIZE*4], arr5, SIZE * sizeof(int));
  delete [] arr5;

  memcpy(&arrSorted[SIZE*5], arr6, SIZE * sizeof(int));
  delete [] arr6;

  memcpy(&arrSorted[SIZE*6], arr7, SIZE * sizeof(int));
  delete [] arr7;

  memcpy(&arrSorted[SIZE*7], arr8, SIZE * sizeof(int));
  delete [] arr8;

  memcpy(&arrSorted[SIZE*8], arr9, SIZE * sizeof(int));
  delete [] arr9;

  memcpy(&arrSorted[SIZE*9], arr10, SIZE * sizeof(int));
  delete [] arr10;

// ---- MERGE SORT AND TIME
  start_time = time(NULL);
  gettimeofday(&start, NULL); // get start time

  MergeSort(arrSorted, 0, (SIZE*10)-1);
  
  end_time = time(NULL);
  gettimeofday(&end, NULL); // get end timE
  seconds3 = end.tv_sec - start.tv_sec; // find elapsed time
  micro3 = end.tv_usec  - start.tv_usec;
  
  cout << endl << "Time to MergeSort "<<SIZE*10<<" integers: "<< seconds3 << " seconds, " << micro3 << "microseconds " <<endl;
  cout << "Time to MergeSort "<<SIZE*10<<" integers: "<< end_time-start_time << " seconds " << endl;

// ---- OUTPUT FILE OF THE SORTED LARGE ARRAY
  string fileOut;
  /* cout << "Name your sorted file: ";
  cin >> fileOut;
  cout << endl; */
  fileOut = "out.txt";
  OutputArray(fileOut, arrSorted);
  
  delete [] arrSorted;
  return 0;
}
// For 5 Million got up to: 6m54.094s then Quit it.

  /*
  // BUBBLE SORT
  // measure time 
  start_time = time(NULL);
  BubbleSort(&values[0], numValues);
  end_time = time(NULL);
  cout << " Bubble Sort Items:  " << SIZE << " Time is: " << end_time-start_time << " seconds " << endl;
  
  // print some after 
  for(i=0;i<5;i++) cout << "value after bubble soret " << i << " was " << values[i] << endl;
  // make some random data
  for(i=0;i<SIZE;i++) values[i] = rand()% 1000;
  //print a few before 
  for(i=0;i<5;i++) cout << "value before merge sort " << i << " was " << values[i] << endl;
  */

 /*
 /*
 For this lab, 
•1- create a data file of 50 million 3 digit random numbers. 
•2- Test two existing sorting algorithms to determine how many data items they can sort.  
 Measure and report their time using the functions described in the file  fine_grain_time.cpp
•3- divide the 50 million items into as many files as is required to perform the sort on each 
 of the individual files. For example if the sort algorithm you chose can sort 1 million items, 
 then create 50 separate files and sort each file individually. Under no conditions should you
  have less than 10 files even if you can.
•4- merge each of individually sorted files into one final sorted file with 50 million items.  
•5- To verify that your work is correct, compare 
  your final result to that obtained by applying the sort command (man 1 sort) to your original
   file and see if they agree (man 1 diff).
*/