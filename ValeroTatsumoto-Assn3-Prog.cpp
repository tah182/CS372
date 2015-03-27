#include <iostream>
#include "common.h"
#include "Valero.h"
#include "Tatsumoto.h"

//test data for push

using namespace std;

int main() {
//variables
	chainNode** test;
	int hashSource[SOURCESIZE];
	fillTable(hashSource);
	int hashSize;

    cout << "*****Tatsumoto-Valero-assn3-prog*****" << endl;
    cout << "This program will assess statistics behind:" << endl;
    cout << "    - linear probe hashing" << endl;
    cout << "    - double hashing" << endl;
    cout << "    - separated chain hashing" << endl;
    cout << "and compare against Knuth averages." << endl << endl;

	hashSize = getHashSize();
	int hashTable[hashSize];
    allocArray(hashTable, hashSize);
    linearProbeHash(hashTable, hashSource, hashSize);

//	test = createChainTable(hashSize);


	return 0;
}
