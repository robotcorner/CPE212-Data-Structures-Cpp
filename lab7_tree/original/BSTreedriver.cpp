#include <string>
#include <iostream>
#include <fstream>
#include "BSTree.h"
#include <ctime>
#include <cstdlib>

using namespace std;


//****************************************************************************************************************************
// NEW CODE FOR DUPLICATE ENTRIES 



int main()
{
  ifstream inFile;
  string inputFile = "student_record_data_file";
  ofstream outFile;
  string outputFile;
  int count_555;

  cout << "Enter the name of the output file: ";
  cin >> outputFile;

  // opening Input and Output files
  inFile.open(inputFile.c_str());
  outFile.open(outputFile.c_str());

// Create Student Name Tree 
  TreeType studentNameTree;     // studentNameTree is of type Tree, called treeType

  info studentInformation[5000];
  int arrayStudentInfo[3][5000];    // rows, columns order, want 3 arrays

// read the file into three arrays -- Reads 3 at a time for 5000 rows
  for (int i = 0; i < 5000; i++)
  {
    inFile >> studentInformation[i].namenum;
    inFile >> studentInformation[i].classnum;
    inFile >> studentInformation[i].gradenum;  
  }

  for (int i = 0; i < 5000; i++)
    studentNameTree.InsertDuplicate(studentInformation[i]); // THIS CREATES a bunch of duplicates in the tree.

//****************************************************************************************************************************
// Check Duplicate Entries Here
  // traverse the entire tree for duplicates
  
// ***************************************************************************************************************************

  // Checking the number of times the name '555' appears in the student name tree 
  studentNameTree.CountDuplicate( (int) 555, &count_555);

  cout << "number 555 in tree is " << count_555 << endl;
  // Printing the three trees and array to the output file
  studentNameTree.PrintItem(outFile);   // Added print to outfile
}

