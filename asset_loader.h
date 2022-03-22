//
// Created by Dustin Simpson on 3/21/22.
//

#ifndef BREAKOUT__ASSET_LOADER_H_
#define BREAKOUT__ASSET_LOADER_H_
#include <string>
#include "raylib.h"

void LoadSpriteSheet(std::string file);
Texture2D GetSpriteTexture(Rectangle rect);

#endif //BREAKOUT__ASSET_LOADER_H_
