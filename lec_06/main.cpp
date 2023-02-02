#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    string password = "1123581321";

    cout << "Enter your password> " << flush;
    
    string input;
    cin >> input;

    if(input == password){
        cout << "Password accepted!" << endl;
        return 0;
    }
    
    cout << "Access denied!" << endl;
    return 0;
}