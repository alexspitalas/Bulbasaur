#include "SDL.h"
#include "SDL_image.h"
#include "Game.h"

int main(int agrc, char *args[]) {
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    SDL_Window* window = SDL_CreateWindow("Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    Game game(window, renderer);
    bool quit = false;
    while (!quit) {
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            game.handle_event(e, &quit);
        }
        if (quit) break;
        game.update();
    }
    IMG_Quit();
    SDL_Quit();
    return 0;
}
