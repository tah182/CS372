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
	int hashSize;
	int* linearHash;
	double chainedSearch,
		   linearSearch,
		   doubleSearch;

    displayIntro();
	
	fillTable(hashSource);
	hashSize = getHashSize();
	
    //linearProbeHash(hashSource, linearHash, hashSize);

	linkedChainHash = createChainTable(hashSize);
	fillChainedTable(linkedChainHash, hashSource, hashSize);
	chainedSearch = searchChainedTable(linkedChainHash, hashSource, hashSize);
	cout << chainedSearch;


	return 0;
}
