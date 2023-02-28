#include "Animal.h"

int main(){
    
    // No memory allocation management needed
    Animal animal1 = Animal();
    animal1.SetName("Aysha");
    animal1.SetSpecies("Dog");
    animal1.Speak();

    // Using new requires memory allocation management
    Animal *pAnimal2 = new Animal();
    pAnimal2->SetName("Chaya");
    pAnimal2->SetSpecies("Cat");
    pAnimal2->Speak();
    // Notice no destructor is call unless we call delete
    delete pAnimal2;
    
    return 0;
}