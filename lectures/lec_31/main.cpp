#include "Animal.h"

int main(){

    Animal animal1 = Animal();
    animal1.SetName("Aysha");
    animal1.SetSpecies("Dog");

    Animal animal2 = animal1;

    animal1.Speak();
    animal2.Speak();

    return 0;
}