#include "chunk.h"

std::string Chunk::GenerateSeed(int chunkX, int chunkY) {
    std::string seed;
    std::vector<Tile> tiles;

    for(u32 _x = 0; _x < size; _x += 1) {
        for(u32 _y = 0; _y < size; _y += 1) {
            Tile tile;
            tile.typeId = 0;

            tiles.push_back(tile);
        }
    }

    for(int i = 0; i < maxObstacles; ++i) {
        int index = rand() % (int)tiles.size(); 
        tiles[index].typeId = 1;
    }

    for(const Tile &tile : tiles) {
        seed += std::to_string(tile.typeId);
    }

    seed += std::to_string(chunkX) + "|" + std::to_string(chunkY);

    return seed;
}

void Chunk::LoadAndRender(std::string seed) {
    vector<Tile> tiles;
    vector<Tile> open;

    if(!loaded) {
        int chunkX = std::stoi(seed.substr(size * size, seed.find("|")));
        int chunkY = std::stoi(seed.substr(size * size + std::to_string(chunkX).length() + 1));

        int i = 0;
        for(int _x = 0; _x < size; ++_x) {
            for(int _y = 0; _y < size; ++_y) {
                char typeChar = seed[i];
                int typeId = typeChar - '0';

                Tile tile;
                tile.x = chunkX + _x;
                tile.y = chunkY + _y;
                tile.size = (int)step;
                tile.typeId = typeId;
                if(typeId == 0) {
                    tile.color = 0x00FF00; // Grass

                    Node* n = new Node();
                    n->posX = tile.x + step / 2.f;
                    n->posY = tile.y + step / 2.f;
                    n->neighbors = n->GetNeighbors();
                } else if(typeId == 1) {
                    tile.color = 0x00FFFF; // Water
                }
            
                i++;
            }
        }
    }

    for(const Tile &tile : tiles) {
        PixelDrawRect(tile.x, tile.y, tile.size, tile.size, tile.color);
    }

    loaded = true;
}