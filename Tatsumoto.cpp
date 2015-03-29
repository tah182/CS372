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
// FUNCTION:  allocArray
// DESCRIP:   Allocates array. Exits if cannot allocate.
// INPUT:     arrSize - the size of the array to allocate
// OUTPUT:    Return Value: an allocated array
// CALLS TO:
//**************************************************************************
void allocArray(int hashTable[], int arrSize) {
    try {
         hashTable = new int[arrSize];
    } catch (bad_alloc& exc) {
        cout << "Cannot allocate array memory. Exiting..." << endl;
        exit(1);
    }
 }

//**************************************************************************
// ------------------         DEPRECATED        ----------------------------
// FUNCTION:  makeRandArray
// DESCRIP:   Dynamically allocates 5000 integers with random numbers
// INPUT:     None
// OUTPUT:    Return Value: a pointer to array object of size 5,000
// CALLS TO:  allocArray
//            makeRandInt
//**************************************************************************
/*
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
*/

//**************************************************************************
// FUNCTION:    linearProbeHash
// DESCRIP:     Creates a Linear Hash Table based on array passed in
// INPUT:       hashTable - the reference to the hashTable to create
//              intArray - the integer array to put into hash table
//              hashSize - the size of the hash table
// OUTPUT:      None
// CALLS TO:
//**************************************************************************
void linearProbeHash(int hashTable[], int intArray[], int hashSize) {
    for (int i = 0; i < 5000; i++) {
        // if collision, resolve via linear probe.
        int hashLocation = intArray[i] % hashSize;
        while (hashTable[hashLocation] > 0) {
            hashLocation++;
            if (hashLocation >= hashSize)
                hashLocation = 0;
            //cout << "Collision at location: " << hashLocation - 1 << endl;
        }

        hashTable[hashLocation] = intArray[i];
//        cout << "Int " << i << ": Putting " << intArray[i] << " into [" << hashLocation << "]" << endl;
    }
}

//**************************************************************************
// FUNCTION:  doubleHash
// INPUT:       hashTable - the reference to the hashTable to create
//              intArray - the integer array to put into hash table
//              hashSize - the size of the hash table
// OUTPUT:    Creates a Linear
// CALLS TO:  getHashSize
//**************************************************************************
void doubleHash(int hashTable[], int intArray[], int hashSize) {
    for (int i = 0; i < 5000; i++) {
        // if collision, resolve via linear probe.
        int hashLocation = intArray[i] % hashSize;
        while (hashTable[hashLocation] > 0) {
            int newLocation = (intArray[i] % (hashSize - 2)) + 1;
            hashLocation = (newLocation + hashLocation) % hashSize;
        }
        hashTable[hashLocation] = intArray[i];
//        cout << "Int " << i << ": Putting " << intArray[i] << " into [" << hashLocation << "]" << endl;
    }
}
