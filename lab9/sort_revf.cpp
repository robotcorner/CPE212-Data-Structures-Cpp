#define DEBUG 0
#define SIZE 50000
#include <stdlib.h>
#include <iostream>

using namespace std;



void Swap(int& item1, int& item2)
// Post: Contents of item1 and item2 have been swapped
{
  int tempItem;
  
  tempItem = item1;
  item1 = item2;
  item2 = tempItem;
}

void BubbleUp(int values[], int startIndex, int endIndex)
// Post: Adjacent pairs that are out of order have been 
//       switched between values[startIndex]..values[endIndex]
//       beginning at values[endIndex].
{
  for (int index = endIndex; index > startIndex; index--)
    if (values[index] < values[index-1])
      Swap(values[index], values[index-1]);
}


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



void Merge (int values[], int leftFirst, int leftLast, int rightFirst, int rightLast)
// Post: values[leftFirst]..values[leftLast] and values[rightFirst]..values[rightLast] have been merged.
//       values[leftFirst]..values[rightLast] is now sorted.
{
  int tempArray[SIZE];
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




int main ()
{
int values[SIZE];
int numValues;
int i, zero;
numValues = SIZE;
zero = 0;
time_t start_time, end_time;

// make some randon data 
for(i=0;i<SIZE;i++) values[i] = rand()% 1000;

//print a few before 
for(i=0;i<5;i++) cout << "value before bubble sort  " << i << " was " << values[i] << endl;

// sort 

//measure time 
start_time = time(NULL);

BubbleSort(&values[0], numValues);

end_time = time(NULL);
cout << " time to bubble sort " << SIZE << " numbers is " << end_time-start_time << " seconds " << endl;
// print some after 
for(i=0;i<5;i++) cout << "value after bubble soret " << i << " was " << values[i] << endl;

// make some random data
for(i=0;i<SIZE;i++) values[i] = rand()% 1000;

//print a few before 
for(i=0;i<5;i++) cout << "value before merge sort " << i << " was " << values[i] << endl;

start_time = time(NULL);

// sort
MergeSort(&values[0], zero , numValues );

end_time = time(NULL);
cout << " time to merge  sort " << SIZE << " numbers is " << end_time-start_time << " seconds " << endl;
//print a few after 
for(i=0;i<5;i++) cout << "value after mergesort was " << i << " was " << values[i] << endl;

}


