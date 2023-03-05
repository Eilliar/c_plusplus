#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

int main(int argv, char** args)
{
    if(SDL_Init(SDL_INIT_VIDEO) <0){
        cout << "Error: SDL_Init failed" << endl;
    }

    cout << "SDL Video Initialization complete!" << endl;
    SDL_Quit();

    return 0;
}