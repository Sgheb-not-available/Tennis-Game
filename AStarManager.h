#pragma once
#include <windows.h>
#include <cfloat>
#include <vector>
#include <algorithm>
#include "utils.h"
#include "node.h"
#include "renderer.h"

using namespace std;

extern vector<Node*> nodes;
extern float step;

void GenerateNodeGrid();
vector<Node*> GeneratePath(Node* startNode, Node* targetNode);
Node* FindClosestNode(float x, float y);
Node* FindFurthestNode(float x, float y);