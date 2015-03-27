#include "Valero.h"
#include "common.h"
#include "stddef.h"
#include <iostream>				//delete after testing

using namespace std;
//local variables

chainNode** createChainTable() {
	int n = getTableSize();
	chainNode** chainedTable = new chainNode*[n];
	chainNode* initializer;
	for (int i = 0; i < n; i++) {
		chainedTable[i] = new chainNode;
		chainedTable[i]->next = NULL;
		cout << "ChainedTable[" << i << "] = " << chainedTable[i];
		cout << endl << "->next = " << chainedTable[i]->next << endl;
	}
	cout << "Created";
	return chainedTable;
}

chainNode* putHash(chainNode* hashTable[], int key, int size) {
	chainNode* resolution;				//pointer to storage location	
	int hashedKey = key % size;			//initial attempt location
	
	cout << "attempting to resolve";
	resolution = hashTable[hashedKey];
	cout << "going to enter loop";
	while(resolution->next != NULL) {
		resolution = resolution->next;
	}
	
	resolution->key = key;
	return resolution;
}

