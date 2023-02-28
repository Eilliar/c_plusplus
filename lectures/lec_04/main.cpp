#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    float f_value = 125.15;
    double d_value = 125.15;
    long unsigned int user_age = 6516421613218165168;

    cout << "User age: " << user_age << endl;

    cout << "Size of integer: " << sizeof(int) << endl;
    cout << "Size of short integer: " << sizeof(short int) << endl;
    cout << "Size of long integer: " << sizeof(long int) << endl;

    cout << "Float value: " << f_value << endl;
    cout << setprecision(20) << "Float value: " << f_value << endl;
    cout << scientific << "Float value scientific notation: " << f_value << endl;

    cout << "Double value: " << d_value << endl;
    cout << setprecision(20) << "Double value: " << d_value << endl;
    cout << scientific << "Double value scientific notation: " << d_value << endl;
    
    return 0;
}