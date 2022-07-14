#ifndef GAME_H
#define GAME_H
/** \file Game.h
    \brief Contains code for constructing Game class hierarchy

    The Game class monitors all actions within the game
*/
#include <iostream>
#include <ctime>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <string>

#include "Resources.h"
#include "Player.h"
#include "Centipede.h"
#include "Blast.h"
#include "Octopus.h"
#include "Jelly.h"
#include "Grid.h"
#include "DDTBomb.h"
#include "Anchor.h"

/** \class Grid
    \brief Game class initialises all game objects and refreshes and renders the game objects
    Performs collision checks between all objects
    Keeps score on collisions between the blast and the enemies
    Keeps track of when the game ends
    Renders all Game objects
    Draws all Game objects on the Game window
 */

class Game
{
private:
    //--------------------------------------------------------------------------------------------------------------------------------
    // Textures & Game resources
    //--------------------------------------------------------------------------------------------------------------------------------
    Resources resources;
    //--------------------------------------------------------------------------------------------------------------------------------
    // Game Window
    //--------------------------------------------------------------------------------------------------------------------------------
    sf::VideoMode windowSpecs; //need this to build window -> will hold size and width of window
    sf::RenderWindow* window;
    sf::Event windowEvent;//variable for pollEvents
    sf::Sprite backgroundSprite;
    sf::Font font1;
    sf::Text text;
    sf::Text text1;
    bool GameOver;
    int myScore;
    int lives;
    //--------------------------------------------------------------------------------------------------------------------------------
    // Player Class
    //--------------------------------------------------------------------------------------------------------------------------------
    Player player;
    //--------------------------------------------------------------------------------------------------------------------------------
    // Centipede Class
    //--------------------------------------------------------------------------------------------------------------------------------
    std::vector<Centipede> centiVector;
    std::vector<sf::Sprite> centiSpriteVector;
    std::vector<bool> isHead;
    //--------------------------------------------------------------------------------------------------------------------------------
    // Bomb Class
    //--------------------------------------------------------------------------------------------------------------------------------
    std::vector<Bomb> BombVector;
    std::vector<sf::Sprite> BombSpriteVector;
    std::vector<bool> Exploded;
    std::vector<bool> Scaled;
    std::vector<int> ExplosionTime;
    sf::Texture BombTexture;
    sf::Texture BombCloudText;
    int PrevClock;
    int PrevClock2;
    int PrevClock3;
    //--------------------------------------------------------------------------------------------------------------------------------
    // Lightning Blast Class
    //--------------------------------------------------------------------------------------------------------------------------------
    std::vector<Blast> BlastArsenal;
    //--------------------------------------------------------------------------------------------------------------------------------
    // Octopus Class
    //--------------------------------------------------------------------------------------------------------------------------------
    std::vector<Octopus> OctopusVector;
    std::vector<sf::Sprite> OctSpriteVector;
    bool firstOct;
    bool OctDeleted;
    sf::Texture OctText;
    //--------------------------------------------------------------------------------------------------------------------------------
    // Jellyfish Class
    //--------------------------------------------------------------------------------------------------------------------------------
    std::vector<Jelly> JellyVector;
    std::vector<int> hitCount;
    sf::Texture jellyText;
    std::vector<sf::Sprite> jellySpriteVector;
    //--------------------------------------------------------------------------------------------------------------------------------
    // Grid Class
    //--------------------------------------------------------------------------------------------------------------------------------
    std::vector<std::vector<Grid> > gridBlocks;
    //--------------------------------------------------------------------------------------------------------------------------------
    // Anchor Class
    //--------------------------------------------------------------------------------------------------------------------------------
    std::vector<Anchor> AnchorVector;
    std::vector<sf::Sprite> AnchorSpriteVector;
    sf::Texture anchorText;
    //--------------------------------------------------------------------------------------------------------------------------------
    // Sound
    //--------------------------------------------------------------------------------------------------------------------------------
    sf::SoundBuffer buffer;
    sf::SoundBuffer buffer1;
    sf::Sound play_;
    sf::Sound play1_;
    //--------------------------------------------------------------------------------------------------------------------------------
    // SET UP FUNCTIONS
    //--------------------------------------------------------------------------------------------------------------------------------
    void setVariables();
    void setWindow();
    void setSprites();
    void setMusic();
    void setCentipede();
    void setBombs();
    void setJellyGrid();
    void setOctopus();
    void newJelly(float xPos, float yPos);
    void setScoreDisplay();
    int setRand();
    time_t Clock();
    void setAnchor();
    void newBlast(float x, float y);

public:
    //--------------------------------------------------------------------------------------------------------------------------------
    // Constructor & Destructor
    //--------------------------------------------------------------------------------------------------------------------------------
    /** \brief The constructor and destructor for the Game class
    */
    Game();
    virtual ~Game();
    //--------------------------------------------------------------------------------------------------------------------------------
    // Game Run & Event Functions
    //--------------------------------------------------------------------------------------------------------------------------------
    /** \brief Keeps the window refreshing and rendering
    \return Returns true for the window being open
    */
    const bool running() const;
    /** \brief Determines which key has been pressed by the player
               Closed indicates that the user wants to close the game window
               Escape indicates that the user wants to close the game window
               Space indicates the user shoots a blast from the player object
    */
    void checkEvents();
    //--------------------------------------------------------------------------------------------------------------------------------
    // Calculations
    //--------------------------------------------------------------------------------------------------------------------------------
    /** \brief Determines if the player has lost all three of its lives
    */
    void monsterVictoryCheck();
     /** \brief Determines if the player blast is out of the window bounds and performs necessary deletions
    */
    void blastDeleteCheck();
     /** \brief Determines if the player blast has collided with a game enemy
                Performs necessary deletions on the respective enemy vector objects
    */
    void collisionsCheck();
     /** \brief Determines if the centipede has been completely destroyed by a DDTbomb or blast
                Concludes that the player has won
    */
    void centiDestroyedCheck();
     /** \brief Determines if the centipede has hit the top or bottom of the window
                Changes the centipedes direction of movement to the opposite direction
    */
    void centiChangeDirCheck();
     /** \brief Determines if either the centipede hits the jellyfish, the DDTbomb explodes around it or if the octopus eats it
                Centipede will make a u-turn if it collides with the jellyfish
                DDTbomb will destroy a jellyfish if its within the explosion radius
                Octopus will randomly eat a jellyfish
    */
    void jellyCollisionCheck();
     /** \brief Determines if the centipede, octopus pr anchor has been destroyed by an exploded DDTbomb
    */
    void BombCollisions();
    /** \brief Anchor randomly plants a jellyfish if it is within the player window
    */
    void anchorPosCheck();

    //--------------------------------------------------------------------------------------------------------------------------------
    // Accessors
    //--------------------------------------------------------------------------------------------------------------------------------
    /** \brief Updates the score after monitoring all collisions
    \return The current score of the game
    */
    int updateScore();
    /** \brief Bool variable which controls when the game ends
    */
    bool win;
    //--------------------------------------------------------------------------------------------------------------------------------
    // Update & Refresh
    //--------------------------------------------------------------------------------------------------------------------------------
    /** \brief Updates the Game and all of its events
    */
    void refresh();
    /** \brief Draws all Game objects on the Game window
    */
    void manifest();
};

#endif // GAME_H
