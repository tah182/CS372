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

		target = (rand() % 30000) + 1;					//get rid of this constant
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

//**************************************************************************
// FUNCTION:  displayIntro
// DESCRIP:   Displays the application introduction message
// INPUT:     None
// OUTPUT:    None
// CALLS TO:
//**************************************************************************
 void displayIntro() {
 	cout << "*****Tatsumoto-Valero-assn3-prog*****" << endl;
    cout << "This program will assess statistics behind:" << endl;
    cout << "    - linear probe hashing" << endl;
    cout << "    - double hashing" << endl;
    cout << "    - separated chain hashing" << endl;
    cout << "and compare against Knuth averages." << endl << endl;

    return;
 }

  //**************************************************************************
// FUNCTION:  searchInt
// DESCRIP:   Searches the hash table and calculates how many passes it made to find the number
// INPUT:     hashTable - the hash Table array to search in
//            hashSize - the size of the hash Table
//            num - the number to find
//            probeMethod - the ProbeMethod Enum
// OUTPUT:    int the passes needed to find the number
// CALLS TO:
//**************************************************************************
 int searchInt(int hashTable[], int hashSize, int num, ProbeMethod probeMethod) {
     int passes = 0;
     int hashLocation;
     switch (probeMethod) {
        case LINEAR_PROBE:
            hashLocation = num % hashSize;
            while (hashTable[hashLocation] != num) {
                hashLocation++;
                passes++;
            }
            passes++;
            break;
        case DOUBLE_HASH:
            hashLocation = num % hashSize;
            while (hashTable[hashLocation] != num) {
                int newLocation = (num % (hashSize - 2)) + 1;
                hashLocation = (newLocation + hashLocation) % hashSize;
            }
            passes++;
            break;
        default :
            passes = 0;
     }
     return passes;
 }


 //**************************************************************************
// FUNCTION:  avgSearch
// DESCRIP:   the average search it took to find each number
// INPUT:     intArray - the integer array to search numbers from
//            hashTable - the hash Table array to search in
//            hashSize - the size of the hash Table
//            probeMethod - the ProbeMethod Enum
// OUTPUT:    float - the average searches it took to find the integers
// CALLS TO:  searchInt
//**************************************************************************
 float avgSearch(int intArray[], int hashTable[], int hashSize, ProbeMethod probeMethod) {
 	int searchesTook = 0;
 	for (int i = 0; i < SOURCESIZE / 2; i += 2)
        searchesTook += searchInt(hashTable, hashSize, hashTable[i], probeMethod);

 	return searchesTook * 1.0 / (SOURCESIZE / 2);
 }
