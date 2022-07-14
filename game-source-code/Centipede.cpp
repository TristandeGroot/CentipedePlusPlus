#include "Centipede.h"

//----------------------------------------------------------------------------------------------------------------------
// CONSTRUCTORS AND DESTRUCTORS
//----------------------------------------------------------------------------------------------------------------------

Centipede::Centipede(float x  ,float y)
{
    centiShape.setPosition(x,y);
    setVariables();
    setCentiShape();

}

Centipede::~Centipede()
{
    //dtor
}

//----------------------------------------------------------------------------------------------------------------------
// SET UP FUNCTIONS
//----------------------------------------------------------------------------------------------------------------------
void Centipede::setVariables()
{
    centiSpeed = 3.f;
    centiVertSpeed = 30.f;
    centiGoesRight = true; //initially moves right
}

void Centipede::setCentiShape()
{
    centiShape.setFillColor(sf::Color::Blue); //choose color of Monster
    centiShape.setSize(sf::Vector2f(28.f,28.f));
    centiShape.setOutlineColor(sf::Color::Black);
    centiShape.setOutlineThickness(1.f);
}

//----------------------------------------------------------------------------------------------------------------------
// CALCULATIONS
//----------------------------------------------------------------------------------------------------------------------
void Centipede::refreshMovement()
{
    if (centiGoesRight == true) //right movement
    {
        centiShape.move(centiSpeed,0.f);
        centiDirection();
    }
    if (centiGoesRight == false) //left movement
    {
        centiShape.move(-centiSpeed,0.f);
        centiDirection();
    }
}

void Centipede::centiWindowCollisions()
{
    //Left collision
    sf::FloatRect centiBounds = centiShape.getGlobalBounds();
    if (centiBounds.left <= 0.f)
    {
        centiShape.move(0.f,centiVertSpeed);
        centiGoesRight = true;
    }
    //Right collision
    else if(centiBounds.left + centiBounds.width >= 1000.f)
    {
        centiShape.move(0.f,centiVertSpeed);
        centiGoesRight = false;
    }
}

//----------------------------------------------------------------------------------------------------------------------
// ACCESSORS
//----------------------------------------------------------------------------------------------------------------------
bool Centipede::centiDirection()
{
    return centiGoesRight;
}

float Centipede::getVertSpeed()
{
    return centiVertSpeed;
}

sf::Rect<float> Centipede::getCentiBounds()
{
    auto centiBounds = centiShape.getGlobalBounds();
    return centiBounds;
}

sf::Vector2<float> Centipede::getCentiPos()
{
    return centiShape.getPosition();
}
//----------------------------------------------------------------------------------------------------------------------
// MODIFIERS
//----------------------------------------------------------------------------------------------------------------------
void Centipede::setCentiDirection()
{
    if(centiGoesRight == true)
    {
        centiGoesRight = false;
    }
    else if(centiGoesRight == false)
    {
        centiGoesRight = true;
    }
}

void Centipede::setCentiVertDir()
{
    centiVertSpeed = -centiVertSpeed;
}

void Centipede::setPos(float x,float y)
{
   centiShape.setPosition(x,y);
}
//----------------------------------------------------------------------------------------------------------------------
// UPDATE AND RENDER
//----------------------------------------------------------------------------------------------------------------------
void Centipede::refresh(sf::RenderTarget* target)
{
    //Window bounds collition
    centiWindowCollisions();

    //call update input to check if key pressed for move
    refreshMovement();
}

void Centipede::manifest(sf::RenderTarget * target)
{
    target->draw(centiShape);
}
