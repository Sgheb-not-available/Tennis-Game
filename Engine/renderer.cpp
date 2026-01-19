#include "renderer.h"

RenderState renderState;
Camera cam;

int screenWidth;
int screenHeight;

static void RenderStateInit() {
    if (renderState.width == 0 || renderState.height == 0 || renderState.memory == nullptr) {
        renderState.width = 1060;
        renderState.height = 1060;
        int renderSize = renderState.width * renderState.height * sizeof(u32);
        renderState.memory = VirtualAlloc(0, renderSize, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

        ZeroMemory(&renderState.bitMapInfo, sizeof(renderState.bitMapInfo));
        renderState.bitMapInfo.bmiHeader.biSize        = sizeof(renderState.bitMapInfo.bmiHeader);
        renderState.bitMapInfo.bmiHeader.biWidth       = renderState.width;
        renderState.bitMapInfo.bmiHeader.biHeight      = -renderState.height;
        renderState.bitMapInfo.bmiHeader.biPlanes      = 1;
        renderState.bitMapInfo.bmiHeader.biBitCount    = 32;
        renderState.bitMapInfo.bmiHeader.biCompression = BI_RGB;
    }

    screenWidth = renderState.width;
    screenHeight = renderState.height;
}

void ClearScreen(u32 color) {
    RenderStateInit();

    u32* pixel = (u32*)renderState.memory;
    for (int y = 0; y < screenHeight; y++) {
        for (int x = 0; x < screenWidth; x++) {
            *pixel++ = color;
        }
    }
}

void PixelDrawRect(int posX, int posY, int sizeX, int sizeY, u32 color) {
    if(!renderState.memory) return;

    POINT p0 = cam.WorldToScreen(posX, posY);
    POINT p1 = cam.WorldToScreen(posX + sizeX, posY + sizeY);

    int x0 = Clamp(0, p0.x, screenWidth);
    int y0 = Clamp(0, p0.y, screenHeight);
    int x1 = Clamp(0, p1.x, screenWidth);
    int y1 = Clamp(0, p1.y, screenHeight);

    for(int y = y0; y < y1; y++) {
        u32* pixel = (u32*)renderState.memory + x0 + y * screenWidth;
        for(int x = x0; x < x1; x++){
            *pixel++ = color;
        }
    }
}

void PixelDrawRectEmpty(int posX, int posY, u32 sizeX, u32 sizeY, u32 border, u32 color) {
    if(!renderState.memory) return;

    POINT p0 = cam.WorldToScreen(posX, posY);
    POINT p1 = cam.WorldToScreen(posX + sizeX, posY + sizeY);

    int x0 = Clamp(0, p0.x, screenWidth);
    int y0 = Clamp(0, p0.y, screenHeight);
    int x1 = Clamp(0, p1.x, screenWidth);
    int y1 = Clamp(0, p1.y, screenHeight);

    for(int y = y0; y < y1; y++) {
        u32* pixel = (u32*)renderState.memory + x0 + y * screenWidth;
        for(int x = x0; x < x1; x++){
            *pixel++ = (x < x0 + border || x >= x1 - border || y < y0 + border || y >= y1 - border) ? color : *pixel;
        }
    }
}

void DrawRect(float posX, float posY, float halfSizeX, float halfSizeY, u32 color) {
    posX *= screenWidth;
    posY *= screenHeight;
    halfSizeX *= 1060;
    halfSizeY *= 1060;

    posX += screenWidth / 2.f;
    posY += screenHeight / 2.f;

    int x0 = posX - halfSizeX;
    int x1 = posX + halfSizeX;
    int y0 = posY - halfSizeY;
    int y1 = posY + halfSizeY;

    PixelDrawRect(x0, y0, x1, y1, color);
}

void DrawRectScaling(float posX, float posY, float halfSizeX, float halfSizeY, u32 color) {
    int multiplier = Bigger(screenWidth, screenHeight);

    posX *= screenWidth;
    posY *= screenHeight;
    halfSizeX *= multiplier;
    halfSizeY *= multiplier;

    posX += screenWidth / 2.f;
    posY += screenHeight / 2.f;

    int x0 = posX - halfSizeX;
    int x1 = posX + halfSizeX;
    int y0 = posY - halfSizeY;
    int y1 = posY + halfSizeY;

    PixelDrawRect(x0, y0, x1, y1, color);
}