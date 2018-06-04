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

    //display PNG image
    std::size_t fwidth;
    std::size_t fheight;
    auto fdata = imglib::file_load("./linux.png", &fwidth, &fheight, nullptr);
    imglib::show(fdata, fwidth, fheight, imglib::FORMAT_RGB);
    SDL_Delay(2000);
    delete[] fdata;

    //display JPEG image
    std::size_t jwidth;
    std::size_t jheight;
    auto jdata = imglib::file_load("./cat.jpg", &jwidth, &jheight, nullptr);
    imglib::show(jdata, jwidth, jheight, imglib::FORMAT_RGB);
    SDL_Delay(2000);
    delete[] jdata;

    //display created image
    auto pixs = build_img(WIDTH, HEIGHT);
    imglib::show(pixs, WIDTH, HEIGHT, imglib::FORMAT_RGB);
    SDL_Delay(2000);

    //save created image to PNG
    imglib::file_save("out.png", pixs, WIDTH, HEIGHT, imglib::FORMAT_RGB);

    //save created image to JPG
    imglib::file_save("out.jpg", pixs, WIDTH, HEIGHT, imglib::FORMAT_RGB);

    delete[] pixs;
    return 0;
}
