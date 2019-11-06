// Stephen Stammen
// Jakob Henson

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int function1(int a1);
float function2 (int a1, float a2);

int main()
{
	const int ROWS = 10;
	const int COLS = 10;
	int newInt = 0;
	float newFloat = 0.0;
	int a1[ROWS][COLS];
	float a2[ROWS][COLS]; 
	float a3[ROWS][COLS];
	int a1x[ROWS][COLS];

	string filename;
	int row;
	int cols;
	
	// read the data files into appropriate structures
	ifstream source1;
	ifstream source2;
		
	source1.open("file1.dat");  // opens the first file to read
	source2.open("file2.dat");
	
	if(!source1 || !source2) {
		cout << "Error: could not open input file";
		return 1;
	}
	
	// READ IN FILE VALUES a1
	for(row = 0; row < ROWS; row++)
		for(cols = 0; cols < COLS; cols++) {
			source1 >> newInt;
			a1[row][cols] = newInt;
			//cout << a1[row][cols] << "  " << newInt;
		}
	
	// READ IN FILE VALUE a2
	for(row = 0; row < ROWS; row++)
		for(cols = 0; cols < COLS; cols++) {
			source2 >> newFloat;
			a2[row][cols] = newFloat;
			//cout << a2[row][cols] << "  " << newFloat;
		}
	
	// pass one or more selected data files to a function1 and get back and print the results
	// TAKES MATRIX INPUT

	// FUNCTION 1 MANIPULATE
	for(row = 0; row < ROWS; row++) {
		for(cols = 0; cols < COLS; cols++) {
			a1x[row][cols] = function1(a1[row][cols]);
		}
	}
	
	// FUNCTION 1 PRINT
	cout << "file1.dat with function1 applied" << endl;
	for(row = 0; row < ROWS; row++) {
		for(cols = 0; cols < COLS; cols++) {
			cout << a1x[row][cols] << ' ';
		}
		cout << endl;
	}
	cout << endl;
	
	// FUNCTION 2 MANIPULATE
	// pass one or more selected data files to a function2 and get back and print the results
	for(row = 0; row < ROWS; row++)
		for(cols = 0; cols < COLS; cols++)
			a3[row][cols] = function2(a1[row][cols], a2[row][cols]);

	// FUNCTION 2 PRINT
	cout << "file1.dat and file2.dat with funtion2 applied" << endl;
	for(row = 0; row < ROWS; row++) {
		for(cols = 0; cols < COLS; cols++) {
			cout << a3[row][cols] << ' ';
		}
		cout << endl;
	}
	cout << endl;
	
	source1.close();
	source2.close();

	return 0;
}

int function1(int a1) // parameter
{
	return a1*a1;
}

float function2 (int a1, float a2)
{
	float a3 = int(a1) + float(a2);
	return a3;
}


