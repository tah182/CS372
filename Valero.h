//implemented by Eric Valero
//this file provides all function headers to Valero.cpp

//structures
struct chainNode{
	int key;
	chainNode* next;
};

//prototypes
chainNode** createChainTable(int);
void putHash(chainNode*[], int, int);
void fillChainedTable(chainNode*[], int[], int);
double searchChainedTable(chainNode*[], int[], int);
