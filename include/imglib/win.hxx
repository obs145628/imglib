#pragma once

#include "sdl-env.hh"

namespace imglib
{

    inline void show_rgb(std::uint8_t* pixels, std::size_t width, std::size_t height)
    {
        SDLEnv::instance().show_img_rgb(pixels, width, height);
    }
    
}
