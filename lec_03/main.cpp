#include <iostream>
using namespace std;

int main() {

    string prompt_name_msg = "Enter your name: ";
    string prompt_age_msg = "Enter your age: ";
    string user_name;
    int user_age;

    cout << prompt_name_msg << flush;
    getline(cin, user_name);

    cout << prompt_age_msg << flush;
    cin >> user_age;
    
    cout << "Welcome " << user_name << ", you said you have " << user_age << " years." <<endl;
    
    return 0;
}