#pragma once

#include "SpatialDataObject.hpp"

// Forward declare
typedef struct _openslide openslide_t;

namespace fast {

struct WholeSlideImageTile {
    std::shared_ptr<uchar[]> data;
    int width;
    int height;
    int offsetX;
    int offsetY;
};

struct WholeSlideImageLevel {
    int width;
    int height;
    int tiles;
};

class FAST_EXPORT WholeSlideImage : public SpatialDataObject {
    FAST_OBJECT(WholeSlideImage)
    public:
        void create(openslide_t* fileHandle, std::vector<WholeSlideImageLevel> levels);
        WholeSlideImageTile getTile(std::string tile);
        WholeSlideImageTile getTile(int level, int tileX, int tileY);
        int getNrOfLevels();
        int getLevelWidth(uint level);
        int getLevelHeight(uint level);
        int getLevelTiles(uint level);
        int getFullWidth();
        int getFullHeight();
        void free(ExecutionDevice::pointer device) override;
        void freeAll() override;
        ~WholeSlideImage();
    private:
        std::vector<WholeSlideImageLevel> m_levels;

        std::unordered_map<std::string, WholeSlideImageTile> m_tileCache;

        uint64_t m_tileCacheMemoryUsage = 0;

        openslide_t* m_fileHandle;
};

}