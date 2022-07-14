#ifndef GRID_H
#define GRID_H
/** \file Grid.h
    \brief Contains code for constructing Grid class hierarchy

    Grid can be used to organise other game objects into certain locations on the window.
*/
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <vector>
/** \class Grid
    \brief grid class can be used to divide the window screen into sections in which other game objects can be rendered.
    This class divides the screen into rectangular sections whose positions can be accessed by other objects.
    A grid can be created by using this class' construtor as a vector of grid blocks.
 */
class Grid
{
private:
    //----------------------------------------------------------------------------------------------------------------------
    // GRID BLOCK ATTRIBUTES
    //----------------------------------------------------------------------------------------------------------------------
    sf::RectangleShape blockShape; //shape to display sprite in Game over
    //----------------------------------------------------------------------------------------------------------------------
    // SET UP FUNCTIONS
    //----------------------------------------------------------------------------------------------------------------------
    void setBlockShape();
public:
    /** \brief The constructor for the Grid class
    \param x The starting x position on the window
    \param y The starting y position on the window
    */
    Grid(float x,float y);
    virtual ~Grid();
    //----------------------------------------------------------------------------------------------------------------------
    // CALCULATIONS
    //----------------------------------------------------------------------------------------------------------------------

    //----------------------------------------------------------------------------------------------------------------------
    // ACCESSORS
    //----------------------------------------------------------------------------------------------------------------------
    /** \brief This is an accessor for the grid block's position
    \return The x and y position of the centre of the player sprite
    */
    sf::Vector2<float> getBlockPos();
    /** \brief This is an accessor for the grid block's global bounds
    \return Global bounds of the grid block
    */
    sf::Rect<float> getBlockBounds();
    //----------------------------------------------------------------------------------------------------------------------
    // MODIFIERS
    //----------------------------------------------------------------------------------------------------------------------

    //----------------------------------------------------------------------------------------------------------------------
    // UPDATE AND RENDER
    //----------------------------------------------------------------------------------------------------------------------
    /** \brief This draws the grid (if required) on the window
    \param target The window of the game
    */
    void manifest(sf::RenderTarget* target);

};

#endif // GRID_H
