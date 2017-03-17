// *************************************
// Pointers.h
// *************************************
struct Distance
{
    int feet;
    float inches;
};

// Create an array of num random numbers 
int * createInts(int num);

// Reverse the Integer Array
void  reverseIntArr(int intArr[], int num);

// Print out the Integer Arry
void  printInArr(int intArr[], int num);

// Free up the dyanmic memory allocated for the integer array
void  freeIntArr(int intArr[]);

// Create an array of num doubles that contain Random values
double * createDbls(int num);

// Reverse the array of doubles
void   reverseDblArr(double * dblArr, int num);

// Print out the array of doubles
void   printDblArr(double * dblArr, int num);

// Free up the memory allocated to the array of doubles
void   freeDblArr(double * dblArr);

// Create an array of num Distance classes that contain random data
Distance *createDst(int num);

// Reverse the Distance Array
void   reverseDstArr(Distance dstArr[], int num);

// Print out the Distance array using the output method in the 
// Distance class
void   printDstArr(Distance dstArr[], int num);

// Free up the memory allocated for the Distance array
void   free(Distance dstArr[]);
