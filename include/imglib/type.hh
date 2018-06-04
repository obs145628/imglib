#pragma once

#include <string>

namespace imglib
{

    constexpr int TYPE_AUTO = -1;
    constexpr int TYPE_ERR = -2;
    constexpr int TYPE_PNG = 1;
    constexpr int TYPE_JPG = 2;


    int detect_file_type(const std::string& path);
    
}

#include "type.hxx"
