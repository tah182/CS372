#include "Valero.h"
#include "common.h"
#include "stddef.h"
#include <iostream>			

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

//places a key in the hash table after collision resolution
void putHash(chainNode* hashTable[], int key, int size) {
	chainNode* resolution;				//pointer to storage location	
	int hashedKey = key % size;			//initial attempt location
	
	resolution = hashTable[hashedKey];
	
	//if first link in chain is empty, add key to that location
	if (resolution == NULL) {
		resolution->key = key;
		resolution->next = NULL;
	}
	//else find the end of the chain and append a new node
	else {
		//find end of chain
		while(resolution->next != NULL) {
			resolution = resolution->next;
		}
		//dynamically allocate new node
		resolution->next = new (nothrow) chainNode;
		//if node creation was succesfull, save key to node
		if(resolution) {
			resolution->key = key;
			resolution->next = NULL;
		}
		//else issue error
		else {
			cout << "Error, not enough memory for chain allocation for key " 
			<< key << endl;
		}
	}
		
	return;
}

//calls put hash while looping through source array to place all keys into table
void fillChainedTable(chainNode* hashTable[], int sourceArr[], int size){
	
	int index = 0;
	int key;
	
	while(index < SOURCESIZE) {
		key = sourceArr[index];
		putHash(hashTable, key, size);
		index++;
	}
	return;
}

