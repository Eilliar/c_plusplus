#include <iostream>
#include "Person.h"

using namespace std;

int main(){

    Person person1;
    Person person2("Chaya");
    Person person3("Bruninha", 28);

    // Memory address pointer accessed using '&'
    cout << person1.toString() << ", located at Memory address" << &person1 << endl;
    cout << person2.toString() << ", located at Memory address" << &person2 << endl;
    cout << person3.toString() << ", located at Memory address" << &person3 << endl;

    return 0;
}
