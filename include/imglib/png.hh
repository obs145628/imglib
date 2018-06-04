#pragma once

#include <cstdint>
#include <string>

namespace imglib
{


    /**
     * Load a PNG file
     * return the allocated array of pixels
     * It must be free with delete[]
     * @htrows if any error occurs
     * @param pwidth - will contain the size of the image if not null
     * @param pheight - will contain the size of the image if not null
     * @param pchannels - will contain the size of the image if not null
     */
    std::uint8_t* png_load(const std::string& path, std::size_t* pwidth, std::size_t* pheight,
                           std::size_t* pchannels);

    void png_rgb_save(const std::string& path, std::uint8_t* data,
                      std::size_t width, std::size_t height);
}

#include "png.hxx"
