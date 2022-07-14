#include "Blast.h"
#include <iostream>

//----------------------------------------------------------------------------------------------------------------------
// CONSTRUCTORS AND DESTRUCTORS
//----------------------------------------------------------------------------------------------------------------------

Blast::Blast()
{

}

Blast::Blast(float x, float y)
{
    //ctor
    blastShape.setPosition(x,y);
    setVariables();
    setBlastShape();
}

Blast::~Blast()
{
    //dtor
}

//----------------------------------------------------------------------------------------------------------------------
// SET UP FUNCTIONS
//----------------------------------------------------------------------------------------------------------------------

void Blast::setVariables()
{
    blastSpeed = 10.f;
}

void Blast::setBlastShape()
{
    blastShape.setFillColor(sf::Color::Magenta); //choose color of Monster
    blastShape.setRadius(5.f);
    blastShape.setOutlineThickness(2.f);
    blastShape.setOutlineColor(sf::Color::Black);
}

//----------------------------------------------------------------------------------------------------------------------
// CALCULATIONS
//----------------------------------------------------------------------------------------------------------------------

void Blast::refreshMovement()
{
    blastShape.move(0.f,-blastSpeed);
}

bool Blast::blastCollisions()
{
    //Top of screen collision-> object must be deleted
    sf::FloatRect blastBounds = blastShape.getGlobalBounds();
    if (blastBounds.top <= 0.f)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//----------------------------------------------------------------------------------------------------------------------
// ACCESSORS
//----------------------------------------------------------------------------------------------------------------------

sf::Rect<float> Blast::getBlastBounds()
{
    return blastShape.getGlobalBounds();
}

sf::Vector2<float> Blast::GetPos()
{
   return blastShape.getPosition();
}

//----------------------------------------------------------------------------------------------------------------------
// MODIFIERS
//---------------------------------------------------------------------------------------------------------------------

void Blast::setPos(float x,float y)
{
   blastShape.setPosition(x,y);
}

//----------------------------------------------------------------------------------------------------------------------
// UPDATE AND RENDER
//----------------------------------------------------------------------------------------------------------------------

void Blast::refresh(sf::RenderTarget* target)
{
    //Window bounds collition
    blastCollisions();

    //call update input to check if key pressed for move
    refreshMovement();
}

void Blast::manifest(sf::RenderTarget* target)
{
    target->draw(blastShape);
}
