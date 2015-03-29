//---------------------------------------------------------------------------
//FILE NAME: valero-assn3-funcs.h
//DESIGNER:	Eric Valero
//DESCRIPTION: This file provides all function prototypes and
//				data types to Valero.cpp
//CLASS&TERM:	CS372/Spring 8wk2
//---------------------------------------------------------------------------


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
