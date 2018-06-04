#pragma once

#include "type.hh"

namespace imglib
{

    inline std::string get_file_ext(const std::string& path)
    {
        auto pos = path.find_last_of(".");
        if (pos == std::string::npos)
            return "";
        else
            return path.substr(pos);
    }

    inline int detect_file_type(const std::string& path)
    {
        auto ext = get_file_ext(path);
        if (ext == ".png")
            return TYPE_PNG;
        else if (ext == ".jpg" || ext == ".jpeg")
            return TYPE_JPG;
        else
            return TYPE_ERR;
    }
    
}
