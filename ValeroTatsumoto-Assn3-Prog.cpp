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
	//when you pass this hashSource, you are passing the
	//fixed source array for dynamic allocation.
							//allocArray(hashSource, SOURCESIZE);

	int hashSize;
	double chainedSearch,
		   linearSearch,
		   doubleSearch;

    displayIntro();

	//all code should come after this point since this is where the source array gets filled with random numbers
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
	cout << chainedSearch;


    //linearSearch = avgSearch(hashSource, linearHash, hashSize, LINEAR_PROBE);
    //doubleSearch = avgSearch(hashSource, doubleHashArray, hashSize, DOUBLE_HASH);

    // RUns if you
	//linkedChainHash = createChainTable(hashSize);
	//fillChainedTable(linkedChainHash, hashSource, hashSize);
	//schainedSearch = searchChainedTable(linkedChainHash, hashSource, hashSize);
	//cout << chainedSearch;


	return 0;
}
