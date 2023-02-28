#include <iostream>

using namespace std;

int main() {
    
    int firstArray[4];

    cout << "\n### First Array initialization ####" << endl;
    for(int i=0; i<4; i++){
        cout << "Element " << i << ": " << firstArray[i] << endl;
    }

    int secondArray[4] = {};

    cout << "\n### Second Array initialization ###" << endl;
    for(int i=0; i<4; i++){
        cout << "Element " << i << ": " << secondArray[i] << endl;
    }

    string thirdArray[4] = {"banana", "apple", "orange", "grape"};
    
    cout << "\n### Third Array initialization ###" << endl;
    for(int i=0; i<4; i++){
        cout << "Element " << i << ": " << thirdArray[i] <<  endl;
    }

    string fourthArray[] = {"banana", "apple", "juice"};
    
    cout << "\n### Fourth Array initialization ###" << endl;
    for(int i=0; i<4; i++){
        cout << "Element " << i << ": " << fourthArray[i] << endl;
    }

    // 2D Arrays
    string first2DArray[2][3] = {
        {"dog", "cat", "mouse"},
        {"horse", "cow", "chicken"}
    };

    cout << "\n### First 2D Array initialization ###" << endl;
    for(int i=0; i<2; i++){
        for(int k=0; k<3; k++){
            cout << first2DArray[i][k] << " " << flush;
        }
        cout << endl;
    }

    int second2DArray[2][5] = {
        {0, 1, 2, 3, 4},
        {5, 6, 7, 8, 9}
    };
    int alpha = 10;

    cout << "\n### Second 2D Array initialization ###" << endl;
    for(int i=0; i<2; i++){
        for(int k=0; k<5; k++){
            cout << second2DArray[i][k] * alpha << " " << flush;
        }
        cout << endl;
    }

    return 0;
}