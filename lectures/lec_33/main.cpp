#include "Animal.h"


int main(){
    int nAnimals = 10;
    Animal *pAnimal = new Animal[nAnimals];

    char letter = 'a';

    for (int i=0; i<nAnimals; i++){
        string name(1, letter + i);

        pAnimal[i].SetName(name);
        pAnimal[i].Speak();
    }

    delete[] pAnimal;

    return 0;
}