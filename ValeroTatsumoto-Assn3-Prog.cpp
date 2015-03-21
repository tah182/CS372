#include <iostream>
#include "common.h"
#include "Valero.h"
#include "Tatsumoto.h"

using namespace std;

int main() {
	
	int hashSource[SOURCESIZE];
	fillTable(hashSource);
	
	for(int i=0;i<5000;i++)
		cout << hashSource[i] << endl;
		
	return 0;
}
