#pragma once

#include <cstdint>
#include <string>
#include "type.hh"

namespace imglib
{


    /**
     * Load an image file
     * Supported files: PNG / JPEG
     * return the allocated array of pixels
     * It must be free with delete[]
     *
     * @htrows if any error occurs
     * @param pwidth - will contain the width of the image if not null
     * @param pheight - will contain the height of the image if not null
     * @param pchannels - will contain the number of channels if not null
     * @param type - optional type of file
     * If not precised, detect the type according to the extension
     */
    std::uint8_t* file_load(const std::string& path, std::size_t* pwidth, std::size_t* pheight,
                            std::size_t* pchannels,
                            int type = TYPE_AUTO);

    void file_save(const std::string& path, std::uint8_t* data,
                   std::size_t width, std::size_t height,
                   int format,
                   int type = TYPE_AUTO);
}

#include "file.hxx"
