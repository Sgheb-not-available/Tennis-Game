#pragma once
#include <enet/enet.h>
#include "logger.h"

extern int maxClients;
extern int currentClients;

void SendData(const char* message, size_t s, ENetPeer *to);
void ServerInit();
void ClientInit();