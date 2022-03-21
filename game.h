//
// Created by gsimp on 3/20/2022.
//

#ifndef BREAKOUT_GAME_H
#define BREAKOUT_GAME_H

enum GameState {
    START,
    PLAY,
    END
};

int GetLives();
void LoseLife();
void DrawGame();
void UpdateGame();
GameState GetState();
#endif //BREAKOUT_GAME_H
