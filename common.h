//global constants
const int SOURCESIZE = 5000;

//global data structures

//global prototypes
int getTableSize();
void fillTable(int[]);
int getHashSize();
void displayIntro();

//**************************************************************************
// ENUM::     ProbeMethod
// DESCRIP:   Enum for Probe Emthod
//**************************************************************************
enum ProbeMethod {
    LINEAR_PROBE,
    DOUBLE_HASH,
    CHAIN_HASH
};

float knuthPrediction (ProbeMethod probeMethod, int hashSize);
int searchInt(int hashTable[], int hashSize, int num, ProbeMethod probeMethod);
int avgSearch(int intArray[], int hashTable[], int hashSize, ProbeMethod probeMethod);
