#include "Animal.h"

using namespace std;

int main(){

    Animal animal;

    animal.setName("Abreu");
    animal.speak();
    
    int value = 10;

    const int *pValue = &value;

    cout << "\nValue is " << value << endl;
    cout << "pValue points to value " << *pValue << endl;

    value = 8;

    cout << "\nValue is " << value << endl;
    cout << "pValue points to value " << *pValue << endl;

    int newValue = 10;

    // Error since we cannot change the value stored where the pointer is pointing to
    // *pValue = newValue;
    // cout << "\nValue is " << value << endl;
    // cout << "pValue points to value " << *pValue << endl;

    // Error since we cannot change where the pointer is pointing to
    // int * const pValue2 = &value;
    // pValue2 = &newValue;

    // cout << "\nValue is " << value << endl;
    // cout << "pValue points to value " << *pValue2 << endl;
    
    return 0;
}