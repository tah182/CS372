#include <iostream>
#include "common.h"
#include "Valero.h"
#include "Tatsumoto.h"

using namespace std;

int main() {
	chainNode** test;
	chainNode* location;
	int hashSource[SOURCESIZE];
	fillTable(hashSource);
	test = createChainTable();
	
	location = getHash(test, 1, 8);

return 0;		
}
