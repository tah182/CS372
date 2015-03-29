//-----------------------------------------------------------------------------
//CODE FILENAME: 	TatsumotoValero-Assn3-main
//DESCRIPTION:		Analyzes and demonstrates separate chaining, double hashing
//						and linear probing as hash collision resolution methods
//CLASS&TERM:		CS372/Spring 8wk2
//DESIGNER:			Eric Valero & Takashi Tatsumoto
//FUNCTIONS:		main
//-----------------------------------------------------------------------------	
#include "tatsumotovalero-assn3-common.h"			//allow access to global constants, prototypes, and enum types
#include "valero-assn3-funcs.h"						//allow access to functions & data structures created by Eric Valero
#include "tatsumoto-assn3-funcs.h"					//allow access to functions & data structures created by Takashi Tatsumoto


//-----------------------------------------------------------------------------
//FUNCTION: main
//AUTHOR: Eric Valero
//DESCRIPTION: Accesses functions in Valero.cpp, Tatsumoto.cpp, and common.cpp
//				to control program flow
//CALLS TO: displayIntro, fillTable, getHashSize, linearProbeHash,
//			doubleHash, createChainedTable, fillChainTable, searchChainTable,
//			avgSearch, printOutResult
//-----------------------------------------------------------------------------
int main() {
//variables-----------
	chainNode** linkedChainHash;
	int hashSource[SOURCESIZE];
	int hashSize;
	double chainedSearch,
		   linearSearch,
		   doubleSearch;
//--------------------

//display program introduction and get basic information from user,
//		initialize the source array
    displayIntro();

	fillTable(hashSource);
	hashSize = getHashSize();

//dynamically allocate an array of size specified by user for linear probing
	int* linearHash = new (nothrow) int[hashSize];
	if (linearHash) {
		for(int i = 0; i < hashSize; i++)
			linearHash[i] = 0;
    	linearProbeHash(linearHash, hashSource, hashSize);						//run hash algorithm against array
    }
    else
    	cout << "Error- out of heap memory" << endl;

//dynamically allocate an array of size specified by user for double hashing
    int* doubleHashArray = new (nothrow) int[hashSize];
    if (doubleHashArray) {
		for (int i = 0; i < hashSize; i++)
			doubleHashArray[i] = 0;
    	doubleHash(doubleHashArray, hashSource, hashSize);						//run hash algorithm against array
    }
    else
    	cout << "Error- out of heap memory" << endl;

//dynamically allocate array of pointers to store seperately chained hash values
	linkedChainHash = createChainTable(hashSize);
	fillChainedTable(linkedChainHash, hashSource, hashSize);					//run hash algorithm against array of pointers
	
//this block of code returns the number of items examined in searching each table
	chainedSearch = searchChainedTable(linkedChainHash, hashSource, hashSize);	
    linearSearch = avgSearch(hashSource, linearHash, hashSize, LINEAR_PROBE);
    doubleSearch = avgSearch(hashSource, doubleHashArray, hashSize, DOUBLE_HASH);

//display results to user
    printOutResult(linearSearch, doubleSearch, chainedSearch, hashSize);

	return 0;
}
