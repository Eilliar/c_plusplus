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
    Person();
    ~Person();
    void setName(string newName);
    void setAge(int newAge);
    string getName();
    int getAge();
};

#endif