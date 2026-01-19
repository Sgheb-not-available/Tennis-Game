#include "player.h"

void Player::Draw() {
    int x = (int)(posX - halfSize);
    int y = (int)(posY - halfSize);
    int x1 = (int)(halfSize * 2);
    int y1 = (int)(halfSize * 2);

    cam.camPos = {x - screenWidth / 2, y - screenHeight / 2};

    PixelDrawRect(x, y, x1, y1, color);
}

void Player::Move(float deltaTime) {
    FollowPath(deltaTime);
}

void Player::SetTarget(float x, float y) {
    path.clear();
    path = GeneratePath(FindClosestNode(posX, posY), FindClosestNode(x, y));
}

void Player::FollowPath(float deltaTime) {
    if (path.size() < 2) return;
    
    float arrivalThreshold = 0.f;
    path.size() == 2 ? arrivalThreshold = 0.0001f : arrivalThreshold = step / 4.f;
    float arrivalThresholdSq = arrivalThreshold * arrivalThreshold;

    while (path.size() > 1) {
        Node* nextNodeCheck = path[1];
        float dx = nextNodeCheck->posX - posX;
        float dy = nextNodeCheck->posY - posY;
        float distSq = dx * dx + dy * dy;
        if (distSq < arrivalThresholdSq) {
            path.erase(path.begin());
        } else {
            break;
        }
    }

    if (path.size() < 2) return;

    Node* nextNode = path[1];
    float dirX = nextNode->posX - posX;
    float dirY = nextNode->posY - posY;
    float lengthSq = dirX * dirX + dirY * dirY;
    if (lengthSq == 0.f) {
        path.erase(path.begin());
        return;
    }

    float length = sqrt(lengthSq);
    dirX /= length;
    dirY /= length;

    float moveDist = speed * deltaTime;

    if (moveDist * moveDist >= lengthSq || length <= arrivalThreshold) {
        posX = nextNode->posX;
        posY = nextNode->posY;
        path.erase(path.begin());
    } else {
        posX += dirX * moveDist;
        posY += dirY * moveDist;
    }
}

void Player::SetPlayerData(int id, float x, float y, int myId) {
    if(id == myId) {
        playerId = id;
        posX = x;
        posY = y;
    }
}