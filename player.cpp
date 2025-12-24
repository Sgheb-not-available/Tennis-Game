#include "player.h"

void Player::Draw() {
    // Draw using pixel coordinates
    int x = (int)(posX - halfSizeX);
    int y = (int)(posY - halfSizeY);
    int x1 = (int)(posX + halfSizeX);
    int y1 = (int)(posY + halfSizeY);
    PixelDrawRect(x, y, x1, y1, color);
}

void Player::Move(float deltaTime) {
    // Follow the currently computed path (path is set once on click via SetTarget)
    FollowPath(deltaTime);
}

void Player::SetTarget(float x, float y) {
    if(!gridGenerated) {
        GenerateNodeGrid();
        gridGenerated = true;
    }

    // Ensure player starts centered once grid (and render dimensions) are available
    if (gridGenerated && (posX == 0.f && posY == 0.f)) {
        posX = renderState.width / 2.f;
        posY = renderState.height / 2.f;
    }

    path.clear();
    path = GeneratePath(FindClosestNode(posX, posY), FindClosestNode(x, y));
    std::cout << "player node: " << FindClosestNode(posX, posY)->posX << ", " << FindClosestNode(posX, posY)->posY << "\n";
    std::cout << "target node: " << FindClosestNode(x, y)->posX << ", " << FindClosestNode(x, y)->posY << "\n";
}

void Player::FollowPath(float deltaTime) {
    if (path.size() < 2) return;

    const float arrivalThreshold = step * 0.5f;

    while (path.size() > 1) {
        Node* nextNodeCheck = path[1];
        float dx = nextNodeCheck->posX - posX;
        float dy = nextNodeCheck->posY - posY;
        float dist = sqrt(dx * dx + dy * dy);
        if (dist < arrivalThreshold) {
            path.erase(path.begin());
        } else {
            break;
        }
    }

    if (path.size() < 2) return;

    Node* nextNode = path[1];
    float dirX = nextNode->posX - posX;
    float dirY = nextNode->posY - posY;
    float length = sqrt(dirX * dirX + dirY * dirY);

    if (length != 0) {
        dirX /= length;
        dirY /= length;
    }

    posX += dirX * speed * deltaTime;
    posY += dirY * speed * deltaTime;
}