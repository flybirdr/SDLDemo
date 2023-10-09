#include <SDL2/SDL.h>
#include <iostream>

int x = 0;
int frameRate = 30;

void draw(SDL_Window *window, SDL_Surface *surface)
{
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
    SDL_UpdateWindowSurface(window);
    SDL_Rect rect = {++x, 0, 100, 100};
    SDL_FillRect(surface, &rect, SDL_MapRGB(surface->format, 0x30, 0x10, 0x30));
    SDL_UpdateWindowSurface(window);
}

int main(int, char **)
{
    SDL_Window *window = NULL;
    SDL_Surface *screenSurface = NULL;
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "failed to init sdl " << SDL_GetError() << std::endl;
        return -1;
    }
    window = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    if (!window)
    {
        std::cout << "failed to create window " << SDL_GetError() << std::endl;
        return -1;
    }

    screenSurface = SDL_GetWindowSurface(window);

    while (1)
    {
        Uint32 begin= SDL_GetTicks();
        draw(window, screenSurface);
        SDL_Event event;
        if (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                break;
            }
            if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    break;
                }
                else if (event.key.keysym.sym == SDLK_a)
                {
                    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "提示", "你按下了a建", window);
                }
            }
            else if (event.type == SDL_KEYUP)
            {
            }
        }
        Uint32 end = SDL_GetTicks();
        Uint32 time = end - begin;
        Uint32 rate = 1000 / frameRate;
        SDL_Delay(30/* rate - time */);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
