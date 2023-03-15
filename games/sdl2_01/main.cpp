#include <SDL2/SDL.h>
#include <iostream>
#include "Screen.h"
using namespace std;

int main(int argv, char** args)
{

    pqsr2::Screen screen;

    if(screen.init() == false){
        cout << "Error during screen initialization." << endl;
        return 1;
    }

    // Game Loop
    // Update particles
    // Draw particles
    // Check message//events
    while(true){
        if(screen.processEvents() == false) { break; }
    }

    screen.close();
    return 0;
}