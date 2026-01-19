#pragma once
#include <windows.h>

class Camera {
    public:
        POINT camPos;
        POINT WorldToScreen(float wX, float wY);
        POINT ScreenToWorld(float sX, float sY);
};