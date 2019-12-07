#ifndef GAME_H
#define GAME_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"


class Game
{
    public:
        Game(SDL_Window* window, SDL_Renderer* renderer);
        void handle_event(SDL_Event e);
        void update();
        
        
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        static int hash[];
        int noise2(int x, int y);
        float lin_inter(float x, float y, float s);
        float smooth_inter(float x, float y, float s);
        float noise2d(float x, float y);
        float perlin2d(float x, float y, float freq, int depth);
        long seed;
        void createGrid(float x, float y);
        int grid_w = 80, grid_h = 60; //center is w =39 h = 29
        //
        char **grid;
};

#endif // GAME_H