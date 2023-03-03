#include "Animal.h"

Animal::Animal()
{
    cout << "I was born!" << endl;
}

Animal::~Animal()
{
    cout << "[" << this->name << "] " << "I'm dying!" << endl;
}

Animal::Animal(const Animal& other): name(other.name), species(other.species){ // make sure to copy data from other object
    cout << "I am a clone!" << endl;
}

void Animal::Speak(){
    cout << "My name is " << this->name << " and I'm a " << this->species << endl;
}

void Animal::SetName(string name){
    this->name = name;
}

void Animal::SetSpecies(string species){
    this->species = species;
}