#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    int value1 = 5;
    int value2 = 7;

    if(value1 == 7  && value2 <= 10){
        cout << "Condition 1: True"<< endl;
    }
    else {
        cout << "Condition 1: False" << endl;
    }

    if(value1 == 7 || value2 < 10){
        cout << "Condition 2: True" << endl;
    }
    else{
        cout << "Condition 2: False" << endl;
    }

    if(value1 != 8 && value2 == 10 || value2 < 10){
        cout << "Condition 3: True" << endl;
    }
    else {
        cout << "Condition 3: False" << endl;
    }

    bool condition1 = (value1 != 8) && (value2 == 10);
    bool condition2 = (value2 < 10);

    if(condition1 || condition2){
        cout << "Condition 4: True" << endl;
    }
    else {
        cout << "Condition 4: False" << endl;
    }
    
    return 0;
}