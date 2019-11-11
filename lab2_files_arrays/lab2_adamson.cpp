// this file courtesy of gabriel adamson
//
// note in this case the arrays are fixed by the constant SIZE
//
#include <iostream>
#include <fstream>
#include <iomanip>

#define SIZE 10 // The size of the array

using namespace std;

// Print functions to tidy up outputting the arrays
void printArray(int[SIZE][SIZE]);
void printArray(float[SIZE][SIZE]);

// Functions to process the arrays, last argument is the return value because c++ does not like returning arrays
void function1(int[SIZE][SIZE], int[SIZE][SIZE]);
void function2 (int[SIZE][SIZE], float[SIZE][SIZE], float[SIZE][SIZE]);

int main()
{
    // Initialize the arrays
    int a1[SIZE][SIZE];
    float a2[SIZE][SIZE];
    int a1x[SIZE][SIZE];
    float a3[SIZE][SIZE];

    // Open the files
    ifstream a1in, a2in;
    a1in.open("file1.dat");
    a2in.open("file2.dat");

    // Read the first file
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            a1in >> a1[i][j];
        }
    }


    // Read the second file
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            a2in >> a2[i][j]; // Read as float to handle dots
        }
    }

    // Proces the files
    function1(a1, a1x);
    function2(a1, a2, a3);

    // Output data
    cout << "a1x:\n";
    printArray(a1x);
    cout << "a3:\n";
    printArray(a3);    

    return 0;
}

void printArray(int a[SIZE][SIZE]) {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            cout << left << setw(4) << a[i][j];
        }
        cout << endl;
    }
}

void printArray(float a[SIZE][SIZE]) {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            cout << left << setw(4) << a[i][j];
        }
        cout << endl;
    }
}

void function1(int a1[SIZE][SIZE], int a1x[SIZE][SIZE])
{

    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            a1x[i][j] = a1[i][j] * a1[i][j];
        }
    }
}

void function2 (int a1[SIZE][SIZE], float a2[SIZE][SIZE], float a3[SIZE][SIZE])
{
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            a3[i][j] = a1[i][j] + a2[i][j];
        }
    }
}


