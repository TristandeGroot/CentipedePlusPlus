#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H
/** \file Splashscreen.h
    \brief Contains code for constructing Splashscreen class hierarchy
*/
#include <iostream>
#include <ctime>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
/** \brief The splashscreen class is used for the menu before the game and the replay game after the game.
    The splashscreen constantly checks for events to determine whether to continue or close the game.
*/
class Splashscreen
{
private:
    //SPLASH WINDOW ATTRIBUTES
    sf::VideoMode windowSpecs; //need this to build window -> will hold size and width of window
    sf::RenderWindow* window;
    sf::SoundBuffer buffer;
    sf::Sound play_;
    sf::Event windowEvent;//variable for pollEvents

    //DISPLAY SCORE ATTRIBUTES
    sf::Font font1;
    sf::Text text;
    sf::Text text2;
    int myScore;
    int topScore;

    //PRIVATE FUNCTIONS TO INITIALISE
    void setVariables();
    void setWindow(); //will create window
    void setMusic();
    void readInFonts();

    void setWinSplash(int score);
    void setLoseSplash(int score);
public:
    /** \brief The default constructor is used to construct the pregame menu
    */
    Splashscreen();
    /** \brief This constructor is used for ther
    \param x The starting x position on the window
    \param y The starting y position on the window
    */
    Splashscreen(int score, bool win, int highScore);
    virtual ~Splashscreen();

    //PUBLIC FUNCTIONS
    /** \brief This remains tru while splashscreen runs
    \returns true if splash still running
    */
    const bool running() const;
    /** \brief This checks for input events for the window such as a keypress
    */
    void checkEvents();

    //START GAME OR ESCAPE
    /** \brief This checks whether player chooses to play or quit
    \param GameOver
    \returns true if player wishes to quit game
    */
    const bool endGameCheck(bool GameOver) const;
    /** \brief This can be called to determine if the player has chosen to play or quit
    */
    bool GameOver;

    //UPDATE & RENDER FRAME
    /** \brief This updates the menu screen
    \param target The window of the game
    */
    void refresh();
    /** \brief This draws the pregame menu / postgame replay on the window
    \param target The window of the game
    */
    void manifest();

};

#endif // SPLASHSCREEN_H
