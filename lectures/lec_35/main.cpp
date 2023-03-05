#include "Animals.h"
#include "Dog.h"

using namespace std;
using namespace animals; // default namespace used when using class Dog

int main(){

    Dog dog1 = Dog("Aysha");
    dog1.Speak();

    dogo::Dog dog2 = dogo::Dog("Chaya");
    dog2.Speak();

    animals::Dog dog3 = animals::Dog("Nala");
    dog3.Speak();

    return 0;
}