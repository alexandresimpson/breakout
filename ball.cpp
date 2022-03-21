//
// Created by gsimp on 3/20/2022.
//
#include "raylib.h"
#include "ball.h"
#include "window.h"
#include "paddle.h"
#include "game.h"

int ball_x=512;
int ball_y=384;
float speed=5.0f;
float x_dir=0.5f;
float y_dir=1.0f;

void UpdateBall(){
    // Move the ball
    ball_x+=x_dir*speed;
    ball_y+=y_dir*speed;

    // Check for if/what the ball hit
    CheckWallCollision();
    CheckPaddleCollision();

}
void DrawBall(){
    DrawCircle( ball_x,ball_y,7.5f, WHITE);
}

void CheckWallCollision(){
    if(ball_x <= 0 || ball_x >= SCREEN_WIDTH-7.5f ){
        x_dir*=-1;
//        y_dir*=-1;
    }
    if(ball_y <= 0 ){
//        x_dir*=-1;
        y_dir*=-1;
    }
    if(ball_y >= SCREEN_HEIGHT-7.5f){
        LoseLife();
        ResetBall();
    }
}

void CheckPaddleCollision() {
    Vector2 pos={(float)ball_x,(float)ball_y};
    auto paddle_rec = GetPaddleRec();
    if(CheckCollisionCircleRec(pos,7.5f,paddle_rec)){
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