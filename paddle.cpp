//
// Created by gsimp on 3/20/2022.
//
#include "raylib.h"
#include "paddle.h"
#include "window.h"

int paddle_speed=6;
int paddle_x=512;
int paddle_y=650;
int paddle_width=75;
int paddle_height=20;

void UpdatePaddle(){
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
void DrawPaddle(){
    DrawRectangle(paddle_x, paddle_y,paddle_width,paddle_height,RED);
}
Rectangle GetPaddleRec(){
    return {paddle_x,paddle_y,paddle_width,paddle_height};
}
