#include <iostream>

using namespace std;

int main() {
    int input;

    cout << "### Welcome to Skynet, please select an option." << endl;
    cout << "1. Add a new record" << endl;
    cout << "2. Delete a record" << endl;
    cout << "3. Search for a record" << endl;
    cout << "4. Quit" << endl;

    cout << "> " << flush;
    cin >> input;

    switch (input)
    {
    case 1:
        cout << "Adding a new record..." << endl;
        break;
    case 2:
        cout << "Deleting a record..." << endl;
        break;
    case 3:
        cout << "Searching for a record..." << endl;
        break;
    case 4:
        cout << "Quitting..." << endl;
        break;
    default:
        cout << "Unrecognized option..." << endl;
        break;
    }

    cout << "System failure..." << endl;    
    return 0;
}