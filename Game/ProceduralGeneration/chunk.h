#pragma once
#include <vector>
#include <string>
#include "../Engine/base.h"
#include "../Game/PathFinding/AStarManager.h"
#include "../Game/PathFinding/node.h"
#include "tile.h"

class Chunk {
    public:
        bool loaded = false;

        std::string GenerateSeed(int chunkX, int chunkY);
        void LoadAndRender(std::string seed);
    private:
        const int size = 512;
        const int pixelSize = size * step;

        float obstacleDensity = 0.1f;
        int maxObstacles = size * size * obstacleDensity / 100;
};