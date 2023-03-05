#include <iostream>

using namespace std;

class Animal
{
private:
    string name;
    
public:
    Animal(string name): name(name) { cout << "[" << this->name << "] I'm born!" << endl; };
    ~Animal(){};
    void Speak() { cout << "[" << this->name << "] " << "Grrrrr!" << endl; };
    string GetName() const { return this->name; };
};

class Dog: public Animal{
    // inherit all constructors from Animal
    using Animal::Animal; 

public:
    void Jump() {cout << "[" << this->GetName() << "] " << "Jumping..." << endl; };
};

class Wolf: public Dog{
public:
    // Notice that will call constructor from super class
    Wolf(string name): Dog(name) { cout << "[" << this->GetName() << "] Aww shit!" << endl; };
    void Attack() { cout << "[" << this->GetName() << "] " << "Attacking..." << endl; };
};

int main(){

    Animal animal1 = Animal("Rat");
    animal1.Speak();

    Dog animal2 = Dog("Chaya");
    animal2.Speak();
    animal2.Jump();

    Wolf animal3 = Wolf("Nala");
    animal3.Speak();
    animal3.Jump();
    animal3.Attack();

    return 0;
}