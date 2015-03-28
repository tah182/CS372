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
		chainedTable[i]->key = 0;
	}

	return chainedTable;
}

//places a key in the hash table after collision resolution
void putHash(chainNode* hashTable[], int key, int size) {
	chainNode* resolution;				//pointer to storage location	
	int hashedKey = key % size;			//initial attempt location
	
	resolution = hashTable[hashedKey];
	
	//if first link in chain is empty, add key to that location
	if (resolution->key == 0) {
		resolution->key = key;
		resolution->next = new (nothrow) chainNode;
		if (!resolution->next)
			cout << endl << "ERROR- out of heap memory";
		else 
			resolution->next->next = NULL;	
	}
	//else find the end of the chain and append a new node
	else {
		//find end of chain
		while(resolution->next != NULL) {
			resolution = resolution->next;
		}
		//dynamically allocate new node
		resolution->key = key;
		resolution->next = new (nothrow) chainNode;
		resolution = resolution->next;
		//if node creation was succesfull, save key to node
		if(resolution) {
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

//searches every other value within the hash source table in the hash, 
//finds average number of steps to find value
double searchChainedTable(chainNode* hashTable[], int sourceArr[], int size) {

	double averageSteps;
	int target;
	int hashedKey;
	chainNode* location;
	int index = 0; 
	double	steps,
			runs = 0.0;
	
	while(index < SOURCESIZE) {
		target = sourceArr[index];
		hashedKey = target % size;
		location = hashTable[hashedKey];
		steps++;
		
		if (location->key != target) {

			while(location->key != target) {
				location = location->next;
				steps++;
			}
		}
		runs++;
		index += 2;
	}
	
	averageSteps = steps / runs;
	
	return averageSteps;
}
