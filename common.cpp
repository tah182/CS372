//contains functions which must be available to all cpp files

using namespace std;
#include "common.h"
#include <iostream>
#include <stdlib.h>			//used for rand, srand functions


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
void fillTable(int table[]) {
	bool isUnique = true;							//used to track uniqueness of target number
	int entries = 0;								//number of entries which have been added to table
	int target;										//number to attempt to add to table
	
	while(entries <= SOURCESIZE) {
		srand(SEED);
		target = rand();
		
		//determine if number is unique
		for(int index = 0; ((index <= entries)&&(isUnique = true)); index++) {
			if(table[index]==target)
				isUnique = false;
		}
		
		//if it is unique, add to next space in array and increment entries
		if(isUnique) {
			table[entries] = target;
			entries++;
		}
	}
	return;
}	
