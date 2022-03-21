//
// Created by gsimp on 3/20/2022.
//
#include "raylib.h"
#include "game.h"
#define LIVES 3
GameState game_state = START;
int lives=LIVES;
int GetLives(){
    return lives;
}
void LoseLife(){
    lives--;
}

void DrawGame(){
    if(GetState()==START){
        DrawText("Push Space To Start", 120, 384, 75, WHITE);
    }
    if(GetState()==END){
        DrawText("GAME OVER", 300, 300, 75, WHITE);
    }
    DrawText("balls: ", 20, 730, 30, WHITE);
    int x=120;
    for(int i=0; i < lives; i++) {
        DrawCircle( x,746,7.5f, WHITE);
        x+=30;
    }
}
GameState GetState(){
    return game_state;
}
void UpdateGame(){
    if((GetState()==START || GetState()==END) && IsKeyPressed(KEY_SPACE)){
        lives=LIVES;
        game_state=PLAY;
    }

    if(GetState()==PLAY && GetLives()==0){
        game_state=END;
    }
}