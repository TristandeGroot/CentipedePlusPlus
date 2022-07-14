#include "Player.h"

//--------------------------------------------------------------------------------------------------------------------------
// CONSTRUCTORS & DESTRUCTORS
//--------------------------------------------------------------------------------------------------------------------------
Player::Player(float x, float y)
{
    //ctor
    appearance.setPosition(x,y);
    setVariables();
    initSprite1();
}

Player::~Player()
{
    //dtor
}
//--------------------------------------------------------------------------------------------------------------------------
// SET UP FUNCTIONS
//--------------------------------------------------------------------------------------------------------------------------
void Player::setVariables()
{
    playerSpeed = 10.f;
}

void Player::initSprite1()
{
    //set the texture to the sprite
    appearance.setTexture(playerResources.playerTexture1);
    appearance.scale(0.15f,0.15f);
}

void Player::initSprite2()
{
    //set the texture to the sprite
    appearance.setTexture(playerResources.playerTexture2);
}

void Player::initSprite3()
{
    //set the texture to the sprite
    appearance.setTexture(playerResources.playerTexture3);
}

void Player::initSprite4()
{
    //set the texture to the sprite
    appearance.setTexture(playerResources.playerTexture4);
}

void Player::initSprite5()
{
    //set the texture to the sprite
    appearance.setTexture(playerResources.playerTexture5);
}
//--------------------------------------------------------------------------------------------------------------------------
// CALCULATIONS
//--------------------------------------------------------------------------------------------------------------------------
void Player::refreshInput()
{
    //Keyboard input
    //Left movement:
    std::string direction= " ";
    std::string prevDir = " ";
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        //note: '-' for left and no movement in y thus 0.f
        prevDir = direction;
        direction = "Left";
        MovePlayer(direction,prevDir); //set how much move (add what you give to position)
    }
    //Right Movement:
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        prevDir = direction;
        direction = "Right";
        MovePlayer(direction,prevDir); //set how much move (add what you give to position)
    }
    //Up movement:
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        prevDir = direction;
        direction = "Up";
        MovePlayer(direction,prevDir); //set how much move (add what you give to position)
    }
    //Down movement:
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        direction = "Down";
        MovePlayer(direction,prevDir); //set how much move (add what you give to position)
    }
}

void Player::MovePlayer(std::string direction, std::string prevDir)
{
    //Keyboard input
    //Left movement:
    if(direction == "Left")
    {
        //note: '-' for left and no movement in y thus 0.f
        if(direction != prevDir)
        {
            initSprite2();
        }
        appearance.move(-playerSpeed,0.f); //set how much move (add what you give to position)
    }
    //Right Movement:
    else if(direction == "Right")
    {
        if(direction != prevDir)
        {
            initSprite3();
        }
        appearance.move(playerSpeed,0.f); //set how much move (add what you give to position)
    }
    //Up movement:
    if(direction == "Up")
    {
        if(direction != prevDir && (prevDir != "Left" && prevDir != "Right"))
        {
            initSprite4();
        }
        appearance.move(0.f,-playerSpeed); //set how much move (add what you give to position)
    }
    //Down movement:
    else if(direction == "Down")
    {
        if(direction != prevDir && (prevDir != "Left" && prevDir != "Right"))
        {
            initSprite5();
        }
        appearance.move(0.f,playerSpeed); //set how much move (add what you give to position)
    }
}

void Player::windowCollisions()
{
    //Left collision
    sf::FloatRect playerBounds = appearance.getGlobalBounds();
    if (playerBounds.left <= -40.f)
    {
        appearance.move(playerSpeed,0.f);
    }
    //Right collision
    else if(playerBounds.left + playerBounds.width >= 1040.f)
    {
        appearance.move(-playerSpeed,0.f);
    }
    //Top collision
    if (playerBounds.top <= 470.f)
    {
        appearance.move(0.f,playerSpeed);
    }
    //Bottom collision
    else if(playerBounds.top + playerBounds.height >= 719.f)
    {
        appearance.move(0.f,-playerSpeed);
    }
}
//--------------------------------------------------------------------------------------------------------------------------
// ACCESSORS
//--------------------------------------------------------------------------------------------------------------------------
sf::Vector2<float> Player::GetPos()
{
   return appearance.getPosition();
}

sf::Rect<float> Player::getPlayerBounds()
{
    return appearance.getGlobalBounds();
}
//--------------------------------------------------------------------------------------------------------------------------
// MODIFIERS
//--------------------------------------------------------------------------------------------------------------------------
void Player::setPos(float x,float y)
{
   appearance.setPosition(x,y);
}
//--------------------------------------------------------------------------------------------------------------------------
// UPDATE AND RENDER
//--------------------------------------------------------------------------------------------------------------------------
void Player::refresh(sf::RenderTarget* target)
{
    //Window bounds collition
    windowCollisions();

    //call update input to check if key pressed for move
    refreshInput();
}

void Player::manifest(sf::RenderTarget * target)
{
    target->draw(appearance);
}
