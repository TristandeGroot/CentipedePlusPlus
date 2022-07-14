#include "Octopus.h"

//----------------------------------------------------------------------------------------------------------------------
// CONSTRUCTORS AND DESTRUCTORS
//----------------------------------------------------------------------------------------------------------------------
Octopus::Octopus(float x, float y)
{
    //ctor
    OctopusShape.setPosition(x,y);
    setVariables();
    initShape();
}

Octopus::~Octopus()
{
    //dtor
}

//----------------------------------------------------------------------------------------------------------------------
// SET UP FUNCTIONS
//----------------------------------------------------------------------------------------------------------------------
void Octopus::setVariables()
{
    OctopusSpeed = 5.f;
    prevDirection = "DownRight";
    direction = "DownRight";
    OctInWindow = false;
}

void Octopus::initShape()
{
    OctopusShape.setFillColor(sf::Color::Yellow);
    OctopusShape.setSize(sf::Vector2f(28.f,28.f));
    OctopusShape.setOutlineThickness(1.f);
    OctopusShape.setOutlineColor(sf::Color::Black);
}

int Octopus::setRandX()
{
    int num = rand()%1000;
    return num;
}

int Octopus::setRandY()
{
    int num = rand()%700;
    int prevNum = num;

    if(num>650&&setRandX()==num)
    {
        return num;
    }
    return prevNum;
}
//----------------------------------------------------------------------------------------------------------------------
// CALCULATIONS
//----------------------------------------------------------------------------------------------------------------------
void Octopus::refreshMovement()
{
    MoveOctopus();

}

void Octopus::WindowCollision()
{
     if (OctopusShape.getPosition().y >=setRandY() && direction=="DownRight")
    {
        prevDirection = direction;
        direction = "UpRight";
    }
    if (OctopusShape.getPosition().y >=700 && direction=="DownLeft")
    {
        prevDirection = direction;
        direction = "UpLeft";
    }

        if (OctopusShape.getPosition().x <=5 && direction=="DownLeft")
    {
        prevDirection = direction;
        direction = "DownRight";
    }

        if (OctopusShape.getPosition().y <=600 && direction=="UpLeft")
    {
        prevDirection = direction;
        direction = "DownLeft";
    }

        if (OctopusShape.getPosition().y <=setRandY() && direction=="UpRight")
    {
        prevDirection = direction;
        direction = "DownRight";
    }

        if (OctopusShape.getPosition().x >=950 && direction=="UpRight")
    {
        prevDirection = direction;
        direction = "UpLeft";
    }

}

void Octopus::checkInWindow()
{
    if (OctopusShape.getPosition().x > 0.f)
    {
        OctInWindow = true;
    }
}
//----------------------------------------------------------------------------------------------------------------------
// ACCESSORS
//----------------------------------------------------------------------------------------------------------------------

sf::Rect<float> Octopus::getOctopusBounds()
{
    auto OctopusBounds = OctopusShape.getGlobalBounds();
    return OctopusBounds;
}

sf::Vector2<float> Octopus::GetOctPos()
{
   auto position = OctopusShape.getPosition();
   return position;
}
//----------------------------------------------------------------------------------------------------------------------
// MODIFIERS
//---------------------------------------------------------------------------------------------------------------------
void Octopus::MoveOctopus()
{
    if (OctInWindow ==true)
    {
        if (prevDirection == "DownRight" && direction == "DownRight")
        {
            OctopusShape.move(OctopusSpeed,OctopusSpeed);
        }
        if (prevDirection == "UpRight" && direction == "DownRight")
        {
            OctopusShape.move(OctopusSpeed,OctopusSpeed);
        }

        if (prevDirection == "UpRight" && direction == "UpLeft")
        {
            OctopusShape.move(-OctopusSpeed,-OctopusSpeed);
        }

        if (prevDirection == "DownLeft" && direction == "DownRight")
        {
            OctopusShape.move(OctopusSpeed,OctopusSpeed);
        }
        if (prevDirection == "DownLeft" && direction == "UpLeft")
        {
            OctopusShape.move(-OctopusSpeed,- OctopusSpeed);
        }

        if(prevDirection=="DownRight" && direction=="UpRight" )
        {
            OctopusShape.move(OctopusSpeed,-OctopusSpeed);
        }

        if(prevDirection=="UpLeft" && direction=="DownLeft" )
        {
            OctopusShape.move(-OctopusSpeed,OctopusSpeed);
        }
    }
    else if (OctInWindow == false)
    {
        OctopusShape.move(OctopusSpeed,0.f);
    }

}

void Octopus::setOctPos(float x, float y)
{
    OctopusShape.setPosition(x,y);
}
//----------------------------------------------------------------------------------------------------------------------
// UPDATE AND RENDER
//----------------------------------------------------------------------------------------------------------------------
void Octopus::refreshOctopus(sf::RenderTarget* target)
{
    WindowCollision();
    checkInWindow();
    refreshMovement();
}

void Octopus::manifestOctopus(sf::RenderTarget* target)
{
    target->draw(OctopusShape);
}
