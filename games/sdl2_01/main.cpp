#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

int main(int argv, char** args)
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
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

    // Renderer used to draw on screen
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

    if(renderer == NULL) { 
        cout << "Error: SDL_CreateRenderer failed" << endl; 
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 4;
    }
    if(texture == NULL) { 
        cout << "Error: SDL_CreateTexture failed" << endl; 
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 3;
    }

    // Create a buffer to store window background color and set it to WHITE (0xFF)
    Uint32 *buffer = new Uint32[SCREEN_WIDTH*SCREEN_HEIGHT];
    memset(buffer, 0xFF, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));

    SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH*sizeof(Uint32));
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);

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

    delete [] buffer;
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}