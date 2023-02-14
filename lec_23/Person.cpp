#include <iostream>
#include <sstream>
#include "Person.h"

using namespace std;

Person::~Person(){
    cout << "I'm going to die! Freeing memory location: " << this << endl;
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

void Person::setName(string name){
    this->name = name;
}

void Person::setAge(int age){
    this->age = age;
}

string Person::getName(){
    return name;
}

int Person::getAge(){
    return age;
}