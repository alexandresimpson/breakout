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

int ball_x=512;
int ball_y=384;
float speed=5.0f;
float x_dir=0.5f;
float y_dir=1.0f;
float ball_size=12.0f;

Texture2D ball_sprite;

void UpdateBall(){
    // Move the ball
    ball_x+=x_dir*speed;
    ball_y+=y_dir*speed;

    // Check for if/what the ball hit
    CheckWallCollision();
    CheckPaddleCollision();

}
void DrawBall(){
//    DrawCircle( ball_x,ball_y,7.5f, WHITE);
  DrawTexture(ball_sprite, ball_x, ball_y, WHITE);
}

void CheckWallCollision(){
    if(ball_x <= GetLeftBoundary() || ball_x >= GetRightBoundary()-(ball_size*2) ){
        x_dir*=-1;
//        y_dir*=-1;
    }
    if(ball_y <= GetTopBoundary() ){
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