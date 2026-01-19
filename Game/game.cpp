#include "game.h"

std::vector<Player> players;
bool eNetInit = false;
int myPlayerId = 0;
u16 needed = 0;
POINT selectedTile = {0, 0};
MapGenerator mapGenerator;

void SimulateGame(Input* input, float deltaTime) {
    ClearScreen(0xFFFFFF);

    if(!eNetInit) {
        Game::ENetInit();
    }

    Game::ListPlayers();

    POINT pS;
    GetCursorPos(&pS);
    if(gWindow) ScreenToClient(gWindow, &pS);
    POINT pW = cam.ScreenToWorld((float)pS.x, (float)pS.y);

    if(pressed(LEFT_MOUSE)) {
        players[myPlayerId].SetTarget((float)pW.x, (float)pW.y);
    }

    if(!players.empty()) {
        players[myPlayerId].Move(deltaTime);
    }

    mapGenerator.DrawMap();
    for(Player& p : players) p.Draw();

    selectedTile = Game::SelectTile(pW);
}

namespace Game {
    void ENetInit() {
        if(enet_initialize() != 0) {
            Log(LOG_ERROR, "Failed to initialize ENet.");
        } else {
            Log(LOG_INFO, "Network inizializzato.");
            Log(LOG_INFO, "Server o Client? (s/c): ");
            std::thread([](){
                char choice = '\0';
                std::cin >> choice;
                if (choice == 's') {
                    ServerInit();
                } else if (choice == 'c') {
                    ClientInit();
                }
            }).detach();
            eNetInit = true;
            Log(LOG_ERROR, "Malformed packet, impossible to send player data and sync obstacles.");
        }
    }

    POINT SelectTile(POINT p) {
        POINT selectedTile = {0, 0};

        u32 selectColor = 0xFFFF00;
        u32 size = (u32)step;
        u32 halfSize = size / 2;
        u32 borderWidth = 5;

        Node* nodePtr = FindClosestNode((float)p.x, (float)p.y);
        if (nodePtr) {
            int x0 = (int)nodePtr->posX;
            int y0 = (int)nodePtr->posY;

            selectedTile.x = x0;
            selectedTile.y = y0;

            PixelDrawRectEmpty(x0 - halfSize, y0 - halfSize, size, size, borderWidth, selectColor);
        }

        return selectedTile;
    }

    void ListPlayers() {
        needed = (u16)currentClients + 1;
        if (players.size() < needed) {
            for (u16 i = players.size(); i < needed; ++i) {
                Player newPlayer;
                newPlayer.playerId = (int)i;
                players.push_back(newPlayer);
            }
        } else if (players.size() > needed) {
            players.resize(needed);
        }
    }

    void SetPNeeded(u16 playerCount) {
        needed = playerCount;
    }
}