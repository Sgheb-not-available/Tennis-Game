#include <iostream>
#include "game.h"
#include "renderer.h"
#include "player.h"

Player player;

void SimulateGame(Input* input, float deltaTime) {
    ClearScreen(0xffffff);

    if(pressed(LEFT_MOUSE) && !player.gridGenerated) GenerateNodeGrid();

    player.Draw();
}