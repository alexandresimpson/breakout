#include <iostream>
#include "raylib.h"

#include "window.h"
#include "game.h"
#include "asset_loader.h"


void Update();
void Draw();

int main() {
    const int screenWidth = SCREEN_WIDTH;
    const int screenHeight = SCREEN_HEIGHT;

    InitWindow(screenWidth, screenHeight, "Breakout");

  LoadSpriteSheet("assets/sprites.png");
  SetupGame();


  SetTargetFPS(60);

    while (!WindowShouldClose()) {
        Update();
        Draw();
    }

    CloseWindow();

    return 0;
}

void Draw() {
    BeginDrawing();
    ClearBackground(BLACK);

    DrawGame();
    EndDrawing();
}

void Update() {
    UpdateGame();

}