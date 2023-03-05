#include "Test.h"

int main(){

    cout << Test::MAX << endl;
    Test::ShowCount();

    Test test1;
    test1.ShowInfo();
    Test test2;
    test2.ShowInfo();

    // As static private variable, it belongs to the class, not the objects
    // so we can access it and count how many objects there are from this class
    Test::ShowCount();

    return 0;
}