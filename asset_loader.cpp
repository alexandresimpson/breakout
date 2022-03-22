//
// Created by Dustin Simpson on 3/21/22.
//
#include "asset_loader.h"

Image sprite_sheet;

void LoadSpriteSheet(std::string file) {
  sprite_sheet = LoadImage(file.c_str());
}

Texture2D GetSpriteTexture(Rectangle rect) {
  auto tmp = ImageFromImage(sprite_sheet, rect);
  return LoadTextureFromImage(tmp);
}