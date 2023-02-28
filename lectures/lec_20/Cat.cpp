#include <iostream>
#include "Cat.h"

using namespace std;

Cat::Cat(){
    cout << "Cat was created" << endl;
    happy = true;
}

Cat::~Cat(){
    cout << "Cat was destroyed" << endl;
}

void Cat::speak(){
    if(happy){
        cout << "Meowwwww!" << endl;
    }
    else{
        cout << "Ssssssss!" << endl;
    }
}

void Cat::jump(){
    cout << "Jumped out of the window!" << endl;
}

void Cat::makeHappy(){
    happy = true;
}

void Cat::makeSad(){
    happy = false;
}