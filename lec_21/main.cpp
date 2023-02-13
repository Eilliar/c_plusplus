#include <iostream>
#include "Person.h"

using namespace std;

int main(){

    Person person;

    cout << "Initial person name is: " << person.getName() << endl;
    cout << "Initial person age is: " << person.getAge() << endl;
    
    person.setName("Sr. Sérgio");
    person.setAge(32);
    cout << "New person name is: " << person.getName() << endl;
    cout << "New person age is: " << person.getAge() << endl;
    
    return 0;
}
