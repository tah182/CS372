#include <iostream>
#include "common.h"
#include "Valero.h"
#include "Tatsumoto.h"

using namespace std;

<<<<<<< HEAD
int main() {
	chainNode** test;
	chainNode* location;
	int hashSource[SOURCESIZE];
	fillTable(hashSource);
	test = createChainTable();
	
	location = getHash(test, 1, 8);
		
=======
int main() {
    int* intArray = makeRandArray();

//	chainNode** test;
//	int hashSource[SOURCESIZE];
//	fillTable(hashSource);
//	test = createChainTable();

//	getHash(test, 1, 8);

>>>>>>> 7cd816b60055f52f47a058ce029874f43e1a3125
	return 0;
}
