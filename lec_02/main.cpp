#include <iostream>
using namespace std;

int main() {

    int numberOfCats = 5;
    int numberOfDogs = 4;
    int numberOfAnimals = numberOfCats + numberOfDogs;

    cout << "Number of cats: " << numberOfCats << endl;
    cout << "Number of dogs: " << numberOfDogs << endl;

    cout << "Total number of animals: " << numberOfAnimals << endl;

    numberOfDogs += 1;

    cout << "New number of dogs: " << numberOfDogs << endl;
    
    return 0;
}