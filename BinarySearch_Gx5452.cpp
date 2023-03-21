//==========================================================
//
// Title:      Binary Search
// Course:     CSC 3110
// Lab Number: Assignment 4
// Author:     Timothy Kosinski
// Date:       11MAR2023
//
//==========================================================
#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
#include <stdlib.h> // For srand , rand
#include <ctime>

using namespace std; // So "std::cout" may be abbreviated to "cout"

//ProtoType Functions
void randArray(int lowerLimit, int upperLimit, int tArray[]);
void binarySearch(int* array, int search);

int main() {

	srand(time(0)); // Used for Random Value

	//Local Variables

	int elements[16];
	int lower = 0, upper =50;
	int tInput = 0; //temp User Input


	cout << "Welcome To Binary Search Algorithm!";



	//Creates Random Array ( of size 16 )
	randArray(lower, upper, elements);

	cout << "\nEnter A Value You Want to Search";
	cout << "\nFrom Random Array\n\nInput: ";
	cin >> tInput;

	//Calls Binary Search
	binarySearch(elements, tInput);


};

//Used to Create A Random Array ( of Size 16 )
void randArray(int lowerLimit, int upperLimit, int tArray[]) {

	//Used for User Reference
	cout << "\n\n" << left << setw(25) << "Array Position:";
	for (int i = 0; i < sizeof(tArray) * 2; i++) {
		cout << left << setw(4) << i + 1 << "|";
	}
	cout << endl;
	cout << left << setw(25) << " ";
	for (int i = 0; i < (sizeof(tArray) * 2); i++) {
		cout << left << setw(4) << "_____"; //Spacing
	}
	cout << endl;
	//Displays Random Array to User
	cout << left << setw(25) << "Displayed Random Array:";
	for (int i = 0; i < sizeof(tArray)*2; i++) {
		tArray[i] = rand() % (upperLimit - lowerLimit) + lowerLimit;
		lowerLimit = upperLimit;
		upperLimit = upperLimit + 10;
		cout << left << setw(4) << tArray[i] << "|";
	}
	cout << endl;
};

//Core of Program - Binary Search Algorithm
void binarySearch(int* array, int search) {
	//Variables
	int low = 0;
	int mid;
	int high = (sizeof(array) * 2) - 1;
	int tempPos = 1;
	bool key = false;

	cout << "\nSearching Array...\n\n";
	cout << left << setw(8) << "SubSet :";
	cout << left << setw(11) << " Iterations :";
	cout << left << setw(6) << " Array\n";
	cout << left << setw(8) << "------ : ";
	//Heart of Code
	while (low <= high) {
		
		mid = (low + high) / 2;
		
		cout << left << setw(10) << tempPos << " : ";
		for (int i = low; i <= high; i++) {
			cout << array[i] << " ";
		}
		cout << endl;
		
		if (array[mid] == search) {
			key = true;
			cout << "Middle";
			cout << "\nInteger " << search << " is at position " << mid + 1 << endl;
			break;


		}
		else if (array[mid] < search){
			low = mid + 1;
			cout << left << setw(7) << "Right" << left << setw(2) << ":";
		}
		else {
			high = mid - 1;
			cout << left << setw(7) << "Left" << left << setw(2) << ":";
		}	
		tempPos++;
	}
	if (!key) {
		cout << "\nError!! " << search << " is not in array!" << endl;
	}
	
	//End of Code Display
	cout << "\n\nThis is the end of Binary Search Algorithm!!\n";
	
};