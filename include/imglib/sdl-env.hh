#pragma once


#include <cstdint>
#include <SDL2/SDL.h>


namespace imglib
{

    class SDLEnv
    {

    public:

        SDLEnv(const SDLEnv&) = delete;
        SDLEnv& operator=(const SDLEnv&) = delete;

        ~SDLEnv();
        static SDLEnv& instance();

        static void sdl_check(int x);
        static void sdl_check(void* ptr);

        void size_set(int width, int height);

        void show_img(std::uint8_t* pixels,
                      std::size_t width, std::size_t height,
                      int format);

        SDL_Window* win;
        SDL_Surface* surface;



    private:

        SDLEnv();
    };
    
}

#include "sdl-env.hxx"
