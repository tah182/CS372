//--------------------------------------------------------------------------
//FILE NAME: tatsumotovalero-assn3-common.h
//DESCRIPTION:	contains global constants, prototypes, and enum types
//DESIGNER:	Eric Valero and Takashi Tatsumoto
//CLASS&TERM: CS372/Spring 8wk2
//--------------------------------------------------------------------------

#include <iostream>
#include <stdlib.h>			//used for rand, srand functions(Eric Valero)
#include <time.h>			//used to seed rand(Eric Valero)
#include <math.h>

using namespace std;

//**************************************************************************
// ENUM::     ProbeMethod
// DESCRIP:   Enum for Probe Emthod
// AUTHOR:	  Takashi Tatsumoto
//**************************************************************************
enum ProbeMethod {
    LINEAR_PROBE,
    DOUBLE_HASH,
    CHAIN_HASH
};

//global constants implemented by Eric Valero
const int SOURCESIZE = 5000;
const int BIGINCREMENT = 2;
const int TOOBIG = 30000;

//global prototypes implemented by Eric Valero
int getTableSize();
void fillTable(int[]);
int getHashSize();
void displayIntro();

//global prototypes implemented by Takashi Tatsumoto
float knuthPrediction (ProbeMethod probeMethod, int hashSize);
int searchInt(int hashTable[], int hashSize, int num, ProbeMethod probeMethod);
int avgSearch(int intArray[], int hashTable[], int hashSize, ProbeMethod probeMethod);
