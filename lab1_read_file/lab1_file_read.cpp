// STEPHEN STAMMEN

#include <iostream>
#include <fstream>      // for file IO
#include <string>

using namespace std;
int square(int value);	// square function init

int main() 
{
	// this program reads in a file with integers
	// it computes the specified function 
	// and prints the result out to the console
	// this program is executed four times- once for each of the data files    

	ifstream source;
    string filename;
	long int sum = 0;	
    int newInt = 0;

    cout << "Enter the data file: ";
    cin >> filename;
    source.open(filename.c_str());	// opens 1st file to read
	if(!source) {
        cout << "Error: could not open input file";
        return 1;
    }

    source >> newInt;          // Priming read
	sum += square(newInt); 
	while (source >> newInt) { 
        sum += square(newInt);
    }
	source.close();    	    
	cout <<sum << endl;       // value sent to file with a space btw each value
    return 0;
}

// SQUARE FUNCTION DEFINITION
int square(int value) {
	return (value * value);
}
