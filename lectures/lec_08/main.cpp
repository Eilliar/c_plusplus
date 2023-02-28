#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    float value1 = 1.1;

    if(value1 == 1.1){
        cout << "equal" << endl;
    }
    else if(value1 - 1.1 <= 0.0001){
        cout << "equal" << endl;
    }
    else {
        cout << "not equal" << endl;
    }

    cout << setprecision(10) << value1 << endl;
    
    return 0;
}