#include <iostream>
#include <sstream>
#include "Person.h"

using namespace std;

Person::Person()
{
    name = "undefined";
    age = 0;
}

Person::Person(string newName){
    name = newName;
    age = 0;
}

Person::Person(string newName, int newAge){
    name = newName;
    age = newAge;
}

Person::~Person(){
    cout << "I'm going to die!" << endl;
}

string Person::toString(){
    stringstream personInfo;

    personInfo << "Name is ";
    personInfo << name;
    personInfo << ", with ";
    personInfo << age;
    personInfo << " years old";

    return personInfo.str();
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