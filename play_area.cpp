//
// Created by Dustin Simpson on 3/22/22.
//
#include "asset_loader.h"
#include "play_area.h"
#include "raylib.h"

Texture2D board_boarder;
Rectangle play_field = {32, 32, 960, 736};

std::vector<std::shared_ptr<Block>> blocks;

void SetupBoard() {
  board_boarder = GetSpriteTexture({360.0f, 0.0f, 32.0f, 32.0f});

  for(int x = 0; x < 25; x++) {
    for(int y = 0; y < 5; y++) {
      blocks.push_back(std::make_unique<Block>(x * 32 + 96, y * 32 + 128));
    }
  }
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

void UpdatePlayArea() {
  for(auto const& the_block:blocks) {
    the_block->Update();
  }
  auto it = blocks.begin();
  while(it != blocks.end()) {
    if((*it)->is_destroyed) {
      it = blocks.erase(it);
    } else {
      ++it;
    }
  }
}
std::vector<std::shared_ptr<Block>> GetActiveBlocks() {
  return blocks;
}

