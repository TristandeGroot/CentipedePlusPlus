#ifndef CENTIPEDE_H
#define CENTIPEDE_H
/** \file Centipede.h
    \brief Contains code for constructing Centipede class hierarchy

    The centipede class generates the segment of a centipede
*/
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <vector>
/** \class Centipede
    \brief the centipede class generates a segement of a centipede for the centipede train.
    The class generates a base rectangle over which a sprite vector can be displayed.
    The centipede segment generated must make its way down the screen, descending one row when interacting with a window bound.
    The centipede segment must change direction when interacting with the bottom window bound.
 */
class Centipede
{
private:
    //----------------------------------------------------------------------------------------------------------------------
    // CENTIPEDE ATTRIBUTES
    //----------------------------------------------------------------------------------------------------------------------
    sf::RectangleShape centiShape; //shape to display sprite in Game over
    float centiSpeed;
    float centiVertSpeed;
    bool centiGoesRight;
    //----------------------------------------------------------------------------------------------------------------------
    // SET UP FUNCTIONS
    //----------------------------------------------------------------------------------------------------------------------
    void setVariables();
    void setCentiShape();

public:
    //----------------------------------------------------------------------------------------------------------------------
    // CONSTRUCTORS AND DESTRUCTORS
    //----------------------------------------------------------------------------------------------------------------------
    /** \brief The constructor for the Centipede class
    \param x The starting x position on the window
    \param y The starting y position on the window
    */
    Centipede(float x  ,float y);
    virtual ~Centipede();
    //----------------------------------------------------------------------------------------------------------------------
    // CALCULATIONS
    //----------------------------------------------------------------------------------------------------------------------
    /** \brief Call to move in horizontal direction (LEFT or RIGHT)
    */
    void refreshMovement();
    /** \brief Call to check if overlapping window boundary
    */
    void centiWindowCollisions();
    //----------------------------------------------------------------------------------------------------------------------
    // ACCESSORS
    //----------------------------------------------------------------------------------------------------------------------
    /** \brief This is an accessor for the centipede rectangle's horizontal speed.
    \return centiSpeed float speed of rectangle in horizontal direction.
    */
    bool centiDirection();
    /** \brief This is an accessor for the centipede rectangle's vertical speed.
    \return centiVertSpeed float speed of rectangle in vertical direction.
    */
    float getVertSpeed();
    /** \brief This is an accessor for the centipede rectangle's position
    \return The x and y position of the centre of the centipede rectangle
    */
    sf::Vector2<float> getCentiPos();
    /** \brief This is an accessor for the centipede rectangle's global bounds
    \return Global bounds of the centipede rectangle
    */
    sf::Rect<float> getCentiBounds();
    //----------------------------------------------------------------------------------------------------------------------
    // MODIFIERS
    //----------------------------------------------------------------------------------------------------------------------
    /** \brief This is a modifier for the centipede rectangle's horizontal speed and direction.
    */
    void setCentiDirection();
    /** \brief This is a modifier for the centipede rectangle's vertical speed and direction.
    */
    void setCentiVertDir();
    /** \brief This sets base rectangle to a new position
    \param x The desired x position
    \param y The desired y position
    */
    void setPos(float x,float y);
    //----------------------------------------------------------------------------------------------------------------------
    // UPDATE AND RENDER
    //----------------------------------------------------------------------------------------------------------------------
    /** \brief This updates the centipede segment rectangle
    \param target The window of the game
    */
    void refresh(sf::RenderTarget* target);
    /** \brief This draws the centipede segment on the window
    \param target The window of the game
    */
    void manifest(sf::RenderTarget* target);

};

#endif // CENTIPEDE_H
