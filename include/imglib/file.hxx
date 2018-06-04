#pragma once

#include "file.hh"
#include "png.hh"
#include "jpg.hh"
#include <stdexcept>

namespace imglib
{



    inline std::uint8_t* file_load(const std::string& path, std::size_t* pwidth, std::size_t* pheight,
                                   std::size_t* pchannels,
                                   int type)
    {
        if (type == TYPE_AUTO)
            type = detect_file_type(path);

        if (type == TYPE_PNG)
            return png_load(path, pwidth, pheight, pchannels);
        else if (type == TYPE_JPG)
            return jpg_load(path, pwidth, pheight, pchannels);
        else
            throw std::runtime_error {"Unknow file type"};
    }

    inline void file_save(const std::string& path, std::uint8_t* data,
                          std::size_t width, std::size_t height,
                          int format,
                          int type)
    {
        if (type == TYPE_AUTO)
            type = detect_file_type(path);

        if (type == TYPE_PNG)
            png_save(path, data, width, height, format);
        else if (type == TYPE_JPG)
            jpg_save(path, data, width, height, format);
        else
            throw std::runtime_error {"Unknow file type"};
        
    }
}
