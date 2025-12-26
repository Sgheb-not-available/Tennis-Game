#include "game.h"

Player player;
Logger logger;

void SimulateGame(Input* input, float deltaTime) {
    ClearScreen(0xffffff);

    if(pressed(LEFT_MOUSE)) {
        POINT p;
        GetCursorPos(&p);
        if (gWindow) {
            ScreenToClient(gWindow, &p);
            logger.Log(LOG_WARNING, "Mouse and node pos not matching");
        }
        player.SetTarget((float)p.x, (float)p.y);
        player.moving = true;
    }

    if(player.moving) {
        player.Move(deltaTime);
    }

    player.Draw();
}