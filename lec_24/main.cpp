#include <iostream>

using namespace std;

void manipulate1(double value){
    cout << "1. Input value is: " << value << endl;
    value = 100.5;
    cout << "2. Input value after manipulation is: " << value << endl;
    
    return;
}

void manipulate2(double *value){
    cout << "1. Input value is: " << *value << endl;
    *value = 100.5;
    cout << "2. Input value after manipulation is: " << *value << endl;

    return;
}

int main(){

    int value = 9;
    int *pValue = &value;

    cout << "Int value is " << value << endl;
    cout << "Int value address is " << pValue << endl;
    cout << "Int value via pointer is " << *pValue << endl;

    double dValue = 148.2;
    cout << "\n######## Manipulate 1 ########" << endl;
    cout << "Double value before manipulate1 call is: " << dValue << endl;
    manipulate1(dValue);
    cout << "Double value after manipulation1 call is: " << dValue << endl;

    cout << "\n######## Manipulate 2 ########" << endl;
    cout << "Double value before manipulate2 call is: " << dValue << endl;
    manipulate2(&dValue);
    cout << "Double value before manipulate2 call is: " << dValue << endl;
    return 0;
}
