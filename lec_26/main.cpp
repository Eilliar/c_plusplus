#include <iostream>

using namespace std;

int main(){

    const int NSTRINGS = 5;
    string labels[NSTRINGS] = {"one", "two", "three", "four", "five"};
    string *pElement = labels; // a pointer to the first element

    cout << "\n### First ###" << endl;
    for(int i=0; i < sizeof(labels) / sizeof(string); i++) {
        cout << pElement[i] << " " << flush;
    }
    cout << "\npElement: " <<  *pElement << endl; // No changes on pointer, it keeps pointing at the start of the array

    cout << "\n### Second ###" << endl;
    for(int i=0; i < sizeof(labels) / sizeof(string); i++) {
        cout << *pElement << " " << flush;
        pElement++; // Increment pointer
    }
    cout << "\npElement: " << *pElement << endl; // Pointer changes to memory address outside array

    cout << "\n### Third ###" << endl;
    string *pElement0 = &labels[0]; 
    string *pEnd = &labels[NSTRINGS - 1];

    while(true){
        cout << *pElement0 << " " << flush;
        
        if(pElement0 == pEnd){
            break;
        }
        pElement0++;
    }
    cout << "\npElement0: " << *pElement0 << endl; // Pointer changes to last element of the array

    pElement0 = &labels[0];
    cout << "\n### Another way to get size of array ###" << endl;
    cout << "Size of labels array: " << (long)(pEnd - pElement0 + 1) << endl;

    return 0;
}