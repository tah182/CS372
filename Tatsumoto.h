#include <algorithm> // for std::find
#include <stdlib.h>
#include <iostream>
using namespace std;

// prototypes

// unused
//int makeRandInt();
//int* makeRandArray();
//int getHashSize(int arrSize);

void allocArray(int hashTable[], int arrSize);
void linearProbeHash(int hashTable[], int intArray[], int hashSize);
void doubleHash(int hashTable[], int intArray[], int hashSize);
