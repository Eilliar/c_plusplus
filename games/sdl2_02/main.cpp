#include <iostream>
#include <SDL2/SDL.h>
#include <math.h>

using namespace std;

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 960;
const int SQUARE_SIZE = 10;
const int CIRCLE_RADIUS = 10;
const int RAYCAST_SIZE = 5;
const unsigned int MAX_RAYCAST_LENGTH = (unsigned int) sqrt(pow(SCREEN_WIDTH, 2)  + pow(SCREEN_HEIGHT, 2));
const int RAYCAST_ANGLE_STEP = 1;

struct wall {
  int startX;
  int startY;
  int endX;
  int endY;
};


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
    wall Wall1;
    Wall1.startX = 1000;
    Wall1.startY = 60;
    Wall1.endX = 1000;
    Wall1.endY = 360;

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
        // PLayer
        drawFilledCircle(mouseX, mouseY, CIRCLE_RADIUS);

        // Walls
        SDL_RenderDrawLine(gRenderer, Wall1.startX, Wall1.startY, Wall1.endX, Wall1.endY);
        
        // Raycast
        for(int k=0; k<360; k++){
            if(k % RAYCAST_ANGLE_STEP == 0){
                // Project the raycast to maximum value
                int endY = (int) (mouseY + MAX_RAYCAST_LENGTH * sin(k * (M_PI / 180)));
                int endX = (int) (mouseX + MAX_RAYCAST_LENGTH * cos(k * (M_PI / 180)));

                // Do the casting
                // source https://en.wikipedia.org/wiki/Line%E2%80%93line_intersection
                int x1 = Wall1.startX;
                int y1 = Wall1.startY;
                int x2 = Wall1.endX;
                int y2 = Wall1.endY;
                int x3 = mouseX;
                int y3 = mouseY;
                int x4 = endX;
                int y4 = endY;
                
                float den = (float) ((x1 - x2)*(y3 - y4) - (y1 - y2)*(x3 - x4));
                if(den != 0){
                    float t = (float) ((x1 - x3)*(y3 -y4) - (y1 - y3)*(x3 -x4)) / den;
                    float u = (float) ((x1 - x3)*(y1 -y2) - (y1 - y3)*(x1 -x2)) / den;
                    if(t >=0 & t <= 1 & u >= 0 & u <= 1){
                        // There is an intersection, so
                        // find the point of intersection
                        endX = (int) x1 + t*(x2 - x1);
                        endY = (int) y1 + t*(y2 - y1);
                        SDL_RenderDrawLine(gRenderer, mouseX, mouseY, endX, endY);
                    }
                }
            }
        }

        // Show
        SDL_RenderPresent(gRenderer);
    }

    close();

    return 0;
}
