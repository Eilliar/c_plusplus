#include <SDL2/SDL.h>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <math.h>
#include "Screen.h"
#include "Swarm.h"

using namespace std;

int main(int argv, char** args)
{

    srand(time(NULL)); // seed random number generator
    pqsr2::Screen screen;
    float BASE_RATE = 0.001;

    if(screen.init() == false){
        cout << "Error during screen initialization." << endl;
        return 1;
    }

    pqsr2::Swarm swarm;
    // Game Loop
    // Update particles
    // Draw particles
    // Check message//events
    while(true){
        if(screen.processEvents() == false) { break; }

        const pqsr2::Particle * particle = swarm.getParticle();
        double r;
        int elapsed = SDL_GetTicks64();
        unsigned char red = (1 + sin(elapsed * BASE_RATE)) * 128;
        unsigned char green = (1 + sin(elapsed * BASE_RATE * 0.5)) * 128;
        unsigned char blue = (1 + sin(elapsed * BASE_RATE * 5)) * 128;

        for(int i = 0; i < pqsr2::Swarm::NPARTICLES; i++){
            // Transform from [-1, 1] particle space to screen resolution space
            int x = (particle[i].m_x + 1) * pqsr2::Screen::SCREEN_WIDTH;
            int y = (particle[i].m_y + 1) * pqsr2::Screen::SCREEN_HEIGHT;

            screen.setPixel(x, y, red, green, blue, 255);
        }
        
        screen.update();
    }

    screen.close();

    return 0;
}