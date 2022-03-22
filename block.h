//
// Created by Dustin Simpson on 3/22/22.
//

#ifndef BREAKOUT__BLOCK_H_
#define BREAKOUT__BLOCK_H_
#include "raylib.h"

enum class BlockType {
  RED_BLOCK,
  BLUE_BLOCK,
  GREEN_BLOCK,
};

class Block {
 public:
  Block(int x, int y);
  Block(int x, int y, BlockType t);
  void Draw();
  void Update();

  int x_;
  int y_;
  Texture2D texture_;
};

#endif //BREAKOUT__BLOCK_H_
