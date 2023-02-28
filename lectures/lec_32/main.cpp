#include "Animal.h"

Animal *createAnimal(string name, string species){
    Animal *pAnimal = new Animal();
    pAnimal->SetName(name);
    pAnimal->SetSpecies(species);

    return pAnimal;
}

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

    // Returning an object from a function is more efficient using pointers
    // but since we need to use new operator, we also will need to call delete
    // to deallocate memory

    Animal *pAnimal3 = createAnimal("Bally", "Pig");
    pAnimal3->Speak();
    delete pAnimal3;
    
    return 0;
}