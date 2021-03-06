#include "Grid.h"

Grid::Grid(float x, float y)
{
    blockShape.setPosition(x,y);
    setBlockShape();
}

Grid::~Grid()
{
    //dtor
}
//----------------------------------------------------------------------------------------------------------------------
// SET UP FUNCTIONS
//----------------------------------------------------------------------------------------------------------------------

void Grid::setBlockShape()
{
    blockShape.setFillColor(sf::Color::Transparent); //choose color of Monster
    blockShape.setSize(sf::Vector2f(28.f,28.f));
    blockShape.setOutlineColor(sf::Color::Black);
    blockShape.setOutlineThickness(1.f);
}

//----------------------------------------------------------------------------------------------------------------------
// CALCULATIONS
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
// ACCESSORS
//---------------------------------------------------------------------------------------------------------------------
sf::Vector2<float> Grid::getBlockPos()
{
    return blockShape.getPosition();
}

sf::Rect<float> Grid::getBlockBounds()
{
    return blockShape.getGlobalBounds();
}

//----------------------------------------------------------------------------------------------------------------------
// MODIFIERS
//----------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------
// UPDATE AND RENDER
//----------------------------------------------------------------------------------------------------------------------
void Grid::manifest(sf::RenderTarget* target)
{
   target->draw(blockShape);
}
