#include "Anchor.h"


//----------------------------------------------------------------------------------------------------------------------
// CONSTRUCTORS AND DESTRUCTORS
//----------------------------------------------------------------------------------------------------------------------

Anchor::Anchor()
{

    setVariables();
    setStartPos();

}

Anchor::~Anchor()
{
    //dtor
}

//----------------------------------------------------------------------------------------------------------------------
// SET UP FUNCTIONS
//----------------------------------------------------------------------------------------------------------------------
void Anchor::setVariables()
{
    AnchorSpeed = 3.f;
}

void Anchor::setStartPos()
{
    //set random position horizontally
    x = rand()%1000;
    AnchorShape.setPosition(x,-1400.f);
}

void Anchor::setAnchorShape()
{
    AnchorShape.setFillColor(sf::Color::Blue); //choose color of Monster
    AnchorShape.setSize(sf::Vector2f(28.f,28.f));
    AnchorShape.setOutlineColor(sf::Color::Black);
    AnchorShape.setOutlineThickness(1.f);
}

//----------------------------------------------------------------------------------------------------------------------
// CALCULATIONS
//----------------------------------------------------------------------------------------------------------------------
void Anchor::refreshMovement()
{
    AnchorShape.move(0.f, AnchorSpeed);
}

void Anchor::WindowCollisions()
{
    //Bottom collision
    sf::FloatRect AnchorBounds = AnchorShape.getGlobalBounds();
    if (AnchorBounds.top > 720.f)
    {
        setStartPos();
    }
}

//----------------------------------------------------------------------------------------------------------------------
// ACCESSORS
//----------------------------------------------------------------------------------------------------------------------
sf::Rect<float> Anchor::getBounds()
{
    return AnchorShape.getGlobalBounds();
}

sf::Vector2<float> Anchor::getPos()
{
    return AnchorShape.getPosition();
}
//----------------------------------------------------------------------------------------------------------------------
// MODIFIERS
//---------------------------------------------------------------------------------------------------------------------
void Anchor::setPos(float x,float y)
{
   AnchorShape.setPosition(x,y);
}
//----------------------------------------------------------------------------------------------------------------------
// UPDATE AND RENDER
//----------------------------------------------------------------------------------------------------------------------
void Anchor::refresh(sf::RenderTarget* target)
{
    //Window bounds collition
    WindowCollisions();

    //movement update
    refreshMovement();
}

void Anchor::manifest(sf::RenderTarget * target)
{
    target->draw(AnchorShape);
}
