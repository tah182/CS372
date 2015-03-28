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
	if (linearHash)
    	linearProbeHash(linearHash, hashSource, hashSize);
    else
    	cout << "Error- out of heap memory" << endl;

    int* doubleHashArray = new (nothrow) int[hashSize];
    if (doubleHashArray)
    	//doubleHash(doubleHashArray, hashSource, hashSize);
    	cout << "skipped double";
    else
    	cout << "Error- out of heap memory" << endl;

	linkedChainHash = createChainTable(hashSize);
	fillChainedTable(linkedChainHash, hashSource, hashSize);
	schainedSearch = searchChainedTable(linkedChainHash, hashSource, hashSize);
	cout << chainedSearch;


	return 0;
}
