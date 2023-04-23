#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 960;
const int SQUARE_SIZE = 10;
const int CIRCLE_RADIUS = 10;

SDL_Window* gWindow = nullptr;
SDL_Renderer* gRenderer = nullptr;

int mouseX = SCREEN_WIDTH / 2;
int mouseY = SCREEN_HEIGHT / 2;

bool init();
void close();
void drawSquare(int x, int y, int size);

bool init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
        return false;
    }

    gWindow = SDL_CreateWindow("Raycast 2D", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (gWindow == nullptr)
    {
        cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
        return false;
    }

    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_PRESENTVSYNC);
    if (gRenderer == nullptr)
    {
        cout << "Renderer could not be created! SDL_Error: " << SDL_GetError() << endl;
        return false;
    }

    SDL_ShowCursor(false);
    return true;
}

void close()
{
    SDL_DestroyRenderer(gRenderer);
    gRenderer = nullptr;
    SDL_DestroyWindow(gWindow);
    gWindow = nullptr;
    SDL_Quit();
}

void drawSquare(int x, int y, int size)
{
    SDL_Rect rect = { x, y, size, size };
    SDL_RenderDrawRect(gRenderer, &rect);
}

void drawCircle(int centerX, int centerY, int radius)
{
    // draw a circle using the Midpoint Circle Algorithm
    // source: https://en.wikipedia.org/wiki/Midpoint_circle_algorithm
    int x = 0;
    int y = radius;
    int d = 3 - 2 * radius;

    while (x <= y)
    {
        SDL_RenderDrawPoint(gRenderer, centerX + x, centerY + y);
        SDL_RenderDrawPoint(gRenderer, centerX - x, centerY + y);
        SDL_RenderDrawPoint(gRenderer, centerX + x, centerY - y);
        SDL_RenderDrawPoint(gRenderer, centerX - x, centerY - y);
        SDL_RenderDrawPoint(gRenderer, centerX + y, centerY + x);
        SDL_RenderDrawPoint(gRenderer, centerX - y, centerY + x);
        SDL_RenderDrawPoint(gRenderer, centerX + y, centerY - x);
        SDL_RenderDrawPoint(gRenderer, centerX - y, centerY - x);

        if (d < 0)
        {
            d += 4 * x + 6;
        }
        else
        {
            d += 4 * (x - y) + 10;
            y--;
        }

        x++;
    }
}

void drawFilledCircle(int centerX, int centerY, int radius)
{
    int x = 0;
    int y = radius;
    int d = 3 - 2 * radius;

    while (x <= y)
    {
        // Draw horizontal lines from the top to the bottom
        for (int i = centerX - x; i <= centerX + x; ++i)
        {
            SDL_RenderDrawPoint(gRenderer, i, centerY + y);
            SDL_RenderDrawPoint(gRenderer, i, centerY - y);
        }

        // Draw horizontal lines from the left to the right
        for (int i = centerX - y; i <= centerX + y; ++i)
        {
            SDL_RenderDrawPoint(gRenderer, i, centerY + x);
            SDL_RenderDrawPoint(gRenderer, i, centerY - x);
        }

        if (d < 0)
        {
            d += 4 * x + 6;
        }
        else
        {
            d += 4 * (x - y) + 10;
            y--;
        }

        x++;
    }
}

int main(int argc, char* args[])
{
    if (!init())
    {
        cout << "Failed to initialize SDL2!" << endl;;
        return -1;
    }

    bool quit = false;
    SDL_Event e;

    while (!quit)
    {
        // (1) Handle Input
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
            else if (e.type == SDL_MOUSEMOTION)
            {
                mouseX = e.motion.x;
                mouseY = e.motion.y;
            }
            else if (e.type == SDL_MOUSEBUTTONDOWN){
                switch (e.button.button)
                {
                case SDL_BUTTON_LEFT:
                    SDL_Log("left mouse clicked\n");
                    break;
                case SDL_BUTTON_RIGHT:
                    SDL_Log("right mouse clicked\n");
                    break;
                default:
                    break;
                }
            }
        }
        // (2) Handle Updates
        
        // (3) Clear and Draw
        // Gives us a clear canvas
        SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(gRenderer);
        
        // Render code goes here
        SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
        drawFilledCircle(mouseX, mouseY, CIRCLE_RADIUS);

        // Show
        SDL_RenderPresent(gRenderer);
    }

    close();

    return 0;
}
