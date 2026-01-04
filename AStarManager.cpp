#include "AStarManager.h"

vector<Node*> nodes;
float step;
float nodeStep;

vector<Node*> GeneratePath(Node* startNode, Node* targetNode) {
    vector<Node*> openSet;

    for (Node* n : nodes) {
        n->gCost = FLT_MAX;
    }

    startNode->gCost = 0;
    startNode->hCost = Pythagoran(startNode->posX, startNode->posY, targetNode->posX, targetNode->posY);
    openSet.push_back(startNode);

    while (!openSet.empty()) {
        int lowestF = 0;
        for (u64 i = 1; i < openSet.size(); i++) {
            if (openSet[i]->fCost() < openSet[lowestF]->fCost()) {
                lowestF = i;
            }
        }

        Node* currentNode = openSet[lowestF];
        openSet.erase(openSet.begin() + lowestF);

        if (currentNode == targetNode) {
            vector<Node*> path;
            path.insert(path.begin(), currentNode);

            while (currentNode != startNode) {
                currentNode = currentNode->cameFrom;
                path.insert(path.begin(), currentNode);
            }

            return path;
        }

        for (Node* neighbor : currentNode->GetNeighbors())
        {
            float heldGCost = currentNode->gCost + Pythagoran(currentNode->posX, currentNode->posY, neighbor->posX, neighbor->posY);

            if(heldGCost < neighbor->gCost) {
                neighbor->cameFrom = currentNode;
                neighbor->gCost = heldGCost;
                neighbor->hCost = Pythagoran(neighbor->posX, neighbor->posY, targetNode->posX, targetNode->posY);

                if(find(openSet.begin(), openSet.end(), neighbor) == openSet.end()) {
                    openSet.push_back(neighbor);
                }
            }
        }
    }

    return vector<Node*>();
}

Node* FindClosestNode(float x, float y) {
    Node* foundNode;
    float minDist = FLT_MAX;

    for (Node* n : nodes) {
        float dist = Pythagoran(x, y, n->posX, n->posY);
        if(dist < minDist) {
            minDist = dist;
            foundNode = n;
        }
    }

    return foundNode;
}

Node* FindFurthestNode(float x, float y) {
    Node* foundNode;
    float maxDist = 0.f;

    for (Node* n : nodes) {
        float dist = Pythagoran(x, y, n->posX, n->posY);
        if(dist > maxDist) {
            maxDist = dist;
            foundNode = n;
        }
    }

    return foundNode;
}