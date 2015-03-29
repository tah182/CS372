#include <iostream>
#include "common.h"
#include "Valero.h"
#include "Tatsumoto.h"

//test data for push

using namespace std;

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
//variables
	chainNode** linkedChainHash;
	int hashSource[SOURCESIZE];
	int hashSize;
	double chainedSearch,
		   linearSearch,
		   doubleSearch;

    displayIntro();

	fillTable(hashSource);
	hashSize = getHashSize();

	int* linearHash = new (nothrow) int[hashSize];
	if (linearHash) {
		for(int i = 0; i < hashSize; i++)
			linearHash[i] = 0;
    	linearProbeHash(linearHash, hashSource, hashSize);
    }
    else
    	cout << "Error- out of heap memory" << endl;

    int* doubleHashArray = new (nothrow) int[hashSize];
    if (doubleHashArray) {
		for (int i = 0; i < hashSize; i++)
			doubleHashArray[i] = 0;
    	doubleHash(doubleHashArray, hashSource, hashSize);
    }
    else
    	cout << "Error- out of heap memory" << endl;

	linkedChainHash = createChainTable(hashSize);
	fillChainedTable(linkedChainHash, hashSource, hashSize);
	chainedSearch = searchChainedTable(linkedChainHash, hashSource, hashSize);


    linearSearch = avgSearch(hashSource, linearHash, hashSize, LINEAR_PROBE);
    doubleSearch = avgSearch(hashSource, doubleHashArray, hashSize, DOUBLE_HASH);

    printOutResult(linearSearch, doubleSearch, chainedSearch, hashSize);

	return 0;
}
