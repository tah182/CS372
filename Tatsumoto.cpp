#include "common.h"
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
// INPUT:     arrSize - the size of the array to allocate
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
    return intArray;
 }

//**************************************************************************
// FUNCTION:  makeRandArray
// DESCRIP:   Dynamically allocates 5000 integers with random numbers
// INPUT:     None
// OUTPUT:    Return Value: a pointer to array object of size 5,000
// CALLS TO:  allocArray
//            makeRandInt
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
// FUNCTION:  linearProbeHash
// DESCRIP:   Creates a Linear Hash Table based on array passed in
// INPUT:     intArray - the integer array to put into hash table
// OUTPUT:    Creates a Linear
// CALLS TO:  getHashSize
//**************************************************************************
int* linearProbeHash(int intArray[], int hashSize) {
    int* hashTable = allocArray(hashSize);

    for (int i = 0; i < hashSize; i++) {
        // if collision, resolve via linear probe.
        int hashLocation = intArray[i] % hashSize;
        while (hashTable[hashLocation] > 0) {
            hashLocation++;
            if (hashLocation >= hashSize)
                hashLocation = 0;
            cout << "Collision at location: " << hashLocation - 1 << endl;
        }

        hashTable[hashLocation] = intArray[i];
        cout << "Int " << i << ": Putting " << intArray[i] << " into [" << hashLocation << "]" << endl;
    }
}
