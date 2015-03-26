#include "Tatsumoto.h"

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
// FUNCTION:  makeRandArray
// DESCRIP:   Dynamically allocates 5000 integers with random numbers
// INPUT:     None
// OUTPUT:    Return Value: a pointer to array object of size 5,000
// CALLS TO:
//**************************************************************************
int* makeRandArray() {
    int maxSize = 5000;
    int *intArray = new int[maxSize];
    int i = 0;
    for (i = 0; i < maxSize; i++) {
        int val = 0;
        do {
            val = makeRandInt();
        } while (std::find(intArray, intArray+5000, val) == intArray+5000);
        intArray[i] = val;
    }
    return intArray;
}

//**************************************************************************
// FUNCTION:  randInt
// DESCRIP:   creates a random integer between 1 and 30,000
// INPUT:     None
// OUTPUT:    Return Value: a random integer between 1 and 30,000
// CALLS TO:
//**************************************************************************
 int* allocArray() {
 }

