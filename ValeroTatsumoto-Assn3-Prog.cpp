#include <iostream>
#include "common.h"
#include "Valero.h"
#include "Tatsumoto.h"

//test data for push

using namespace std;

int main() {
//variables
	chainNode** linkedChainHash;
	int hashSource[SOURCESIZE];
	allocArray(hashSource, SOURCESIZE);

	int hashSize;
	double chainedSearch,
		   linearSearch,
		   doubleSearch;

    displayIntro();

	fillTable(hashSource);
	hashSize = getHashSize();

	int linearHash[SOURCESIZE];
	allocArray(linearHash, hashSize);
    linearProbeHash(hashSource, linearHash, hashSize);

    int doubleHashArray[SOURCESIZE];
    allocArray(doubleHashArray, hashSize);
    doubleHash(hashSource, doubleHashArray, hashSize);

	linkedChainHash = createChainTable(hashSize);
	fillChainedTable(linkedChainHash, hashSource, hashSize);
	chainedSearch = searchChainedTable(linkedChainHash, hashSource, hashSize);
	cout << chainedSearch;


	return 0;
}
