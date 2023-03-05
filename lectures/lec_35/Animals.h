#ifndef ANIMALS_H_
#define ANIMALS_H_

#include <iostream>

using namespace std;

namespace animals {
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
