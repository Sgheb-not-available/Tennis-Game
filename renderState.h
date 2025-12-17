#pragma once
#include <windows.h>
#include "utils.h"

struct RenderState {
    int width;
    int height;
    void* memory;
    BITMAPINFO bitMapInfo;
};

extern RenderState renderState;
