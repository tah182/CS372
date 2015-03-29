#include "tatsumotovalero-assn3-common.h"
#include "tatsumoto-assn3-funcs.h"

//**************************************************************************
// IMPLEMENTED BY: Tah Tatsumoto
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
// -------------------      DEPRECATED          ----------------------------
// IMPLEMENTED BY: Tah Tatsumoto
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
// IMPLEMENTED BY: Tah Tatsumoto
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
// IMPLEMENTED BY: Tah Tatsumoto
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
// IMPLEMENTED BY: Tah Tatsumoto
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


//**************************************************************************
// IMPLEMENTED BY: Tah Tatsumoto
// FUNCTION:  printOutResult
// INPUT:       linearProbeResult - the result of the linear probe
//              doubleHashResult - the result of the double hash
//              chainHashResult - the result of the chain hash
//              hashSize - the hash table size
// OUTPUT:
// CALLS TO:  knuthPrediction
//**************************************************************************
void printOutResult(int linearProbeResult, int doubleHashResult, int chainHashResult, int hashSize) {
    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(3);
    cout << endl << endl << SOURCESIZE << " items loaded into a " << hashSize << " element hash table." << endl;
    cout << "Load Factor = " << SOURCESIZE * 1.0 / hashSize << endl << endl;
    cout << "Result of searching for 2500 items:" << endl << endl;
    cout << "\tLinear Probing" << endl;
    cout << "\t\t" << linearProbeResult << " items examined (avg = " << linearProbeResult * 1.0 / (SOURCESIZE / 2);
    cout <<             " items examined per search)" << endl;
    cout << "\t\t" << "  vs Knuth predicted avg = " << knuthPrediction(LINEAR_PROBE, hashSize) << " items examined per search." << endl << endl;
    cout << "\tDouble Hashing" << endl;
    cout << "\t\t" << doubleHashResult << " items examined (avg = " << doubleHashResult * 1.0 / (SOURCESIZE / 2);
    cout <<             " items examined per search)" << endl;
    cout << "\t\t" << "  vs Knuth predicted avg = " << knuthPrediction(DOUBLE_HASH, hashSize) << " items examined per search." << endl << endl;
    cout << "\tChained Hashing" << endl;
    cout << "\t\t" << chainHashResult << " items examined (avg = " << chainHashResult
 * 1.0 / (SOURCESIZE / 2);
    cout <<             " items examined per search)" << endl;
    cout << "\t\t" << "  vs Knuth predicted avg = " << knuthPrediction(CHAIN_HASH, hashSize) << " items examined per search." << endl;
}
