#pragma once

#include "sdl-env.hh"

namespace imglib
{

    inline void show(std::uint8_t* pixels, std::size_t width, std::size_t height,
                     int format)
    {
        SDLEnv::instance().show_img(pixels, width, height, format);
    }
    
}
