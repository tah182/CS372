#include <iostream>
#include "common.h"
#include "Valero.h"
#include "Tatsumoto.h"

using namespace std;

int main() {
<<<<<<< HEAD
	chainNode** test;
	chainNode* location;
	int hashSource[SOURCESIZE];
	fillTable(hashSource);
	test = createChainTable();
	
	location = getHash(test, 1, 8);

return 0;		
=======
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

	getHash(test, 1, 8);

	return 0;
>>>>>>> 8c30703227d8d324c43735be43b0a3c55967b9a3
}
