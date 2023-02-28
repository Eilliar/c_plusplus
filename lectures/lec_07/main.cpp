#include <iostream>

using namespace std;

int main() {

    cout << "1. Add a new record. " << endl;
    cout << "2. Delete a record. " << endl;
    cout << "3. View a record. " << endl;
    cout << "4. Search for a record. " << endl;
    cout << "5. Quit. " << endl;
    
    int input;
    cout << "Enter your option > " << flush;
    cin >> input;

    if(input == 1){
        cout << "Adding new record..." << endl;
    }
    else if(input == 2) {
        cout << "Deleting a record..." << endl;
    }
    else if(input == 3){
        cout << "Viewing a record..." << endl;
    }
    else if(input == 4){
        cout << "Searching for a record..." << endl;
    }
    else if(input == 5){
        cout << "Quiting..." << endl;
    }
    else {
        cout << "Option not available" << endl;
    }
    
    return 0;
}