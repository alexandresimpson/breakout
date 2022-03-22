//
// Created by Dustin Simpson on 3/22/22.
//
#include "block.h"
#include "asset_loader.h"

void Block::Draw() {
  DrawTexture(texture_, x_, y_, WHITE);
}

void Block::Update() {

}

Block::Block(int x, int y) {
  x_ = x;
  y_ = y;
  texture_ = GetSpriteTexture({0, 0, 32, 32});
}

Block::Block(int x, int y, BlockType t) {
  x_ = x;
  y_ = y;

  if(t == BlockType::RED_BLOCK) {
    texture_ = GetSpriteTexture({0, 0, 32, 32});
  }

  if(t == BlockType::BLUE_BLOCK) {
    texture_ = GetSpriteTexture({40, 0, 32, 32});
  }

  if(t == BlockType::GREEN_BLOCK) {
    texture_ = GetSpriteTexture({80, 0, 32, 32});
  }
}
