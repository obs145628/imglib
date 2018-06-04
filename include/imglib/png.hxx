#pragma once

#include "png.hh"
#include <cstdio>
#include <cstring>
#include <stdexcept>
#include <png.h>


namespace imglib
{

    inline std::uint8_t* png_load(const std::string& path,
                                  std::size_t* pwidth, std::size_t* pheight,
                                  std::size_t* pchannels)
    {
        unsigned char header[8];

        FILE* f = fopen(path.c_str(), "rb");
        if (!f)
            throw std::runtime_error {"Can't open file"};
        fread(header, 1, 8, f);
        if (png_sig_cmp(header, 0, 8))
            throw std::runtime_error {"Not a png file"};

        png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING,
                                                      NULL, NULL, NULL);
        if (!png_ptr)
            throw std::runtime_error{"png_create_read_struct failed"};

        png_infop info_ptr = png_create_info_struct(png_ptr);
        if (!info_ptr)
            throw std::runtime_error {"png_create_info_struct failed"};

        if (setjmp(png_jmpbuf(png_ptr)))
            throw std::runtime_error {"Error during init_io"};

        png_init_io(png_ptr, f);
        png_set_sig_bytes(png_ptr, 8);

        png_read_info(png_ptr, info_ptr);

        std::size_t width = png_get_image_width(png_ptr, info_ptr);
        std::size_t height = png_get_image_height(png_ptr, info_ptr);
        
        png_read_update_info(png_ptr, info_ptr);

        if (setjmp(png_jmpbuf(png_ptr)))
            throw std::runtime_error {"Error during read_image"};

        std::size_t rowstride = png_get_rowbytes(png_ptr,info_ptr);
        std::size_t channels = rowstride / width;

        std::uint8_t* pixs = new std::uint8_t[height * rowstride];
        for (std::size_t y = 0; y < height; ++y)
            png_read_row(png_ptr, pixs + y * rowstride, nullptr);


        fclose(f);

        if (pwidth)
            *pwidth = width;
        if (pheight)
            *pheight = height;
        if (pchannels)
            *pchannels = channels;
        return pixs;
    }

    inline void png_rgb_save(const std::string& path, std::uint8_t* data,
                             std::size_t width, std::size_t height)
    {
        FILE* f = fopen(path.c_str(), "wb");
        if (!f)
            throw std::runtime_error {"Can't open file"};
        
        png_structp png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING,
                                                      NULL, NULL, NULL);
        if (!png_ptr)
            throw std::runtime_error {"Can't create write_struct"};

        png_infop info_ptr = png_create_info_struct(png_ptr);
        if (!info_ptr)
            throw std::runtime_error {"Can't create info struct"};

        if (setjmp(png_jmpbuf(png_ptr)))
            throw std::runtime_error {"Error during png creation\n"};

        png_init_io(png_ptr, f);

        png_set_IHDR(png_ptr, info_ptr, width, height,
                     8, PNG_COLOR_TYPE_RGB, PNG_INTERLACE_NONE,
                     PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);

        png_write_info(png_ptr, info_ptr);

        std::size_t rowstride = 3 * width;
        for (std::size_t y = 0; y < height; ++y)
            png_write_row(png_ptr, data + y * rowstride);

        png_write_end(png_ptr, nullptr);

        fclose(f);
        png_free_data(png_ptr, info_ptr, PNG_FREE_ALL, -1);
        png_destroy_write_struct(&png_ptr, nullptr);
    }

}
