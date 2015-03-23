#include <iostream>
#include "common.h"
#include "Valero.h"
#include "Tatsumoto.h"

using namespace std;

int main() {
	chainNode* test;
	int hashSource[SOURCESIZE];
	fillTable(hashSource);
	test = createChainTable();
	
	getHash(test, 1, 10);
		
	return 0;
}
