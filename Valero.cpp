#include "Valero.h"
#include "common.h"
#include "stddef.h"
#include <iostream>				//delete after testing

using namespace std;
//local variables

chainNode* createChainTable() {
	int n = getTableSize();
	chainNode* chainedTable = new chainNode[n];
	
	return chainedTable;
}

chainNode* getHash(chainNode* hashTable, int key, int size) {
	chainNode* resolution;				//pointer to storage location	
	int hashedKey = key % size;			//initial attempt location
	
	resolution = &hashTable[hashedKey];
	
	while(resolution->next != NULL) {
		resolution = resolution->next;
	}
	
	cout << resolution;
	return resolution;
}

