#include <iostream>
#include "Cat.h"

using namespace std;


int main(){

    cout << "Starting the program..." << endl;

    {
        // Not common, but using {} one can create an scope, 
        // where cat will be created and out of the scope it's destroyed
        Cat myCat;
        myCat.speak();
        myCat.jump();
    }

    cout << "Ending the program..." << endl;
    return 0;
}
