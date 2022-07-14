#ifndef RESOURCES_H
#define RESOURCES_H

/** \file Resources.h
    \brief Contains code for reading in textures and sprites for all
*/

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
using std::string;

/** \class Resources
    \brief This class loads in textures and sprites from files to be used by the classes
 */

class Resources
{
private:
    //------------------------------------------------------------------------------------------------------------------------------
    // GAME SPRITE VARIABLES & VECTORS
    //------------------------------------------------------------------------------------------------------------------------------
    std::vector<sf::Sprite> centiSpriteVect;
    //------------------------------------------------------------------------------------------------------------------------------
    // TEXTURES SET UP
    //------------------------------------------------------------------------------------------------------------------------------
    void readInTextures();
    //------------------------------------------------------------------------------------------------------------------------------
    // SPRITES SET UP
    //------------------------------------------------------------------------------------------------------------------------------
    void setCentiSprites();
public:
    //------------------------------------------------------------------------------------------------------------------------------
    // CONSTRUCTORS AND DESTRUCTORS
    //------------------------------------------------------------------------------------------------------------------------------
    /** \brief Constructor for the Resource class
    */
    Resources();
    virtual ~Resources();
    //------------------------------------------------------------------------------------------------------------------------------
    // GAME TEXTURE VARIABLES
    //------------------------------------------------------------------------------------------------------------------------------
    /** \brief Nomenclature of all textures and sprites
    */
    sf::Texture backgroundTexture;
    sf::Texture playerTexture1;
    sf::Texture playerTexture2;
    sf::Texture playerTexture3;
    sf::Texture playerTexture4;
    sf::Texture playerTexture5;
    sf::Texture centiTexture1;
    sf::Texture centiTexture2;
    sf::Texture centiTexture3;
    sf::Texture octopusTexture;
    sf::Texture jellyTexture1;
    sf::Texture BombTexture;
    sf::Texture BombCloudText;
    sf::Texture anchorTexture;
    //------------------------------------------------------------------------------------------------------------------------------
    // ACCESSORS
    //------------------------------------------------------------------------------------------------------------------------------
    /** \brief Accessor function for the Game class to access the centipede sprite
    */
    std::vector<sf::Sprite> centiSpriteVector();
    //------------------------------------------------------------------------------------------------------------------------------
    // MODIFIERS
    //------------------------------------------------------------------------------------------------------------------------------
};

#endif // RESOURCES_H
