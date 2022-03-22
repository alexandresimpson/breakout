//
// Created by Dustin Simpson on 3/22/22.
//
#include "asset_loader.h"
#include "play_area.h"
#include "raylib.h"
#include "block.h"
#include <memory>
#include <vector>

Texture2D board_boarder;
Rectangle play_field = {32, 32, 960, 736};

std::vector<std::unique_ptr<Block>> blocks;

void SetupBoard() {
  board_boarder = GetSpriteTexture({360.0f, 0.0f, 32.0f, 32.0f});

  blocks.push_back(std::make_unique<Block>(256, 128));
  blocks.push_back(std::make_unique<Block>(288, 128, BlockType::BLUE_BLOCK));
  blocks.push_back(std::make_unique<Block>(320, 128, BlockType::GREEN_BLOCK));
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

  for(auto const& the_block:blocks) {
    the_block->Draw();
  }
}

