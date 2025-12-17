#include "player.h"

void Player::Draw() {
    DrawRect(posX, posY, halfSizeX, halfSizeY, color);
}

void Player::Move(float deltaTime) {
    POINT p;
    GetCursorPos(&p);
}