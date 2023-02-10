#include <iostream>
#include <typeinfo>

using namespace std;

int main() {
    
    int firstArray[4] = {1, 4, 2, 5};

    cout << "Bytes of the entire array: " << sizeof(firstArray) << endl;
    cout << "Bytes of the type used in array element: " << sizeof(int) << endl;

    for(int i=0; i < sizeof(firstArray)/sizeof(int); i++){
        cout << firstArray[i] << " " << flush;
    }

    cout << endl;

    int secondArray[][2] = {
        {1, 2},
        {3, 5}
    };

    cout << sizeof(secondArray) << endl;
    for(int i=0; i < sizeof(secondArray) / sizeof(secondArray[0]);i++){
        for(int k=0; k < sizeof(secondArray[0]) / sizeof(int); k++){
            cout << secondArray[i][k] << " " << flush;
        }
        cout << endl;
    }

    int thirdArray[][3] = {
        {1, 8, 7}
    };

    cout << sizeof(thirdArray) << endl;
    for(int i=0; i < sizeof(thirdArray) / sizeof(thirdArray[0]);i++){
        for(int k=0; k < sizeof(thirdArray[0]) / sizeof(int); k++){
            cout << thirdArray[i][k] << " " << flush;
        }
        cout << endl;
    }
    return 0;
}