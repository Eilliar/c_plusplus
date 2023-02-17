#include <iostream>

using namespace std;

int main(){

    string labels[] = {"one", "two", "three", "four", "five"};
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
    string *pEnd = &labels[4];

    while(true){
        cout << *pElement0 << " " << flush;
        
        if(pElement0 == pEnd){
            break;
        }
        pElement0++;
    }
    cout << "\npElement0: " << *pElement0 << endl; // Pointer changes to last element of the array

    return 0;
} 