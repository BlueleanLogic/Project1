#include "scoreBoard.h"
#include <iostream>

scoreBoard::scoreBoard() :
    score(0),
    gameOver(false)
{
}

scoreBoard::~scoreBoard()
{
}


int scoreBoard::getScore()
{
    return score;
}

void scoreBoard::addScore(){
    return score++;
}

void scoreBoard::out(btVector3 position, btScalar radius){
    // int cameraZ = 1000;
    int floorHeight = 0;

    // if ball goes past you
    // if (position.z > cameraZ){
    //     gameOver = true;
    //     return;
    // }

    // if ball bounces on the floor more than once 
    if (position.y = floorHeight + radius) {
        // if (hitFloor){
        //     gameOver = true;
        //     return;
        // }
        // else
        //     hitFloor = true;
        gameOver = true;
        return;
    }

}

void scoreBoard::finishGame(bool gameOver){
    if (gameOver){
        // finish and restart game

        // reset game
        score(0);
        gameOver(false);
    }
}