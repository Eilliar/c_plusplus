#ifndef DOG_H_
#define DOG_H_

#include <iostream>

using namespace std;

namespace dogo{
    class Dog
    {
    private:
        string name;
    public:
        Dog(string name): name(name){};
        ~Dog(){};
        void Speak();
    };
}

#endif