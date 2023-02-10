#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    
    const string password = "hello";
    string input;

    do {
        cout << "Enter the password> " << flush;
        cin >> input;

        if(input != password){
            cout << "Incorrect password!" << endl;
        }

    } while(input != password);

    cout << "Access granted!" << endl;

    return 0;
}