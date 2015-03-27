#include "Tatsumoto.h"
#include <iostream>

//**************************************************************************
// FUNCTION:  randInt
// DESCRIP:   creates a random integer between 1 and 30,000
// INPUT:     None
// OUTPUT:    Return Value: a random integer between 1 and 30,000
// CALLS TO:
//**************************************************************************
int makeRandInt() {
    return rand() % 30000 + 1;
}

//**************************************************************************
// FUNCTION:  allocArray
// DESCRIP:   Allocates array. Exits if cannot allocate.
// INPUT:     None
// OUTPUT:    Return Value: an allocated array
// CALLS TO:
//**************************************************************************
 int* allocArray(int arrSize) {
    int *intArray;
    try {
         intArray = new int[arrSize];
    } catch (bad_alloc& exc) {
        cout << "Cannot allocate array memory. Exiting..." << endl;
        exit(1);
    }
    cout << "pt1" << endl;
    return intArray;
 }

//**************************************************************************
// FUNCTION:  makeRandArray
// DESCRIP:   Dynamically allocates 5000 integers with random numbers
// INPUT:     None
// OUTPUT:    Return Value: a pointer to array object of size 5,000
// CALLS TO:
//**************************************************************************
int* makeRandArray() {
    int maxSize = 5000;
    int *intArray = allocArray(maxSize);
    for (int i = 0; i < maxSize; i++) {
        int val = 0;
        bool unique;
        do {
            unique = true;
            val = makeRandInt();
            for (int j = 0; j <= i; j++) {
                if (val == intArray[j]) {
                    unique = false;
                    break;
                }
            }
        } while (!unique);
        intArray[i] = val;
    }
    return intArray;
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
