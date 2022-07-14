#ifndef ANCHOR_H
#define ANCHOR_H

/** \file Anchor.h
    \brief Contains code for constructing Anchor class hierarchy
    The Anchor moves down vertically from set position
 */

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <vector>

/** \class Anchor
    \brief Anchor moves down vertically and resets when hitting bottom of window.
    Creates a rectangle to be used as a base for a sprite.
    Game object with descending vertical movement, spawning from a random horizontal coordinate.
    Reaching bottom of window resets position.
 */
class Anchor
{
private:
    //----------------------------------------------------------------------------------------------------------------------
    // ANCHOR ATTRIBUTES
    //----------------------------------------------------------------------------------------------------------------------
    sf::RectangleShape AnchorShape; //shape to display sprite in Game over
    float AnchorSpeed;
    float x,y;
    //----------------------------------------------------------------------------------------------------------------------
    // SET UP FUNCTIONS
    //----------------------------------------------------------------------------------------------------------------------
    void setVariables();
    void setAnchorShape();
    void setStartPos();

public:

    //----------------------------------------------------------------------------------------------------------------------
    // CONSTRUCTORS AND DESTRUCTORS
    //----------------------------------------------------------------------------------------------------------------------
    /** \brief The constructor for the Anchor class
    \param x The starting x position on the window
    \param y The starting y position on the window
    */
    Anchor();
    virtual ~Anchor();
    //----------------------------------------------------------------------------------------------------------------------
    // CALCULATIONS
    //----------------------------------------------------------------------------------------------------------------------
    /** \brief This moves the base rectangle at a speed of AnchorSpeed down when called
    \param AnchorSpeed is 3.f and can be adjusted in the private variable function setVariables().
    */
    void refreshMovement();
    /** \brief This resets the base rectangle to new starting position if reaches the bottom of the window
    Calls the private function setStartPos() to reset the starting position of the rectangle.
    */
    void WindowCollisions();
    //----------------------------------------------------------------------------------------------------------------------
    // ACCESSORS
    //----------------------------------------------------------------------------------------------------------------------
    /** \brief This is an accessor for the rectangle's position
    \return The x and y position of the centre of the base rectangle
    */
    sf::Vector2<float> getPos();
    //----------------------------------------------------------------------------------------------------------------------
    /** \brief This is an accessor for the rectangle's global bounds
    \return Global bounds of the base rectangle
    */
    sf::Rect<float> getBounds();
    //----------------------------------------------------------------------------------------------------------------------
    // MODIFIERS
    //----------------------------------------------------------------------------------------------------------------------
    /** \brief This sets rectangle to a new position
    \param x The desired x position
    \param y The desired y position
    */
    void setPos(float x,float y);
    //----------------------------------------------------------------------------------------------------------------------
    // UPDATE AND RENDER
    //----------------------------------------------------------------------------------------------------------------------
    /** \brief This updates the base rectangle
    \param target The window of the game
    */
    void refresh(sf::RenderTarget* target);
    /** \brief This draws the base rectangle on the window
    \param target The window of the game
    */
    void manifest(sf::RenderTarget* target);

};

#endif // ANCHOR_H
