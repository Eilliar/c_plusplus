#include <iostream>

using namespace std;

void doSomething1(int value) {
    value = 1238;
}

void doSomething2(int &value) {
    value = 1238.33;
}
// References
int main(){

    int value1 = 8;
    int value2 = value1;
    int &value3 = value1;

    value1 = 42;

    cout << "Value1: " << value1 << endl;
    cout << "value2: " << value2 << endl;
    cout << "Value3: " << value3 << endl;

    doSomething1(value1);
    cout << "Value1: " << value1 << endl;
    doSomething2(value1);
    cout << "Value1: " << value1 << endl;

    return 0;
}