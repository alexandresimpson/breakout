#include <iostream>
#include "raylib.h"

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768

void Update();
void Draw();

int paddle_speed=6;
int paddle_x=512;
int paddle_y=650;
int paddle_width=75;

int main() {
    const int screenWidth = SCREEN_WIDTH;
    const int screenHeight = SCREEN_HEIGHT;

    InitWindow(screenWidth, screenHeight, "Breakout");

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
    DrawText("start", 190, 200, 20, WHITE);

    DrawRectangle(paddle_x, paddle_y,paddle_width,20,RED);

    EndDrawing();
}

void Update() {
  if(IsKeyDown(KEY_RIGHT)){
      // paddle_x=paddle_x+1;
      paddle_x+=paddle_speed;
  }

  if(IsKeyDown(KEY_LEFT)){
        // paddle_x=paddle_x-1;
        paddle_x-=paddle_speed;
  }

  if(paddle_x < 0){
        paddle_x=0;
    }

    if(paddle_x > SCREEN_WIDTH-paddle_width) {
        paddle_x = SCREEN_WIDTH-paddle_width;
    }
}