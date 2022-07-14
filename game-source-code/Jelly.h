#ifndef JELLY_H
#define JELLY_H
/** \file Jelly.h
    \brief Contains code for constructing Jellyfish class hierarchy

    A field of jellyfish can be randomly spawned.
*/
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
/** \class Jelly
    \brief jellyfish can be spawned using this class. A base rectangle is generated over which the jellyfish sprite can be displayed.
    The jellyfish are stationary, thus this class is used for the position for displaying sprites.
 */
class Jelly
{
private:
    //----------------------------------------------------------------------------------------------------------------------
    // CENTIPEDE ATTRIBUTES
    //----------------------------------------------------------------------------------------------------------------------
    sf::RectangleShape jellyShape; //shape to display sprite in Game over
    //----------------------------------------------------------------------------------------------------------------------
    // SET UP FUNCTIONS
    //----------------------------------------------------------------------------------------------------------------------
    void setVariables();
    void setJellyShape();
public:
    //--------------------------------------------------------------------------------------------------------------------------
    // CONSTRUCTORS & DESTRUCTORS
    //--------------------------------------------------------------------------------------------------------------------------
    /** \brief The constructor for the Jelly class
    \param x The starting x position on the window
    \param y The starting y position on the window
    */
    Jelly(float x  ,float y);
    virtual ~Jelly();
    //--------------------------------------------------------------------------------------------------------------------------
    // CALCULATIONS
    //--------------------------------------------------------------------------------------------------------------------------

    //--------------------------------------------------------------------------------------------------------------------------
    // ACCESSORS
    //--------------------------------------------------------------------------------------------------------------------------
    /** \brief This is an accessor for the jellyfish's position
    \return The x and y position of the centre of the jellyfish base rectangle
    */
    sf::Vector2<float> getJellyPos();
    /** \brief This is an accessor for the jellyfish's global bounds
    \return Global bounds of the jellyfish base rectangle
    */
    sf::Rect<float> getJellyBounds();
    //--------------------------------------------------------------------------------------------------------------------------
    // MODIFIERS
    //--------------------------------------------------------------------------------------------------------------------------
    /** \brief This sets jellyfish to a new position
    \param x The desired x position
    \param y The desired y position
    */
    void setPos(float x,float y);
    //--------------------------------------------------------------------------------------------------------------------------
    //UPDATE AND RENDER
    //--------------------------------------------------------------------------------------------------------------------------
    /** \brief This updates the jellyfish
    \param target The window of the game
    */
    void refresh(sf::RenderTarget* target);
    /** \brief This draws the jellyfish base rectangle on the window
    \param target The window of the game
    */
    void manifest(sf::RenderTarget* target);
};


#endif // JELLY_H
