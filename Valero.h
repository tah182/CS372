//implemented by Eric Valero
//this file provides all function headers to Valero.cpp

//structures
struct chainNode{
	int key;
	chainNode* next;
};

//prototypes
chainNode* createChainTable();
chainNode* getHash(chainNode*, int, int);

