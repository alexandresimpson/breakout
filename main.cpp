#include <iostream>
#include "raylib.h"
#include "paddle.h"
#include "ball.h"
#include "window.h"
#include "game.h"
#include "asset_loader.h"
#include "play_area.h"

void Update();
void Draw();

int main() {
    const int screenWidth = SCREEN_WIDTH;
    const int screenHeight = SCREEN_HEIGHT;

    InitWindow(screenWidth, screenHeight, "Breakout");

  LoadSpriteSheet("assets/sprites.png");
  SetupBall();
  SetupPaddle();
  SetupBoard();

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
    if(GetState()==PLAY) {
        DrawPlayArea();
        DrawPaddle();
        DrawBall();
    }
    DrawGame();
    EndDrawing();
}

void Update() {
    UpdateGame();
    if(GetState()==PLAY) {
        UpdatePaddle();
        UpdateBall();
    }
}