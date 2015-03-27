#include <algorithm> // for std::find
#include <stdlib.h>
using namespace std;

// prototypes
int makeRandInt();
int* makeRandArray();
int getHashSize(int arrSize);
int* linearProbeHash(int* intArray, int hashSize);
int* doubleHash(int tSize);
int avgSearch(int *intARray, int *hashTable);
int searchInt(int *hashTable, int num);
