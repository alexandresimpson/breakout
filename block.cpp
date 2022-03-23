//
// Created by Dustin Simpson on 3/22/22.
//
#include "block.h"
#include "asset_loader.h"
#include "ball.h"
#include <ctime>
#include <random>
#include <iostream>

std::default_random_engine defEngine(time(0));
std::uniform_int_distribution<int> intDistro(0,2);

void Block::Draw() {
  DrawTexture(texture_, x_, y_, WHITE);
}

void Block::Update() {
  if(CheckCollisionCircleRec(GetBallPosition(),GetBallSize()*2, (Rectangle){(float)x_,(float)y_, 32.0f, 32.0f})) {
    is_destroyed = true;
  }
}

Block::Block(int x, int y) {
  x_ = x;
  y_ = y;

  auto num = intDistro(defEngine);
  if(num == 0) {
    texture_ = GetSpriteTexture({0, 0, 32, 32});
  } else if (num == 1) {
    texture_ = GetSpriteTexture({40, 0, 32, 32});
  } else if (num == 2) {
    texture_ = GetSpriteTexture({80, 0, 32, 32});
  }
//  texture_ = GetSpriteTexture({0, 0, 32, 32});
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
