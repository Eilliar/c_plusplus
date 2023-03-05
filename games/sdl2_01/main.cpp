#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

int main(int argv, char** args)
{
    if(SDL_Init(SDL_INIT_VIDEO) <0){
        cout << "Error: SDL_Init failed" << endl;
        return 1;
    }

    cout << "SDL Video Initialization complete!" << endl;

    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;
    SDL_Window *window = SDL_CreateWindow("Particle explosion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if(window == NULL){
        cout << "Error: SDL_Window failed" << endl;
        SDL_Quit();
        return 2;
    }

    bool quit = false;
    SDL_Event event;
    // Game Loop
    // Update particles
    // Draw particles
    // Check message//events
    while(!quit){
        
        while (SDL_PollEvent(&event)){
            switch(event.type)
            {
            case SDL_QUIT:
                quit = true;
                break;
            
            default:
                break;
            }
        }
        
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}