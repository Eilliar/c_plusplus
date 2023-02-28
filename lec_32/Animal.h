#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

using namespace std;
class Animal
{
private:
    string name;
    string species;
public:
    Animal(); 
    ~Animal();
    Animal(const Animal& other); // Copy constructor
    void Speak();
    void SetName(string name);
    void SetSpecies(string species);
    
};

#endif