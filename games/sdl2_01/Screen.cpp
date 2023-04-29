#include "Screen.h"

namespace pqsr2 {
    Screen::Screen(): m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer1(NULL), m_buffer2(NULL){
    }

    bool Screen::init(){
        if(SDL_Init(SDL_INIT_VIDEO) < 0){
            return false;
        }
        m_window = SDL_CreateWindow("Particle explosion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

        if(m_window == NULL){
            SDL_Quit();
            return false;
        }

        // Renderer used to draw on screen
        m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
        // m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_SOFTWARE); // Does it use only CPU?
        m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

        if(m_renderer == NULL) { 
            SDL_DestroyWindow(m_window);
            SDL_Quit();
            return 4;
        }
        if(m_texture == NULL) { 
            SDL_DestroyRenderer(m_renderer);
            SDL_DestroyWindow(m_window);
            SDL_Quit();
            return false;
        }

        // Create a buffer to store window pixel colors
        m_buffer1 = new Uint32[SCREEN_WIDTH*SCREEN_HEIGHT];
        m_buffer2 = new Uint32[SCREEN_WIDTH*SCREEN_HEIGHT];

        return true;
    }

    void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha){

        if(x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT){
            return;
        }

        Uint32 color  = 0;

        color += red;
        color <<= 8;
        color += green;
        color <<= 8;
        color += blue;
        color <<= 8;
        color += alpha;

        m_buffer1[(y * SCREEN_WIDTH + x)] = color;
    }
    
    void Screen::clear(){
        memset(m_buffer1, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
        memset(m_buffer2, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

        return;
    }

    void Screen::boxBlur(){
        // Swap the buffers
        Uint32 *tempbuffer = m_buffer1;
        m_buffer1 = m_buffer2;
        m_buffer2 = tempbuffer;

        for(int y=0; y < SCREEN_HEIGHT; y++){
            for(int x=0; x < SCREEN_WIDTH; x++){
               int redTotal = 0;
               int greenTotal = 0;
               int blueTotal = 0;
               /* For pixel in 1, get values from all surrounding pixels, 
                * average channel (R,G,B) value and reassign 1 to calculated avg
                *0 0 0 
                *0 1 0
                *0 0 0
                */
               for(int row=-1; row <= 1; row++){
                    for(int col=-1; col <= 1; col++){
                        int currentY = y + row;
                        int currentX = x + col;

                        if(currentX >= 0 && currentX < SCREEN_WIDTH && currentY >=0 && currentY < SCREEN_HEIGHT){
                            Uint32 color = m_buffer2[currentY*SCREEN_WIDTH + currentX];
                            Uint8 red = color >> 24;
                            Uint8 green = color >> 16;
                            Uint8 blue = color >> 8;

                            redTotal += red;
                            greenTotal += green;
                            blueTotal += blue;
                        }
                    }
               }
               Uint8 red = redTotal / 9;
               Uint8 green = greenTotal / 9;
               Uint8 blue = blueTotal / 9;

               setPixel(x, y, red, green , blue, 0xFF);
            }
        }
    }

    void Screen::update(){
        SDL_UpdateTexture(m_texture, NULL, m_buffer1, SCREEN_WIDTH*sizeof(Uint32));
        SDL_RenderClear(m_renderer);
        SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
        SDL_RenderPresent(m_renderer);
    }

    bool Screen::processEvents(){
        SDL_Event event;

        while (SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                return false;
            }
        }
        return true;
    }

    void Screen::close(){
        delete [] m_buffer1;
        delete [] m_buffer2;
        SDL_DestroyTexture(m_texture);
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyWindow(m_window);
        SDL_Quit();

        return;
    }
}