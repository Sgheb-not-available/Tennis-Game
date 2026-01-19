#include "camera.h"

POINT Camera::WorldToScreen(float wX, float wY) {
    POINT sCoords;
    sCoords.x = wX - camPos.x;
    sCoords.y = wY - camPos.y;
    return sCoords;
}

POINT Camera::ScreenToWorld(float sX, float sY) {
    POINT wCoords;
    wCoords.x = sX + camPos.x;
    wCoords.y = sY + camPos.y;
    return wCoords;
}