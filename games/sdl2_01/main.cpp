#include <SDL2/SDL.h>
#include <iostream>
#include <iomanip>
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
        
        for(int y=0; y<pqsr2::Screen::SCREEN_HEIGHT; y++){
            for (int x=0; x<pqsr2::Screen::SCREEN_WIDTH; x++){
                screen.setPixel(x, y, 86, 101, 115, 255);
            }
        }
        
        screen.update();
    }

    screen.close();

    return 0;
}