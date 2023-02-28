#include "Animal.h"

using namespace std;

Animal::Animal(){};

Animal::~Animal(){};

void Animal::setName(string name){
    this->name = name;
}

void Animal::speak() const {
    cout << "My name is " << this->name << endl;
    // this->name = "José"; // This will yield an error, since the method is constant
}