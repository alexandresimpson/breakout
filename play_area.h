//
// Created by Dustin Simpson on 3/22/22.
//

#ifndef BREAKOUT__PLAY_AREA_H_
#define BREAKOUT__PLAY_AREA_H_
#include <memory>
#include <vector>
#include "block.h"

void DrawPlayArea();
void SetupBoard();
int GetTopBoundary();
int GetLeftBoundary();
int GetRightBoundary();
void UpdatePlayArea();

std::vector<std::shared_ptr<Block>> GetActiveBlocks();

void DrawPlayArea();
#endif //BREAKOUT__PLAY_AREA_H_
