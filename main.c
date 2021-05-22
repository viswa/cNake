#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "game.h"
#include "snake.h"

_Noreturn void quit()
{
    fprintf(stderr, "cNake could not be lanuched");
    exit(EXIT_FAILURE);
}

int main(int argc, char** argv)
{
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        quit();
    }

    window = SDL_CreateWindow(
            "cNake",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            SC_WIDTH,
            SC_HEIGHT,
            SDL_WINDOW_SHOWN);
    if (window == NULL) {
        quit();
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        quit();
    }
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, SDL_ALPHA_OPAQUE); // Black
    SDL_RenderClear(renderer);

    snake* crawler = make_snake(); // snake object
    SDL_Event e;
    // Game Loop
    while (true) {
        // Process Events
        if (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                break;
            }
        }

        // Make calculations

        // Redraw window
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);
        draw_snake(&renderer, crawler);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}
