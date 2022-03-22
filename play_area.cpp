//
// Created by Dustin Simpson on 3/22/22.
//
#include "asset_loader.h"
#include "play_area.h"
#include "raylib.h"

Texture2D board_boarder;
Rectangle play_field = {32, 32, 960, 736};

void SetupBoard() {
  board_boarder = GetSpriteTexture({360.0f, 0.0f, 32.0f, 32.0f});
}

int GetTopBoundary() {
  return (int)play_field.y;
}

int GetLeftBoundary() {
  return (int)play_field.y;
}

int GetRightBoundary() {
  return (int)(play_field.width + play_field.x);
}

void DrawPlayArea() {
  for(int i = 0; i < 32; i++) {
    DrawTexture(board_boarder, i*32, 0, WHITE);
  }
  for(int i = 0; i < 20; i++) {
    DrawTexture(board_boarder, 0, i*32, WHITE);
    DrawTexture(board_boarder, GetRightBoundary(), i*32, WHITE);
  }
}

