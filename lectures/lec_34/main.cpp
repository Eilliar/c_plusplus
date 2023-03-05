#include <iostream>

using namespace std;


char *getMemory(int nElements) {

    // allocate memory and return pointer since no local variable will persist
    static char *pMemory = new char[nElements];

    for(int k; k<=nElements; k++){
        pMemory[k] = ' ';
    }
    cout << "Memory allocated at " << hex << &pMemory << endl;
    return pMemory;
}

void freeMemory(char *pMemory){
    cout << "Deleting at memory " << hex << &pMemory << endl;
    delete [] pMemory;
}

int main(){

    int nElements = 10;
    char *pMem = getMemory(nElements);

    cout << "Memory allocated at " << hex <<  &pMem << endl;
    for(int k=0; k<nElements; k++){
        cout << "Element " << k << ": " << pMem[k] << endl;
    }

    freeMemory(pMem);

    return 0;
}