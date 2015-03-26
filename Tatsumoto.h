#include <algorithm> // for std::find

// prototypes
int makeRandInt();
int* makeRandArray();
int* hashSize();
int* linearProbeHash(int tSize);
int* doubleHash(int tSize);
int avgSearch(int *intARray, int *hashTable);
int searchInt(int *hashTable, int num);
