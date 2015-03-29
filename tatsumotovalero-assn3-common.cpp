//-----------------------------------------------------------------------------------
//FILE NAME: tatsumotovalero-assn3-common.cpp
//DESIGNERS: Eric Valero & Takashi Tatsumoto
//DESCRIPTION: contains functions which must be available to all cpp files
//CLASS&TERM: CS372/Spring 8wk2
//-----------------------------------------------------------------------------------
#include "stddef.h"
#include "tatsumotovalero-assn3-common.h"
#include "tatsumoto-assn3-funcs.h"
#include "valero-assn3-funcs.h"

//-------------------------------------------------------------------------------
//FUNCTION:		fillTable
//AUTHOR:	 	Eric Valero.
//DESCRIPTION:	Tries to add a number to the source table, if it is unique
//OUTPUT:
//	Parameters:	table- the completed source array
//CALLS TO:		srand- seeds the rand function
//				rand- generates a random int
//-------------------------------------------------------------------------------
void fillTable(int table[]) {
	bool isUnique;									//used to track uniqueness of target number
	int entries = 0;								//number of entries which have been added to table
	int target;										//number to attempt to add to table

	srand(time(NULL));

	//run until array is full
	while(entries <= SOURCESIZE) {

		target = (rand() % TOOBIG) + 1;				//ensure all numbers x are 0 < x < 30000
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
// IMPLEMENTED BY: EricValero
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
// IMPLEMENTED BY: Tah Tatsumoto
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
// IMPLEMENTED BY: Tah Tatsumoto
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
     int hashLocation = num % hashSize;
     switch (probeMethod) {
        case LINEAR_PROBE:
            while (hashTable[hashLocation] != num) {
                hashLocation++;
                if (hashLocation >= hashSize) hashLocation = 0;
                passes++;
            }
            passes++;
            break;
        case DOUBLE_HASH:
            while (hashTable[hashLocation] != num) {
                int newLocation = (num % (hashSize - 2)) + 1;
                hashLocation = (newLocation + hashLocation) % hashSize;
                passes++;
            }
            passes++;
            break;
        default :
            passes = 0;
     }
     return passes;
 }


//**************************************************************************
// IMPLEMENTED BY: Tah Tatsumoto
// FUNCTION:  avgSearch
// DESCRIP:   the average search it took to find each number
// INPUT:     intArray - the integer array to search numbers from
//            hashTable - the hash Table array to search in
//            hashSize - the size of the hash Table
//            probeMethod - the ProbeMethod Enum
// OUTPUT:    float - the average searches it took to find the integers
// CALLS TO:  searchInt
//**************************************************************************
 int avgSearch(int intArray[], int hashTable[], int hashSize, ProbeMethod probeMethod) {
 	int searchesTook = 0;
 	for (int i = 0; i < SOURCESIZE; i += 2)
        searchesTook += searchInt(hashTable, hashSize, hashTable[i], probeMethod);

 	return searchesTook;
 }


//**************************************************************************
// IMPLEMENTED BY: Tah Tatsumoto
// FUNCTION:  knuthPrediction
// DESCRIP:   calculates the Knuth predicted average search
// INPUT:     probeMethod - the ProbeMethod enum
//            hashSize - the size of the hash Table
// OUTPUT:    float - the calculated average of searches necessary
// CALLS TO:
//**************************************************************************
 float knuthPrediction (ProbeMethod probeMethod, int hashSize) {
     double loadFactor = SOURCESIZE * 1.0 / hashSize;
     switch (probeMethod) {
        case LINEAR_PROBE:
            return 1 * 1.0 / 2 * (1 + (1 / (1 - loadFactor)));
            break;
        case DOUBLE_HASH:
            return (-log(1 - loadFactor)) / loadFactor;
            break;
        case CHAIN_HASH:
            return 1 + (loadFactor / 2);
            break;
        default:
            break;
     }
     return 1;
 }
