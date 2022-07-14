#ifndef DDTBOMB_H
#define DDTBOMB_H
/** \file DDTBomb.h
    \brief Contains code for constructing Bomb class hierarchy

    The Sea mine bomb is spawned spontaneously accross the window.
*/
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
/** \class Bomb
    \brief bomb base rectangle is spawned at specified location on window.
    The bomb is unmoving.
 */
class Bomb
{
private:
    //----------------------------------------------------------------------------------------------------------------------
    // CENTIPEDE ATTRIBUTES
    //----------------------------------------------------------------------------------------------------------------------
    sf::RectangleShape BombShape; //shape to display sprite in Game over
    //----------------------------------------------------------------------------------------------------------------------
    // SET UP FUNCTIONS
    //----------------------------------------------------------------------------------------------------------------------
    void setVariables();
    void setBombShape();
public:
    //--------------------------------------------------------------------------------------------------------------------------
    // CONSTRUCTORS & DESTRUCTORS
    //--------------------------------------------------------------------------------------------------------------------------
    /** \brief The constructor for the Bomb class
    \param x The starting x position on the window
    \param y The starting y position on the window
    */
    Bomb(float x  ,float y);
    virtual ~Bomb();
    //--------------------------------------------------------------------------------------------------------------------------
    // ACCESSORS
    //--------------------------------------------------------------------------------------------------------------------------
    /** \brief This is an accessor for the bomb's position
    \return The x and y position of the centre of the bomb rectangle
    */
    sf::Vector2<float> getBombPos();
    /** \brief This is an accessor for the bomb's global bounds
    \return Global bounds of the bomb base rectangle
    */
    sf::Rect<float> getBombBounds();
    /** \brief This is an accessor for the bomb's global bounds
    \param The desired scale of the width of the bomb
    \param The desired scale of the height of the bomb
    */
    void setBombScale(int  x, int y);
    //--------------------------------------------------------------------------------------------------------------------------
    // MODIFIERS
    //--------------------------------------------------------------------------------------------------------------------------
    /** \brief This sets bomb rectangle to a new position
    \param x The desired x position
    \param y The desired y position
    */
    void setPos(float x,float y);
    //--------------------------------------------------------------------------------------------------------------------------
    //UPDATE AND RENDER
    //--------------------------------------------------------------------------------------------------------------------------
    /** \brief This draws the bomb rectangle on the window
    \param target The window of the game
    */
    void manifestBomb(sf::RenderTarget* target);
};

#endif // DDTBOMB_H

