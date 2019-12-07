#ifndef GAME_H
#define GAME_H
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>


class Game
{
    public:
        Game(SDL_Window* window, SDL_Renderer* renderer);
        void handle_event(SDL_Event e, bool *quit);
        void update();
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_Texture* sprite_sheet;
        SDL_Texture* load_texture(std::string path);

        static int hash[];
        int noise2(int x, int y);
        float lin_inter(float x, float y, float s);
        float smooth_inter(float x, float y, float s);
        float noise2d(float x, float y);
        float perlin2d(float x, float y, float freq, int depth);
        long seed;

        int grid_w, grid_h;
        char **grid;
        void createGrid(int x, int y);
        enum Terrain {WATER, SAND, GRASS, MOUNTAIN, TREE, YOU_ARE_WELCOME};
};

#endif // GAME_H
