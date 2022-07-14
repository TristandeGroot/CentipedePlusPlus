#ifndef OCTOPUS_H
#define OCTOPUS_H
/** \file Octopus.h
    \brief Contains code for constructing Octopus class hierarchy

    The Octopus moves in a random zig zag fashion in area at bottom of screen
*/
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
#include <stdlib.h>
#include <string.h>
/** \class Octopus
    \brief octopus starts at arbitrary position off screen and slowly moves towards screen.
    When reaching screen the octopus begins to move in random zig zag fashion within the player movement area.
    The octopus position can be reset to its start position (such as when destroyed by the player)
 */
class Octopus
{
private:
    //----------------------------------------------------------------------------------------------------------------------
    // ANCHOR ATTRIBUTES
    //----------------------------------------------------------------------------------------------------------------------
    sf::RectangleShape OctopusShape;
    float OctopusSpeed;
    bool OctopusGoesRight;
    bool OctInWindow;
    std::string prevDirection;
    std::string direction;

    //----------------------------------------------------------------------------------------------------------------------
    // SET UP FUNCTIONS
    //----------------------------------------------------------------------------------------------------------------------
    void setVariables();
    void initShape();
    int setRandX();
    int setRandY();

public:
    //----------------------------------------------------------------------------------------------------------------------
    // CONSTRUCTORS AND DESTRUCTORS
    //----------------------------------------------------------------------------------------------------------------------
    /** \brief The constructor for the Octopus class
    \param x The starting x position on the window
    \param y The starting y position on the window
    */
    Octopus(float x = -1400.f, float y =500.f);
    virtual ~Octopus();
    //----------------------------------------------------------------------------------------------------------------------
    // CALCULATIONS
    //----------------------------------------------------------------------------------------------------------------------
    /** \brief Updates the movement of the octopus base rectangle
    */
    void refreshMovement();
    /** \brief This moves octopus in opposite direction and resets direction when hitting window bounds
    */
    void WindowCollision();
    /** \brief When the octopus is within the window, its random movement pattern is activated using this function
    */
    void checkInWindow();
    //----------------------------------------------------------------------------------------------------------------------
    // ACCESSORS
    //----------------------------------------------------------------------------------------------------------------------
    /** \brief This is an accessor for the octopus' global bounds
    \return Global bounds of the octopus rectangle
    */
    sf::Vector2<float> GetOctPos();
    /** \brief This is an accessor for the octopus' global bounds
    \return Global bounds of the octopus rectangle
    */
    sf::Rect<float> getOctopusBounds();
    //----------------------------------------------------------------------------------------------------------------------
    // MODIFIERS
    //----------------------------------------------------------------------------------------------------------------------
    /** \brief This moves octopus rectangle
    */
    void MoveOctopus();
    /** \brief This sets player sprite to a new position
    \param x The desired x position
    \param y The desired y position
    */
    void setOctPos(float x,float y);
    //----------------------------------------------------------------------------------------------------------------------
    // UPDATE AND RENDER
    //----------------------------------------------------------------------------------------------------------------------
    /** \brief This updates the octopus rectangle
    \param target The window of the game
    */
    void refreshOctopus(sf::RenderTarget* target);
    /** \brief This draws the octopus rectangle on the window
    \param target The window of the game
    */
    void manifestOctopus(sf::RenderTarget* target);
};

#endif // OCTOPUS_H
