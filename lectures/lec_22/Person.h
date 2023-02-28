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
    Person(string name);
    Person(string name, int age);
    // Destructor
    ~Person();

    // Other Methods
    string toString();
    
    // Setters
    void setName(string name);
    void setAge(int age);
    // Getters
    string getName();
    int getAge();
};

#endif