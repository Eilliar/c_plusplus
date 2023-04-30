#include <iostream>

using namespace std;

class Animal
{
public:
    Animal(){};
    virtual ~Animal(){};
    virtual void speak(){
        cout << "????????????" << endl;
    };
};
 
class Dog: public Animal {
public:
    Dog(){};
    virtual ~Dog(){};
    virtual void speak(){
        cout << "rrRRrrrRRRrrrRRR" << endl;
    }

    void jump(){
        cout << "dog just jumped!" << endl;
    }
};

int main(){
    // Polymorphism example
    // Still don't know why someone would do this
    Animal *pDog = new Dog();

    pDog->speak();
    // This yield error: 'class Animal' has no member named 'jump'
    // pDog->jump();

    delete pDog;

    return 0;
}