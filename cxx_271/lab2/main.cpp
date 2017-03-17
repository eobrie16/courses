#include <iostream>
using namespace std;

void myCopy(int dest[], int src[], int num, 
            int deststart=0, int srcstart=0);
void myCopy(double dest[], double src[], int num, 
            int deststart=0, int srcstart=0);
void multiply(double result[], double operand1[], 
              double operand2[], int num);

void myPrint(int arr[],    int num, int start=0);
void myPrint(double arr[], int num, int start=0);

int main()
{
    int idest1[10];
    int isrc1[] = {1,2,3,4,5,6,7};
    double ddest1[10];
    double dsrc1[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.1};
    double op1[5], op2[5], result[5];

    myCopy(idest1, isrc1, 7);
    cout << endl << "myPrint(idest1,7)" << endl;
    myPrint(idest1, 7);
    
    myCopy(ddest1, dsrc1, 5, 1, 3);
    cout << endl << "myPrint(ddest1, 5, 1)" << endl;
    myPrint(ddest1, 5, 1);

    myCopy(op1, dsrc1, 5, 0, 0);
    myCopy(op2, dsrc1, 5, 0, 5);
    multiply(result, op1, op2, 5);
    
    cout << endl << "myPrint(result, 5, 0)" << endl;
    myPrint(result, 5, 0);
}

void myCopy(int dest[], int src[], int num, int deststart, int srcstart)
{
	for (int i=0; i<num; i++)
		dest[deststart+i] = src[srcstart+i];
		
}

void myCopy(double dest[], double src[], int num, int deststart, int srcstart)
{
	for (int i=0; i<num; i++)
		dest[deststart+i] = src[srcstart+i];
}

void multiply(double result[], double operand1[], double operand2[], int num)
{
	for (int i=0; i<num; i++)
	{
		result[i] = operand1[i] * operand2[i];
	}
}

void myPrint(int arr[], int num, int start)
{
	for (int i=start; i<start+num; i++)
		cout << "arr[" << i << "]=" << arr[i] << endl; 
}

void myPrint(double arr[], int num, int start)
{
	for (int i=start; i<start+num; i++)
		cout << "arr[" << i << "]=" << arr[i] << endl; 
}
