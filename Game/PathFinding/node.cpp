#include "node.h"

std::vector<Node*> Node::GetNeighbors() {
    std::vector<Node*> result;

    std::vector<float> up = { 0.f,  step} ;
    std::vector<float> down = { 0.f, -step };
    std::vector<float> left = {-step,  0.f };
    std::vector<float> right = { step,  0.f };
    
    for (const auto& dir : {up, down, left, right}) {
        float neighborX = posX + dir[0];
        float neighborY = posY + dir[1];

        Node* neighborNode = GetNodeAtPosition(neighborX, neighborY);
        if (neighborNode) {
            result.push_back(neighborNode);
        }
    }
    
    return result;
}

Node* Node::GetNodeAtPosition(float x, float y) {
    for (Node* node : nodes) {
        if (node->posX == x && node->posY == y) return node;
    }
    return nullptr;
}