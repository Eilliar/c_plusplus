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
    Person(): name("undefined"), age(0) {};
    Person(string name): name(name), age(0) {};
    Person(string name, int age): name(name), age(age) {};
    
    // Destructor
    ~Person();

    // Setters
    void setName(string name);
    void setAge(int age);
    // Getters
    string getName();
    int getAge();

    // Other Methods
    string toString();
};

#endif