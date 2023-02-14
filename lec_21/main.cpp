#include <iostream>
#include <sstream> // needed to use string stream
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

    stringstream personInfo;

    personInfo << "Name is ";
    personInfo << person.getName();
    personInfo << ", with ";
    personInfo << person.getAge();
    personInfo << " years old";

    cout << personInfo.str() << endl;

    return 0;
}
