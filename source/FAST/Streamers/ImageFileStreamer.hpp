#pragma once

#include "FAST/Streamers/FileStreamer.hpp"

namespace fast {

class FAST_EXPORT  ImageFileStreamer : public FileStreamer {
    FAST_OBJECT(ImageFileStreamer)
    protected:
        DataObject::pointer getDataFrame(std::string filename);
    private:
        ImageFileStreamer();

};

} // end namespace fast
