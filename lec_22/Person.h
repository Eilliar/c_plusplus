#ifndef PERSON_H
#define PERSON_H

#include <iostream>

using namespace std;

class Person
{
private:
    string name;
    int age;

public:
    // Diff Types of constructor
    Person();
    Person(string newName);
    Person(string newName, int age);
    // Destructor
    ~Person();

    // Other Methods
    string toString();
    
    // Setters
    void setName(string newName);
    void setAge(int newAge);
    // Getters
    string getName();
    int getAge();
};

#endif