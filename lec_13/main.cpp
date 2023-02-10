#include <iostream>

using namespace std;

int main() {
    
    int firstArray[4];

    cout << "\n### First Array initialization ####" << endl;
    for(int i; i<4; i++){
        cout << "Element " << i << ": " << firstArray[i] << endl;
    }

    int secondArray[4] = {};

    cout << "\n### Second Array initialization ###" << endl;
    for(int i; i<4; i++){
        cout << "Element " << i << ": " << secondArray[i] << endl;
    }

    string thirdArray[4] = {"banana", "apple", "orange", "grape"};
    
    cout << "\n### Third Array initialization ###" << endl;
    for(int i; i<4; i++){
        cout << "Element " << i << ": " << thirdArray[i] <<  endl;
    }

    string fourthArray[] = {"banana", "apple", "juice"};
    
    cout << "\n### Fourth Array initialization ###" << endl;
    for(int i; i<4; i++){
        cout << "Element " << i << ": " << fourthArray[i] << endl;
    }

    return 0;
}