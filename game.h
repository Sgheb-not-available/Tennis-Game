#pragma once
#include "platformCommon.h"
#include "renderer.h"
#include "player.h"

#define isDown(b) input->buttons[b].isDown
#define pressed(b) (input->buttons[b].isDown && input->buttons[b].changed)
#define released(b) (!input->buttons[b].isDown && input->buttons[b].changed)

// Use internal if you want this function private to game.cpp
void SimulateGame(Input* input, float deltaTime);