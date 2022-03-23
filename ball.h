//
// Created by gsimp on 3/20/2022.
//

#ifndef BREAKOUT_BALL_H
#define BREAKOUT_BALL_H

void CheckWallCollision();
void CheckPaddleCollision();
void CheckBlockCollision();

void SetupBall();

void UpdateBall();
void DrawBall();
void ResetBall();

Vector2 GetBallPosition();
float GetBallSize();

#endif //BREAKOUT_BALL_H
