#ifndef _scoreBoard_H_
#define _scoreBoard_H_

#include <Ogre.h>

class scoreBoard
{
    private:
        bool gameOver;

    public:
        int getScore();
        int score;
        bool gameOver;
};

#endif