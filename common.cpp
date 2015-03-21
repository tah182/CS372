//contains functions which must be available to all cpp files

using namespace std;
#include "common.h"
#include <iostream>


//implemented by Eric Valero. 
//Gets the table size from user for declaring hash tables of dynamic size
int getTableSize() {
	int n;
	cout << "Enter a desired table size: ";
	cin >> n;
	cout << endl;
	
	return n;
}

//implemented by Eric Valero.
//tries to add a number to the source table, if it is unique
void fillTable(int table[], int& lastFill, int target) {
	bool isUnique = true;							//used to track uniqueness of target number
	
	//determine if number is unique
	for(int index = 0; ((index <= lastFill)&&(isUnique = true)); index++) {
		if(table[index]==target)
			isUnique = false;
	}
	
	//if it is unique, add to next space in array
	if(isUnique)
		table[lastFill + 1] = target;
}
