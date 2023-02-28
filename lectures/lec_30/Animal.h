#ifndef ANIMAL_H_
#define ANIMAL_H_

#include <iostream>

using namespace std;

class Animal
{
private:
    string name;
public:
    Animal();
    ~Animal();
    void setName(string name);
    void speak() const;
};


#endif
