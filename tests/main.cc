#include <cstdlib>
#include <iostream>

#include <imglib/imglib.hh>

namespace
{
    constexpr std::size_t WIDTH = 640;
    constexpr std::size_t HEIGHT = 480;
}


std::uint8_t* build_img(std::size_t width, std::size_t height)
{
    auto pixs = new std::uint8_t[width * height * 3];

    for (std::size_t i = 0; i < height; ++i)
    {
        for (std::size_t j = 0; j < width; ++j)
        {
            
            if (i < height / 2)
            {
                pixs[3 * width * i + 3 * j + 0] = 0x00;
                pixs[3 * width * i + 3 * j + 1] = 0x00;
                pixs[3 * width * i + 3 * j + 2] = 0xFF;
            }
            else
            {
                pixs[3 * width * i + 3 * j + 0] = 0xFF;
                pixs[3 * width * i + 3 * j + 1] = 0x00;
                pixs[3 * width * i + 3 * j + 2] = 0x00;
            }
        }
    }

    return pixs;
}


int main()
{

    std::size_t fwidth;
    std::size_t fheight;
    auto fdata = imglib::png_load("./img.png", &fwidth, &fheight, nullptr);   

    auto pixs = build_img(WIDTH, HEIGHT);
    imglib::png_rgb_save("out.png", pixs, WIDTH, HEIGHT);

    imglib::show_rgb(fdata, fwidth, fheight);
    SDL_Delay(2000);

    imglib::show_rgb(pixs, WIDTH, HEIGHT);
    SDL_Delay(2000);

    delete[] pixs;
    delete[] fdata;

    return 0;
}
