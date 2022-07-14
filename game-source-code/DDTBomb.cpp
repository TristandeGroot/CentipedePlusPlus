#include "DDTBomb.h"

//----------------------------------------------------------------------------------------------------------------------
// CONSTRUCTORS AND DESTRUCTORS
//----------------------------------------------------------------------------------------------------------------------

Bomb::Bomb(float x, float y)
{
    //ctor
    BombShape.setPosition(x,y);
    //setVariables();
    setBombShape();
}

Bomb::~Bomb()
{
    //dtor
}

//----------------------------------------------------------------------------------------------------------------------
// SET UP FUNCTIONS
//----------------------------------------------------------------------------------------------------------------------

void Bomb::setBombShape()
{
    BombShape.setFillColor(sf::Color::Blue); //choose color of Monster
    BombShape.setSize(sf::Vector2f(28.f,28.f));
    BombShape.setOutlineColor(sf::Color::Black);
    BombShape.setOutlineThickness(1.f);
    BombShape.scale(1,1);
}

//----------------------------------------------------------------------------------------------------------------------
// CALCULATIONS
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
// ACCESSORS
//----------------------------------------------------------------------------------------------------------------------

sf::Vector2<float> Bomb::getBombPos()
{
   auto position = BombShape.getPosition();
   return position;
}

sf::Rect<float> Bomb::getBombBounds()
{
    return BombShape.getGlobalBounds();
}

void Bomb::setBombScale(int x, int y)
{
    BombShape.scale(x,y);
}

//----------------------------------------------------------------------------------------------------------------------
// MODIFIERS
//---------------------------------------------------------------------------------------------------------------------
void Bomb::setPos(float x,float y)
{
   BombShape.setPosition(x,y);
}
//----------------------------------------------------------------------------------------------------------------------
// UPDATE AND RENDER
//----------------------------------------------------------------------------------------------------------------------

void Bomb::manifestBomb(sf::RenderTarget* target)
{
    target->draw(BombShape);
}


