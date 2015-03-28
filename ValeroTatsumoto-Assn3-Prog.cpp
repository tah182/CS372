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
	fillTable(hashSource);
	int hashSize;
	int* linearHash;

    displayIntro();

	hashSize = getHashSize();
    //linearProbeHash(hashSource, linearHash, hashSize);

	linkedChainHash = createChainTable(hashSize);
	fillChainedTable(linkedChainHash, hashSource, hashSize);


	return 0;
}
