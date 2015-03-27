#include "Valero.h"
#include "common.h"
#include "stddef.h"
#include <iostream>				//delete after testing

using namespace std;
//local variables

chainNode** createChainTable(int hashSize) {
	int n = hashSize;
	chainNode** chainedTable = new chainNode*[n];
	chainNode* initializer;
	for (int i = 0; i < n; i++) {
		chainedTable[i] = new chainNode;
		chainedTable[i]->next = NULL;
	}

	return chainedTable;
}

void putHash(chainNode* hashTable[], int key, int size) {
	chainNode* resolution;				//pointer to storage location	
	int hashedKey = key % size;			//initial attempt location
	
	resolution = hashTable[hashedKey];
	while(resolution->next != NULL) {
		resolution = resolution->next;
	}
	
	resolution->key = key;
	return;
}

