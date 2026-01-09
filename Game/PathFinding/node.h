#pragma once
#include <vector>
#include <iostream>

class Node {
    public:
        Node* cameFrom = nullptr;
        
        float posX;
        float posY;

        float gCost;
        float hCost;
        
        std::vector<Node*> neighbors;
        std::vector<Node*> GetNeighbors();

        float fCost() {
            return gCost + hCost;
        }
    private:
        Node* GetNodeAtPosition(float x, float y);
};

extern std::vector<Node*> nodes;
extern float step;