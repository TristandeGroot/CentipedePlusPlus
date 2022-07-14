#ifndef GAMETESTS_H
#define GAMETESTS_H

#include <iostream>
#include <ctime>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <string>

#include "../game-source-code/Resources.h"
#include "../game-source-code/Player.h"
#include "../game-source-code/Centipede.h"
#include "../game-source-code/Blast.h"
#include "../game-source-code/Octopus.h"
#include "../game-source-code/Jelly.h"
#include "../game-source-code/Grid.h"
#include "../game-source-code/DDTBomb.h"
#include "../game-source-code/Anchor.h"

class GameTests
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

public:
    //--------------------------------------------------------------------------------------------------------------------------------
    // Constructor & Destructor
    //--------------------------------------------------------------------------------------------------------------------------------
    GameTests();
    virtual ~GameTests();

    //--------------------------------------------------------------------------------------------------------------------------------
    // Game Run & Event Functions
    //--------------------------------------------------------------------------------------------------------------------------------
    const bool running() const;
    void checkEvents();
    //--------------------------------------------------------------------------------------------------------------------------------
    // Calculations
    //--------------------------------------------------------------------------------------------------------------------------------
    void monsterVictoryCheck();
    void blastDeleteCheck();
    void collisionsCheck();
    void centiDestroyedCheck();
    void centiChangeDirCheck();
    void jellyCollisionCheck();
    void BombCollisions();
    void anchorPosCheck();
    //--------------------------------------------------------------------------------------------------------------------------------
    // Accessors
    //--------------------------------------------------------------------------------------------------------------------------------
    int updateScore();
    bool win;
    //--------------------------------------------------------------------------------------------------------------------------------
    // TEST CASE Accessors
    //--------------------------------------------------------------------------------------------------------------------------------
    Player accessPlayer();
    std::vector<Centipede> accessCenti();
    std::vector<Octopus> accessOct();
    std::vector<Bomb> accessBombs();
    std::vector<bool> accessExplosion();
    std::vector<Blast> accessBlast();
    std::vector<Jelly> accessJelly();
    std::vector<Anchor> accessAnchor();
    int accessLives();
    std::vector<int> accessHitCount();
    std::vector<bool> accessIsHead();
    //--------------------------------------------------------------------------------------------------------------------------------
    // TEST CASE Modifiers
    //--------------------------------------------------------------------------------------------------------------------------------
    void modPlayerPos(float x, float y);
    void modCentiPos(float x, float y);
    void modOctPos(float x, float y);
    void modBombPos(float x, float y,int pos);
    void modExplodedPos();
    void modBlastPos(float x, float y);
    void newBlast(float x, float y);
    void modJellyPos(float x, float y);
    void modAnchorPos(float x, float y);
    //--------------------------------------------------------------------------------------------------------------------------------
    // Update & Refresh
    //--------------------------------------------------------------------------------------------------------------------------------
    void refresh();
    void manifest();
};
#endif // GAMETESTS_H
