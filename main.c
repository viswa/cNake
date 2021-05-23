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
            } else if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    case SDLK_UP: {
                        if (crawler->direction != DOWN) {
                            crawler->direction = UP;
                            move(crawler);
                        }
                    } break;
                    case SDLK_DOWN: {
                        if (crawler->direction != UP) {
                            crawler->direction = DOWN;
                            move(crawler);
                        }
                    } break;
                    case SDLK_LEFT: {
                        if (crawler->direction != RIGHT) {
                            crawler->direction = LEFT;
                            move(crawler);
                        }
                    } break;
                    case SDLK_RIGHT: {
                        if (crawler->direction != LEFT) {
                            crawler->direction = RIGHT;
                            move(crawler);
                        }
                    } break;
                }
            }
        }

        // Make calculations
        move(crawler);
        SDL_Delay(50);

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
