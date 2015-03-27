#include <iostream>
#include "common.h"
#include "Valero.h"
#include "Tatsumoto.h"

using namespace std;

int main() {

    cout << "*****Tatsumoto-Valero-assn3-prog*****" << endl;
    cout << "This program will assess statistics behind:" << endl;
    cout << "    - linear probe hashing" << endl;
    cout << "    - double hashing" << endl;
    cout << "    - separated chain hashing" << endl;
    cout << "and compare against Knuth averages." << endl << endl;

//    int* intArray = makeRandArray();

    int* linearHash = linearProbeHash(intArray);
	chainNode** test;
	int hashSource[SOURCESIZE];
	fillTable(hashSource);
	test = createChainTable();


	return 0;
}
