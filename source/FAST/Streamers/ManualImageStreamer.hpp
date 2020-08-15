#ifndef MANUAL_IMAGE_STREAMER_HPP
#define MANUAL_IMAGE_STREAMER_HPP


#include "FAST/Streamers/Streamer.hpp"
#include "FAST/ProcessObject.hpp"
#include <thread>

namespace fast {

class Image;

class FAST_EXPORT  ManualImageStreamer : public Streamer {
    FAST_OBJECT(ManualImageStreamer)
    public:
    	void addImage(std::shared_ptr<Image> image);
        void addSequence(std::vector<std::shared_ptr<Image>> images);
        void setStartNumber(uint startNumber);
        void setStepSize(uint step);
        void setZeroFilling(uint digits);
        void setNumberOfReplays(uint replays);
        void setStreamingMode(StreamingMode mode);
        void enableLooping();
        void disableLooping();
        /**
         * Set a sleep time after each frame is read
         */
        void setSleepTime(uint milliseconds);
        bool hasReachedEnd();
        uint getNrOfFrames() const;
        /**
         * This method runs in a separate thread and adds frames to the
         * output object
         */
        void generateStream() override;

        ~ManualImageStreamer();
    private:
        ManualImageStreamer();

        // Update the streamer if any parameters have changed
        void execute();

        bool mLoop;
        int mNrOfReplays;
        uint mZeroFillDigits;
        uint mStartNumber;
        uint mNrOfFrames;
        uint mMaximumNrOfFrames;
        bool mMaximumNrOfFramesSet;
        uint mSleepTime;
        uint mStepSize;

        std::vector<std::vector<std::shared_ptr<Image>>> mImages;
};

} // end namespace fast

#endif
