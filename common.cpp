//contains functions which must be available to all cpp files

using namespace std;
#include "common.h"
#include <iostream>

//implemented by Eric Valero. 
//Gets the table size from user for declaring hash tables of dynamic size
int getTableSize() {
	int n;
	cout << "Enter a desired table size: ";
	cin >> n;
	cout << endl;
	
	return n;
}
