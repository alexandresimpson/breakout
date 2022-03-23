//
// Created by gsimp on 3/20/2022.
//
#include "raylib.h"
#include "ball.h"
#include "window.h"
#include "paddle.h"
#include "game.h"
#include "asset_loader.h"
#include "play_area.h"
#include "block.h"

int ball_x=512;
int ball_y=384;
float speed=5.0f;
float x_dir=0.5f;
float y_dir=1.0f;
float ball_size=12.0f;

static Texture2D ball_sprite;

void UpdateBall(){
    // Move the ball
    ball_x+=x_dir*speed;
    ball_y+=y_dir*speed;

    // Check for if/what the ball hit
    CheckWallCollision();
    CheckPaddleCollision();
    CheckBlockCollision();

}
void DrawBall(){
//    DrawCircle( ball_x,ball_y,7.5f, WHITE);
  DrawTexture(ball_sprite, (int)ball_x - ball_size, (int)ball_y - ball_size, WHITE);
}

void CheckWallCollision(){
    if(ball_x - ball_size <= GetLeftBoundary() || ball_x+ball_size >= GetRightBoundary() ){
        x_dir*=-1;
//        y_dir*=-1;
    }
    if(ball_y - ball_size <= GetTopBoundary() ){
//        x_dir*=-1;
        y_dir*=-1;
    }
    if(ball_y >= SCREEN_HEIGHT-(ball_size*2)){
        LoseLife();
        ResetBall();
    }
}

void CheckPaddleCollision() {
    Vector2 pos={(float)ball_x,(float)ball_y};
    auto paddle_rec = GetPaddleRec();
    if(CheckCollisionCircleRec(pos,ball_size*2,paddle_rec)){
        if(ball_y > paddle_rec.y+1) {
            x_dir*=-1;
        } else {
            y_dir*=-1;
        }
    }
}
void ResetBall(){
    ball_x=512;
    ball_y=384;
    speed=5.0f;
    x_dir=0.5f;
    y_dir=1.0f;
}

void SetupBall() {
  ball_sprite = GetSpriteTexture({158.0f, 240.0f, 24.0f, 24.0f});
}

Vector2 GetBallPosition() {
  return (Vector2) {(float)ball_x, (float)ball_y};
}

float GetBallSize() {
  return ball_size;
}

void CheckBlockCollision() {
  auto blocks = GetActiveBlocks();

  for(auto const& b : blocks) {
    if (CheckCollisionCircleRec(GetBallPosition(),
                                GetBallSize() * 2,
                                (Rectangle) {(float) b->x_, (float) b->y_, 32.0f, 32.0f})) {
      y_dir*=-1;
    }
  }
}