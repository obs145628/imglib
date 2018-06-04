#pragma once

#include <cstdint>

namespace imglib
{
    void show(std::uint8_t* pixels, std::size_t width, std::size_t height,
              int format);
}

#include "win.hxx"
