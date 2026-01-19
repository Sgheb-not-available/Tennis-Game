#pragma once 
#include <vector>
#include "../Engine/utils.h"

struct Tile {
    s64 x, y;
    int sizeX, sizeY;
    TileType type;
};

enum TileType {
    GRASS,
    WATER
};

struct Chunk {
    s64 chunkX, chunkY;
    std::vector<Tile> tiles;
};