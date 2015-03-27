//contains functions which must be available to all cpp files

using namespace std;
#include "common.h"
#include <iostream>
#include <stdlib.h>			//used for rand, srand functions
#include <time.h>			//used to seed rand

//implemented by Eric Valero.
//tries to add a number to the source table, if it is unique
void fillTable(int table[]) {
	bool isUnique;									//used to track uniqueness of target number
	int entries = 0;								//number of entries which have been added to table
	int target;										//number to attempt to add to table

	srand(time(NULL));

	//run until array is full
	while(entries <= SOURCESIZE) {

		target = rand();
		isUnique = true;

		//determine if number is unique
		for(int index = 0; ((index <= entries)&&(isUnique == true)); index++) {
			if(table[index] == target) {
				isUnique = false;
			}
		}

		//if it is unique, add to next space in array and increment entries
		if(isUnique) {
			table[entries] = target;
			entries++;
		}
	}
	return;
}

//**************************************************************************
// FUNCTION:  getHashSize
// DESCRIP:   Asks the user for hash size
// INPUT:     None
// OUTPUT:    Return Value: an integer >= 6700
// CALLS TO:
//**************************************************************************
 int getHashSize() {
     string printout = "Please input a size for the Hash Table: ";
     int input = 0;
     do {
        cout << printout;
        string userInput = "";
        cin >> userInput;
        try {
            input = atoi(userInput.c_str());
        } catch (exception &e) {
            input = 0;
        }
        if (input < 6700)
            cout << "Not a valid number, please enter a number greater than 6699." << endl;
     } while (input < 6700);
     return input;
 }
