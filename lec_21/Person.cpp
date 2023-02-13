#include <iostream>
#include "Person.h"

using namespace std;

Person::Person()
{
    name = "Lima Maria";
}

Person::~Person(){
    cout << "I'm going to die!" << endl;
}

void Person::setName(string newName){
    name = newName;
}

void Person::setAge(int newAge){
    age = newAge;
}

string Person::getName(){
    return name;
}

int Person::getAge(){
    return age;
}