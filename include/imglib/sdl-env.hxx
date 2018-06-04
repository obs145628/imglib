#pragma once

#include "sdl-env.hh"
#include <iostream>
#include <cstdlib>

namespace imglib
{

    inline SDLEnv::~SDLEnv()
    {
        SDL_DestroyWindow(win);
        SDL_Quit();
    }
    
    inline SDLEnv& SDLEnv::instance()
    {
        static SDLEnv res;
        return res;
    }

    inline void SDLEnv::sdl_check(int x)
    {
        if (x < 0)
        {
            std::cerr << "SDL Errror: "  << SDL_GetError() << std::endl;
            std::exit(1);
        }
    }

    inline void SDLEnv::sdl_check(void* ptr)
    {
        if (!ptr)
        {
            std::cerr << "SDL Errror: "  << SDL_GetError() << std::endl;
            std::exit(1);
        }
    }

    inline void SDLEnv::size_set(int width, int height)
    {
        SDL_SetWindowSize(win, width, height);
        SDL_SetWindowPosition(win, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
        surface = SDL_GetWindowSurface(win);
    }

    inline void SDLEnv::show_img_rgb(std::uint8_t* pixels,
                          std::size_t width, std::size_t height)
    {
        size_set(width, height);
        
        auto pixs_surface = SDL_CreateRGBSurfaceFrom(pixels, width, height, 3 * 8,
                                                     width * 3,
                                                     0x0000FF, 0x00FF00, 0xFF0000, 0);
        sdl_check(pixs_surface);

        sdl_check(SDL_BlitSurface(pixs_surface, nullptr, surface, nullptr));    
    
        SDL_UpdateWindowSurface(win);
    }

    inline SDLEnv::SDLEnv()
    {
        sdl_check(SDL_Init(SDL_INIT_VIDEO));
        win = SDL_CreateWindow("imglib",
                                    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                    256, 256, SDL_WINDOW_SHOWN);
        sdl_check(win);
        surface = SDL_GetWindowSurface(win);
    }


}
