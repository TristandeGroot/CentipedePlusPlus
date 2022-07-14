/** \file BETAmain.cpp
    \brief Contains the main function which constructs the game and splashscreen

    This file can be used to create the game splashscreen and also run the game. The high score
    and score are compared here to be displayed on the splashscreen after the game.
 */

#include "Game.h"
#include "Splashscreen.h"

int main()
{
//-------------------------------------------------------------------------------------------------------------------------------
    //INITIALISE

    srand(static_cast<unsigned>(time(0))); //initialise random seed
    int highscore = 0;
//-------------------------------------------------------------------------------------------------------------------------------
    //GAME

    Splashscreen splash; //create splashscreen

    bool gameOver = splash.GameOver;
    while(gameOver==false) //condition if ESC prior to start of game
    {
        Game game; //create game
        bool win = game.win;
        int myScore = game.updateScore();
//-------------------------------------------------------------------------------------------------------------------------------
    //HIGH SCORE CALCULATION

        if(myScore >highscore)
        {
            highscore = myScore;
        }
//------------------------------------------------------------------------------------------------------------------------------
    //YOU WIN OR LOSE SPLASH

        Splashscreen afterSplash(myScore,win,highscore);
        gameOver = afterSplash.GameOver;
    }

    return 0;
}
