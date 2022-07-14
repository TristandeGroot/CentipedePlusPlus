#include "Resources.h"

Resources::Resources()
{
    //ctor
    readInTextures();
    setCentiSprites();
}

Resources::~Resources()
{
    //dtor
}

//------------------------------------------------------------------------------------------------------------------------
// SET UP FUNCTIONS
//------------------------------------------------------------------------------------------------------------------------

void Resources::readInTextures()
{
    if(!backgroundTexture.loadFromFile("resources/oceanBackground.png"))
    {
        std::cout << "Error: Could not load texture file" << "\n";
    }
    if(!playerTexture1.loadFromFile("resources/player.png"))
    {
        std::cout << "Error: Could not load texture file" << "\n";
    }
    if(!playerTexture2.loadFromFile("resources/playerLeftOrientation.png"))
    {
        std::cout << "Error: Could not load texture file" << "\n";
    }
    if(!playerTexture3.loadFromFile("resources/playerRightOrientation.png"))
    {
        std::cout << "Error: Could not load texture file" << "\n";
    }
    if(!playerTexture4.loadFromFile("resources/playerUpOrientation.png"))
    {
        std::cout << "Error: Could not load texture file" << "\n";
    }
    if(!playerTexture5.loadFromFile("resources/playerDownOrientation.png"))
    {
        std::cout << "Error: Could not load texture file" << "\n";
    }
    if(!centiTexture1.loadFromFile("resources/monsterHead-right.png"))
    {
        std::cout << "Error: Could not load texture file" << "\n";
    }
    if(!centiTexture2.loadFromFile("resources/monsterHead-Left.png"))
    {
        std::cout << "Error: Could not load texture file" << "\n";
    }
    if(!centiTexture3.loadFromFile("resources/DragonSkin2.png"))
    {
        std::cout << "Error: Could not load texture file" << "\n";
    }
    if(!octopusTexture.loadFromFile("resources/Octopus.png"))
    {
        std::cout << "Error: Could not load texture file" << "\n";
    }
    if(!jellyTexture1.loadFromFile("resources/JellyFish.png"))
    {
        std::cout << "Error: Could not load texture file" << "\n";
    }
        if(!BombTexture.loadFromFile("resources/SeaBomb.png"))
    {
        std::cout << "Error: Could not load texture file" << "\n";
    }
    if(!BombCloudText.loadFromFile("resources/Explosion.png"))
    {
        std::cout << "Error: Could not load texture file" << "\n";
    }
    if(!anchorTexture.loadFromFile("resources/anchor.png"))
    {
        std::cout << "Error: Could not load texture file" << "\n";
    }


}

void Resources::setCentiSprites()
{
    sf::Sprite tempSpriteObj1;
    tempSpriteObj1.setTexture(centiTexture1);
    centiSpriteVect.push_back(tempSpriteObj1);

    for (int count=1; count<11; count++)
    {
        sf::Sprite tempSpriteObj;
        tempSpriteObj.setTexture(centiTexture3);
        centiSpriteVect.push_back(tempSpriteObj);
    }
}

//------------------------------------------------------------------------------------------------------------------------
// ACCESSORS
//------------------------------------------------------------------------------------------------------------------------
std::vector<sf::Sprite> Resources::centiSpriteVector()
{
    return centiSpriteVect;
}
