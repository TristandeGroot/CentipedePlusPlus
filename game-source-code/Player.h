#ifndef PLAYER_H
#define PLAYER_H

/** \file Player.h
    \brief Contains code for constructing Player class hierarchy

    The player base rectangle moves in limited area at bottom of window.
*/

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Resources.h"

/** \class Player
    \brief player moves in all directions in limited area at bottom of window.
    Uses 5 different sprites to create different perspectives when moving.
    Game object with ability to move in all directions.
    Hitting a window bound pushes player back in opposite direction.
 */
class Player
{
private:
    //--------------------------------------------------------------------------------------------------------------------------
    // PLAYER ATTRIBUTES
    //--------------------------------------------------------------------------------------------------------------------------
    sf::Sprite appearance;
    float playerSpeed; //how much must player move
    Resources playerResources; //obtain textures for sprites
    //--------------------------------------------------------------------------------------------------------------------------
    // SET UP FUNCTIONS
    //--------------------------------------------------------------------------------------------------------------------------
    void setVariables();
    void initSprite1();
    void initSprite2();
    void initSprite3();
    void initSprite4();
    void initSprite5();
public:
    //--------------------------------------------------------------------------------------------------------------------------
    // CONSTRUCTORS & DESTRUCTORS
    //--------------------------------------------------------------------------------------------------------------------------
    /** \brief The constructor for the Player class
    \param x The starting x position on the window
    \param y The starting y position on the window
    */
    Player(float x = 470.f, float y = 650.f);
    virtual ~Player();
    //--------------------------------------------------------------------------------------------------------------------------
    // CALCULATIONS
    //--------------------------------------------------------------------------------------------------------------------------
    /** \brief Determines the input from the user to update the players movement
    */
    void refreshInput(); //user input for player movement
    /** \brief This moves the sprite at a speed of playerSpeed in the direction specified
    \param direction A string specifying the direction of movement of player
    \param prevDir A string specifying previous direction of player to determine if change of sprite needed
    */
    void MovePlayer(std::string direction,std::string prevDir); //movement of sprite
    /** \brief Keeps the player wihtin the bounds of the window frame
    */
    void windowCollisions(); //keep player within frame
    //--------------------------------------------------------------------------------------------------------------------------
    // ACCESSORS
    //--------------------------------------------------------------------------------------------------------------------------
    /** \brief This is an accessor for the player's position
    \return The x and y position of the centre of the player sprite
    */
    sf::Vector2<float> GetPos();
    /** \brief This is an accessor for the player's global bounds
    \return Global bounds of the player sprite
    */
    sf::Rect<float> getPlayerBounds();
    //--------------------------------------------------------------------------------------------------------------------------
    // MODIFIERS
    //--------------------------------------------------------------------------------------------------------------------------
    /** \brief This sets player sprite to a new position
    \param x The desired x position
    \param y The desired y position
    */
    void setPos(float x,float y);
    //--------------------------------------------------------------------------------------------------------------------------
    //UPDATE AND RENDER
    //--------------------------------------------------------------------------------------------------------------------------
    /** \brief This updates the player sprite
    \param target The window of the game
    */
    void refresh(sf::RenderTarget* target);
    /** \brief This draws the player sprite on the window
    \param target The window of the game
    */
    void manifest(sf::RenderTarget* target);
};

#endif // PLAYER_H
