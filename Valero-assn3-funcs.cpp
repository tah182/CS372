//--------------------------------------------------------------------------
//CODE FILENAME:	Valero-assn3-funcs.cpp
//DESIGNER:			Eric Valero
//DESCRIPTION:		Creates separate chaining hash table, places hash values
//						in table, searches for values,
//CLASS&TERM:		CS372/Spring 8week2
//FUNCTIONS:		createChainTable, putHash, fillChainedTable, 
//						searchChainedTable
//-------------------------------------------------------------------------- 
#include "valero-assn3-funcs.h"					//allow access to prototypes and data structures in this file
#include "tatsumotovalero-assn3-common.h"		//allow access to global constants, prototypes, data structures and funcs

//--------------------------------------------------------------------------
//FUNCTION: 	createChainTable
//AUTHOR:		Eric Valero
//DESCRIPTION:	creates a dynamically allocated array of pointers to structs
//INPUT:
//	Parameters:	hashSize- a user entered integer determining size of hash table
//OUTPUT:
//	Return Val:	chainedTable- a pointer to an array of pointers(hash table)
//--------------------------------------------------------------------------
chainNode** createChainTable(int hashSize) {
	chainNode** chainedTable = new chainNode*[hashSize];	//allocate memory

	//initialize all nodes to contain pointers to NULL and keys of 0
	for (int i = 0; i < hashSize; i++) {
		chainedTable[i] = new chainNode;
		chainedTable[i]->next = NULL;
		chainedTable[i]->key = 0;
	}

	return chainedTable;
}

//---------------------------------------------------------------------------
//FUNCTION:		putHash
//AUTHOR:		Eric Valero
//DESCRIPTION:	places a key in the hash table after collision resolution
//INPUT:
//	Parameters:	key- value to be added
//				size- size of hash table
//OUTPUT:
//	Parameters:	hashTable[]- updated hash table
//---------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
//FUNCTION:		fillChainedTable
//AUTHOR:		Eric Valero
//DESCRIPTION:	calls put hash while looping through source array to place all 
//					keys into table
//INPUT:
//	Parameters:	size- size of hash table
//OUTPUT:
//	Parameters: chainTable- the hash table
//				sourceArr- used as input, is source of random numbers
//CALLS TO:		putHash
//-----------------------------------------------------------------------------
void fillChainedTable(chainNode* hashTable[], int sourceArr[], int size){

	int index = 0;
	int key;
	
	//loop through source array, pulling random numbers and placing them
	//	in hash table
	while(index < SOURCESIZE) {
		key = sourceArr[index];
		putHash(hashTable, key, size);
		index++;
	}
	return;
}

//-----------------------------------------------------------------------------
//FUNCTION: 	searchChainedTable
//AUTHOR:		Eric Valero	
//DESCRIPTION:	searches every other value within the hash source table in the hash,
//					tracks the number of items examined
//INPUT:
//	Parameters:	size- size of hash table
//OUTPUT:
//	Return Val: steps- number of items examined
//	Parameters:	hashTable- used as input, the hash table
//				sourceArr- used as input, the array of random numbers
//------------------------------------------------------------------------------
double searchChainedTable(chainNode* hashTable[], int sourceArr[], int size) {

	int target;									//search target
	int hashedKey;								//hash location based off target
	chainNode* location;						//a location within the hash table
	int index = 0;				
	double steps = 0.0;
	
	//step through source array
	while(index < SOURCESIZE) {
		target = sourceArr[index];				//retrieve target from array
		hashedKey = target % size;				//generate hash location
		location = hashTable[hashedKey];		//look in that place for target
		steps++;								//track one item examined

		//if location doesn't contain target, step through chain
		//until it does, incrementing step each time
		if (location->key != target) {

			while(location->key != target) {
				location = location->next;
				steps++;
			}
		}
		index += BIGINCREMENT;								//progress by two to search for half of values
												//	in the source array
	}

	return steps;
}
