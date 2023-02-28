#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    
    for(int i=0; i<10; i++){
        cout << "Hello: " << i << endl;
    }

    for(int k=0; k<5; k++){
        cout << "k is " << k << endl;

        if(k==3) break;
    }

    const string password = "hello";
    string input;

    do {
        cout << "Enter the password> " << flush;
        cin >> input;
        
        if(input == password){
            break;
        }
        cout << "Wrong password." << endl;

    } while (true);
    
    cout << "Access granted!" << endl;

    return 0;
}