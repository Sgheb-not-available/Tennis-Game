#pragma once
#include <vector>
#include <iostream>
#include "renderer.h"
#include "AStarManager.h"
#include "game.h"
#include "win32.h"

class Player {
    public:
        float posX = 0.f;
        float posY = 0.f;

        float speed = 50.f;

        bool moving = false;

        float halfSizeX = 50.f; 
        float halfSizeY = 50.f; 

        u32 color = 0x00FFFF;

        void Draw();
        void Move(float deltaTime);
        void SetTarget(float x, float y);
    private:
        vector<Node*> path;
        bool gridGenerated = false;

        void FollowPath(float deltaTime);
};