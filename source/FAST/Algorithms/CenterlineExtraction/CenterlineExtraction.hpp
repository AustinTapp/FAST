#ifndef CENTERLINE_EXTRACTION_HPP_
#define CENTERLINE_EXTRACTION_HPP_

#include "FAST/ProcessObject.hpp"

namespace fast {

class Image;

class FAST_EXPORT  CenterlineExtraction : public ProcessObject {
	FAST_OBJECT(CenterlineExtraction)
    public:
    private:
		CenterlineExtraction();
		void execute();
        std::shared_ptr<Image> calculateDistanceTransform(std::shared_ptr<Image> input);
};

}

#endif
