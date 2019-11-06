// This file courtesy of cody holland
//
// notice the somewhat suprising use of arrays of pointers to arrays
//
//this is one way to dynamically resize the arrays at the time the data is read in 
//
// Lab Assignment 2
// Cody D. Holland
// 4 September 2019
// CS 214-01
/* Read two files and place their contents into two different arrays. For function1,
   take the first array and square each element and assign it to array a1x.
   For function2, sum both arrays into a3. After performing these operations,
   output both new arrays in a 10x10 square.

   For the sake of simplicity, I used string literals for the filenames and
   automatically assigned the dimensions of the arrays to 10x10.
*/

#include <iostream>
#include <fstream>
#include <cmath>  // included for squaring array elements using pow()

using namespace std;

// function prototypes
// functions return pointers-to-pointer since 2d arrays are involved
int** function1(int**);
float** function2 (int**, int**);

int main()
{
	// input file stream
	ifstream inFile;

	// double array pointers for return value of functions
	int **a1x;
	float **a3;

	// double array pointers for reading input and passing into functions
	int **a1;
	int **a2;

	// using new int in order to assign memory locations for pointer
	a1 = new int *[10];
	a2 = new int *[10];

	// looping to assign individual element locations
	for(int i = 0; i < 10; i++)
	{
		a1[i] = new int[10];
		a2[i] = new int[10];
	}
		
	// open input file
	inFile.open("file1.dat");
	
	// read into array and close file
	for(int i = 0; i<10; i++)
	{
		// nested loop because 2d array
		for(int j = 0; j<10; j++)
		{
			inFile >> a1[i][j];
		}
	}
	inFile.close();

	// open second file
	inFile.open("file2.dat");

	// read into second array and close file
	for(int i = 0; i<10; i++)
	{
		// nested b/c 2d array
		for(int j = 0; j<10; j++)
		{
			inFile >> a2[i][j];
			inFile.ignore(256,'.');
		}
	}
	inFile.close();

	// perform operations using function calls
	a1x = function1(a1);
	a3 = function2(a1,a2);

	// output array of squares
	cout << "Squared Array" << endl;
	for (int i = 0; i < 10; i++)
	{
		// nested loop since 2d array
		for (int j = 0; j < 10; j++)
			cout << a1x[i][j] << " ";
		cout << endl;
	}
	cout << endl << endl;

	// output array of sums
	cout << "Summed Array" << endl;
	for (int i = 0; i < 10; i++)
	{
		// nested loop since 2d array
		for (int j = 0; j < 10; j++)
			cout << a3[i][j] << " ";
		cout << endl;
	}
	cout << endl << endl;

	return 0;
}


/* return  type not void */  
int** function1(int** a1)
{
	// create double pointer for return
	int** a1x;
	a1x = new int *[10];
	for(int i = 0; i<10; i++)
		a1x[i] = new int[10];

	// loop to square input array and place into output array
	for(int i = 0; i<10; i++)
	{
		//nest loop
		for(int j = 0; j<10; j++)
		{
			a1x[i][j] = pow(a1[i][j],2);
		}
	}
	
	// return array
	return a1x;
}

/* return type not void */
float** function2 (int** a1, int** a2)
{
	// create double pointer for return
	float** a3;
	a3 = new float *[10];
	for(int i = 0; i<10; i++)
		a3[i] = new float[10];
	
	// loop to sum input arrays and place into output array
	for(int i = 0; i<10; i++)
	{
		//nest loop
		for(int j = 0; j<10; j++)
		{
			a3[i][j] = (a1[i][j])+(a2[i][j]);
		}
	}

	// return array
	return a3;
}

