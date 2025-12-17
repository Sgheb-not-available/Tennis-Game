#pragma once
#include "renderer.h"
#include "playerController.h"
#include "game.h"

class Player {
    public:
        float posX = renderState.width / 2.f;
        float posY = renderState.height / 2.f;
        float speed = 10.f;
        float halfSizeX = 0.1f;
        float halfSizeY = 0.1f;
        bool hasTargetPos = false;
        bool gridGenerated = false;
        u32 color = 0x00FFFF;

        void Draw();
        void Move(float deltaTime);
};