#include "../game-source-code/Game.h"
#include "../game-source-code/Splashscreen.h"
#include "../game-source-code/Player.h"
#include "../game-source-code/Centipede.h"
#include "../game-source-code/Blast.h"
#include "../game-source-code/Anchor.h"
#include "../game-source-code/Octopus.h"
#include "GameTests.h"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <vector>
#include <iostream>


//--------------------------------------------------------------------------------------------------------------------
// GENERAL TESTS
//--------------------------------------------------------------------------------------------------------------------

TEST_CASE("Check if key is detected when pressed")
{
    CHECK(sf::Keyboard::isKeyPressed);
}

//--------------------------------------------------------------------------------------------------------------------
// PLAYER MOVEMENT TESTS
//--------------------------------------------------------------------------------------------------------------------

TEST_CASE("Check if player moves right")
{
    Player player_;

    player_.MovePlayer("Right","Right");
    auto moved = player_.GetPos();
    sf::Vector2<float> newPos = {480.f,650.f};

    CHECK(moved==newPos);
}

TEST_CASE("Check if player moves left")
{
    Player player_;

    player_.MovePlayer("Left","Left");
    auto moved = player_.GetPos();
    sf::Vector2<float> newPos = {460.f,650.f};

    CHECK(moved==newPos);
}

TEST_CASE("Check if player moves Up")
{
    Player player_;

    player_.MovePlayer("Up","Up");
    auto moved = player_.GetPos();
    sf::Vector2<float> newPos = {470.f,640.f};

    CHECK(moved==newPos);
}


TEST_CASE("Check if player moves Down")
{
    Player player_;

    player_.MovePlayer("Up","Up");
    player_.MovePlayer("Up","Up");
    player_.MovePlayer("Up","Up");
    player_.MovePlayer("Down","Down");
    auto moved = player_.GetPos();
    sf::Vector2<float> newPos = {470.f,630.f};

    CHECK(moved==newPos);
}

//--------------------------------------------------------------------------------------------------------------
//PLAYER WINDOW COLLISION TESTS
//--------------------------------------------------------------------------------------------------------------

TEST_CASE("Check if player bounces when it hits the Right bounds")
{
    Player player_;
    player_.setPos(1000.f,400.f);
    player_.MovePlayer("Right","Right");

    player_.windowCollisions();
    auto moved = player_.GetPos();

    sf::Vector2<float> newPos = {1000.f,410.f};

    CHECK(moved==newPos);
}

TEST_CASE("Check if player bounces when it hits the Left bounds")
{
    Player player_;
    player_.setPos(-35.f,400.f);

    player_.MovePlayer("Left","Left");

    player_.windowCollisions();
    auto moved = player_.GetPos();

    sf::Vector2<float> newPos = {-35.f,410.f};

    CHECK(moved==newPos);
}

TEST_CASE("Check if player bounces when it hits the Left bounds")
{
    Player player_;
    player_.setPos(-35.f,400.f);

    player_.MovePlayer("Left","Left");

    player_.windowCollisions();
    auto moved = player_.GetPos();

    sf::Vector2<float> newPos = {-35.f,410.f};

    CHECK(moved==newPos);
}

TEST_CASE("Check if player bounces when it hits the Top bounds")
{
    Player player_;
    player_.setPos(465.f,400.f);

    player_.MovePlayer("Up","Up");

    player_.windowCollisions();
    auto moved = player_.GetPos();

    sf::Vector2<float> newPos = {465.f,400.f};

    CHECK(moved==newPos);
}

TEST_CASE("Check if player bounces when it hits the Bottom bounds")
{
    Player player_;
    player_.setPos(715.f,400.f);

    player_.MovePlayer("Down","Down");

    player_.windowCollisions();
    auto moved = player_.GetPos();

    sf::Vector2<float> newPos = {715.f,420.f};

    CHECK(moved==newPos);
}

//--------------------------------------------------------------------------------------------------------------
//CENTIPEDE MOVEMENT TESTS
//--------------------------------------------------------------------------------------------------------------

TEST_CASE("Check if monster moves Right")
{
    std::vector<Centipede> centipede_;
    Centipede tempCentiObj(360.f,0.f);
    centipede_.push_back(tempCentiObj);

    auto x1 = centipede_.at(0).getCentiPos();

    centipede_.at(0).refreshMovement();
    centipede_.at(0).centiWindowCollisions();

    auto newPos1 = centipede_.at(0).getCentiPos();

    CHECK(x1.x < newPos1.x);
    CHECK(x1.y == newPos1.y);
}

//--------------------------------------------------------------------------------------------------------------
//CENTIPEDE WINDOW COLLISION TESTS
//--------------------------------------------------------------------------------------------------------------

TEST_CASE("Check if monster hits Right boundary, moves down and then starts moving left")
{
    std::vector<Centipede> centipede_;
    Centipede tempCentiObj(997.f,0.f);
    centipede_.push_back(tempCentiObj);

    auto x1 = centipede_.at(0).getCentiPos();

    centipede_.at(0).refreshMovement();
    centipede_.at(0).centiWindowCollisions();

    auto newPos1 = centipede_.at(0).getCentiPos();

    centipede_.at(0).refreshMovement();
    auto newPos2 = centipede_.at(0).getCentiPos();

    CHECK(newPos1.x==1000);
    CHECK(newPos1.y == 30);
    CHECK(newPos2.x==997);
    CHECK(newPos2.y == 30);
}

TEST_CASE("Check if monster hits Left boundary, moves down and then starts moving right")
{
    std::vector<Centipede> centipede_;
    Centipede tempCentiObj(997.f,0.f);
    centipede_.push_back(tempCentiObj);

    centipede_.at(0).refreshMovement();
    centipede_.at(0).centiWindowCollisions();

    centipede_.at(0).setPos(3.f,60.f);
    auto x1 = centipede_.at(0).getCentiPos();

    centipede_.at(0).refreshMovement();
    centipede_.at(0).centiWindowCollisions();
    auto newPos1 = centipede_.at(0).getCentiPos();

    centipede_.at(0).refreshMovement();
    centipede_.at(0).centiWindowCollisions();
    auto newPos2 = centipede_.at(0).getCentiPos();

    CHECK(newPos1.x==0);
    CHECK(newPos1.y == 90);
    CHECK(newPos2.x==3);
    CHECK(newPos2.y == 90);
}

TEST_CASE("Check if centipede starts moving back up when it hits bottom boundary")
{
    //Construct Game TEST class
    GameTests gameTests_;

    //set positions
    gameTests_.modCentiPos(985.f,721.f);

    //get expected positions
    auto origCentiPos = gameTests_.accessCenti().at(0).getCentiPos();

    //call collision check function
    gameTests_.centiChangeDirCheck();

    //get new positions
    auto newCentiPos = gameTests_.accessCenti().at(0).getCentiPos();

    //TEST
    CHECK_FALSE(origCentiPos.y == newCentiPos.y); //check that Centi has changed vertical position
    CHECK(newCentiPos.x == origCentiPos.x+3.f); //check that Centi has moved in horizontal direction
    CHECK(newCentiPos.y == origCentiPos.y - 30.f); //check centi has moved up by one row
}

TEST_CASE("Check if centipede starts moving back down when it hits top boundary")
{
    //Construct Game TEST class
    GameTests gameTests_;

    //set positions
    gameTests_.modCentiPos(985.f,-10.f);

    //get expected positions
    auto origCentiPos = gameTests_.accessCenti().at(0).getCentiPos();

    //call collision check function
    gameTests_.centiChangeDirCheck();

    //get new positions
    auto newCentiPos = gameTests_.accessCenti().at(0).getCentiPos();

    //TEST
    CHECK_FALSE(origCentiPos.y == newCentiPos.y); //check that Centi has changed vertical position
    CHECK(newCentiPos.x == origCentiPos.x+3.f); //check that Centi has moved in horizontal direction
    CHECK(newCentiPos.y == origCentiPos.y -30.f); //check centi has moved down by one row
}

//--------------------------------------------------------------------------------------------------------------
//OCTOPUS MOVEMENT TESTS
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Check if Octopus Moves when initialised")
{
    Octopus octopus_;
    octopus_.setOctPos(600.f,400.f);
    auto OriginalPos = octopus_.GetOctPos();

    octopus_.MoveOctopus();

    auto newPos = octopus_.GetOctPos();

    CHECK_FALSE(OriginalPos==newPos);
}

//--------------------------------------------------------------------------------------------------------------
//OCTOPUS WINDOW COLLISION TESTS
//--------------------------------------------------------------------------------------------------------------

TEST_CASE("Check if Octopus Moves when hits bottom window bounds")
{
    Octopus octopus_;
    octopus_.setOctPos(700.f,700.f);
    auto OriginalPos = octopus_.GetOctPos();

    octopus_.MoveOctopus();

    auto newPos = octopus_.GetOctPos();

    CHECK(OriginalPos.y>=newPos.y);
 }
//--------------------------------------------------------------------------------------------------------------------
// LIGHTNING BLAST MOVEMENT TESTS
//--------------------------------------------------------------------------------------------------------------------
TEST_CASE("Check if Lightning blast is generated at certain position")
{
    std::vector<Blast> BlastArsenal;
    Blast tempBlastObject(500.f ,500.f);
    BlastArsenal.push_back(tempBlastObject);

    auto yPos = BlastArsenal.at(0).GetPos().y;
    CHECK(yPos == 500.f);
}

TEST_CASE("Check if Lightning blast moves up by speed of 10.f after generated")
{
    std::vector<Blast> BlastArsenal;
    Blast tempBlastObject(500.f ,500.f);
    BlastArsenal.push_back(tempBlastObject);

    auto yPos = BlastArsenal.at(0).GetPos().y;
    BlastArsenal.at(0).refreshMovement();
    auto newYPos = BlastArsenal.at(0).GetPos().y;
    CHECK_FALSE(yPos == newYPos);
    CHECK(newYPos == 490.f);
}

TEST_CASE("Check that Lightning blast does not change horizontal position")
{
    std::vector<Blast> BlastArsenal;
    Blast tempBlastObject(500.f ,500.f);
    BlastArsenal.push_back(tempBlastObject);

    auto xPos = BlastArsenal.at(0).GetPos().x;
    BlastArsenal.at(0).refreshMovement();
    auto newXPos = BlastArsenal.at(0).GetPos().x;
    CHECK(xPos == newXPos);
}
//--------------------------------------------------------------------------------------------------------------------
// LIGHTNING BLAST WINDOW COLLISIONS
//--------------------------------------------------------------------------------------------------------------------

TEST_CASE("Check if lightning blast deleted when reaching top bound of window")
{
    //Construct Game TEST class
    GameTests gameTests_;

    auto origVectSize = gameTests_.accessBlast().size();
    gameTests_.newBlast(10.f,-20.f);

    auto newVectSize1 = gameTests_.accessBlast().size();
    //set positions
    gameTests_.accessBlast().at(0).blastCollisions();
    gameTests_.accessBlast().at(0).refreshMovement();

    //call collision check function
    gameTests_.blastDeleteCheck();
    auto newVectSize2 = gameTests_.accessBlast().size();

    //TEST
    CHECK(newVectSize1 == origVectSize + 1); // check new jelly was initially created
    CHECK(gameTests_.accessBlast().empty() == true); //check that vector now empty
    CHECK(newVectSize2 == origVectSize); //check that size of vector has reduced to start size
}

//--------------------------------------------------------------------------------------------------------------------
// ANCHOR MOVEMENT TESTS
//--------------------------------------------------------------------------------------------------------------------
TEST_CASE("Check if anchor is generated at certain position")
{
    std::vector<Anchor> AnchorVector;
    Anchor tempAnchorObject;
    AnchorVector.push_back(tempAnchorObject);

    auto yPos = AnchorVector.at(0).getPos().y;
    CHECK(yPos == -1400.f);
}

TEST_CASE("Check if anchor moves down vertically at speed of 3.f from start position")
{
    std::vector<Anchor> AnchorVector;
    Anchor tempAnchorObject;
    AnchorVector.push_back(tempAnchorObject);

    auto yPos = AnchorVector.at(0).getPos().y;
    AnchorVector.at(0).refreshMovement();
    auto newYPos = AnchorVector.at(0).getPos().y;
    CHECK_FALSE(newYPos == yPos);
    CHECK(newYPos == yPos + 3.f);
}

TEST_CASE("Check that anchor does not change horizontal position when it moves")
{
    std::vector<Anchor> AnchorVector;
    Anchor tempAnchorObject;
    AnchorVector.push_back(tempAnchorObject);

    auto xPos = AnchorVector.at(0).getPos().x;
    AnchorVector.at(0).refreshMovement();
    auto newXPos = AnchorVector.at(0).getPos().x;
    CHECK_FALSE(newXPos == xPos + 3.f);
    CHECK(newXPos == xPos);

}

//--------------------------------------------------------------------------------------------------------------------
// ANCHOR WINDOW COLLISIONS
//--------------------------------------------------------------------------------------------------------------------
TEST_CASE("Check that anchor resets vertical position at top when it hits bottom of window")
{
    std::vector<Anchor> AnchorVector;
    Anchor tempAnchorObject;
    AnchorVector.push_back(tempAnchorObject);

    AnchorVector.at(0).setPos(100.f,729.f);
    auto yPos = AnchorVector.at(0).getPos().y;
    AnchorVector.at(0).refreshMovement();

    AnchorVector.at(0).WindowCollisions();
    auto newYPos = AnchorVector.at(0).getPos().y;

    CHECK_FALSE(newYPos == yPos + 3.f);
    CHECK_FALSE(newYPos == yPos);
    CHECK(newYPos == -1400.f);
}

//--------------------------------------------------------------------------------------------------------------
// PLAYER AND CENTIPEDE COLLISION TESTS
//--------------------------------------------------------------------------------------------------------------

TEST_CASE("Check if player moves to an origin position when colliding with Centipede")
{
    //Construct Game TEST class
    GameTests gameTests_;

    //set positions
    gameTests_.modPlayerPos(400.f,600.f);
    gameTests_.modCentiPos(390.f,600.f);

    //get expected positions
    auto origPlayerPos = gameTests_.accessPlayer().GetPos();
    auto origCentiPos = gameTests_.accessCenti().at(0).getCentiPos();

    //call collision check function
    gameTests_.monsterVictoryCheck();

    //get new positions
    auto newPlayerPos = gameTests_.accessPlayer().GetPos();
    auto newCentiPos = gameTests_.accessCenti().at(0).getCentiPos();

    //TEST
    CHECK_FALSE(origPlayerPos.x == newPlayerPos.x); //player should be moved to new position
    CHECK(origCentiPos.x == newCentiPos.x); //centipede will still be at same position
}

TEST_CASE("Check that extra lives decrease when player collides with Centipede")
{
    //Construct Game TEST class
    GameTests gameTests_;

    //set positions
    gameTests_.modPlayerPos(400.f,600.f);
    gameTests_.modCentiPos(390.f,600.f);

    //original number of extra lives
    auto origLives = gameTests_.accessLives();

    //call collision check function
    gameTests_.monsterVictoryCheck();

    //new number of extra lives
    auto newLives = gameTests_.accessLives();

    //TEST
    CHECK_FALSE(origLives == newLives); //extra lives should decrement on collision
    CHECK(newLives == origLives - 1); //extra lives should decrement by one on collision
}

//--------------------------------------------------------------------------------------------------------------
// PLAYER AND OCTOPUS COLLISION TESTS
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Check if player moves to an origin position when colliding with Octopus")
{
    //Construct Game TEST class
    GameTests gameTests_;

    //set positions
    gameTests_.modPlayerPos(400.f,600.f);
    gameTests_.modOctPos(390.f,600.f);

    //get expected positions
    auto origPlayerPos = gameTests_.accessPlayer().GetPos();
    auto origOctPos = gameTests_.accessOct().at(0).GetOctPos();

    //call collision check function
    gameTests_.monsterVictoryCheck();

    //get new positions
    auto newPlayerPos = gameTests_.accessPlayer().GetPos();
    auto newOctPos = gameTests_.accessOct().at(0).GetOctPos();

    //TEST
    CHECK_FALSE(origPlayerPos.x == newPlayerPos.x); //player should be moved to new position
    CHECK(origOctPos.x == newOctPos.x); //Octopus will still be at same position
}

TEST_CASE("Check that extra lives decrease when player collides with Octopus")
{
    //Construct Game TEST class
    GameTests gameTests_;

    //set positions
    gameTests_.modPlayerPos(400.f,600.f);
    gameTests_.modOctPos(390.f,600.f);

    //original number of extra lives
    auto origLives = gameTests_.accessLives();

    //call collision check function
    gameTests_.monsterVictoryCheck();

    //new number of extra lives
    auto newLives = gameTests_.accessLives();

    //TEST
    CHECK_FALSE(origLives == newLives); //extra lives should decrement on collision
    CHECK(newLives == origLives - 1); //extra lives should decrement by one on collision
}
//--------------------------------------------------------------------------------------------------------------
// CENTIPEDE AND JELLYFISH COLLISION TESTS
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Check if Centipede moves down one row when hitting a jellyfish")
{
    //Construct Game TEST class
    GameTests gameTests_;

    //set positions
    gameTests_.modCentiPos(390.f,600.f);
    gameTests_.modJellyPos(400.f,600.f);

    //get expected positions
    auto origCentiPos = gameTests_.accessCenti().at(0).getCentiPos();
    auto origJellyPos = gameTests_.accessJelly().at(0).getJellyPos();

    //call collision check function
    gameTests_.jellyCollisionCheck();
    gameTests_.accessCenti().at(0).refreshMovement();
    gameTests_.jellyCollisionCheck();

    //get new positions
    auto newCentiPos = gameTests_.accessCenti().at(0).getCentiPos();
    auto newJellyPos = gameTests_.accessJelly().at(0).getJellyPos();

    //TEST
    CHECK_FALSE(origCentiPos.y == newCentiPos.y); //check that Centi has changed vertical position
    CHECK(origCentiPos.x == newCentiPos.x); //check that Centi has not yet moved in horizontal direction
    CHECK(newCentiPos.y == origCentiPos.y + 30.f); //check centi has moved down by one row
    CHECK(origJellyPos.y == newJellyPos.y); //check Jellyfish has not moved
}

//--------------------------------------------------------------------------------------------------------------
// OCTOPUS AND JELLYFISH COLLISION TESTS (TEST OF A FUNCTION INVOLVING RANDOMNESS)
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Check that Octopus eats a jellyfish at random")
 {
    //NOTE: due to the fact that the jellyfish has a 1 in 10 chance of being eaten, we use a for loop to implement
    //      the check multiple times over to ensure that such an occurence will happen.

    //Construct Game TEST class
    GameTests gameTests_;

    auto origVectSize = gameTests_.accessJelly().size();

    //set positions
    gameTests_.modOctPos(390.f,600.f);
    gameTests_.modJellyPos(400.f,600.f);

    //call collision check function
    for(auto count = 0; count < 50; count++)
    {
        gameTests_.jellyCollisionCheck();
    }

    auto newVectSize = gameTests_.accessJelly().size();

    //TEST
    CHECK_FALSE(newVectSize == origVectSize);
}

//--------------------------------------------------------------------------------------------------------------
// LIGHTNING BLAST AND JELLYFISH COLLISION TESTS
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Check if hit count and score increases when blast hits jellyfish")
{
    //Construct Game TEST class
    GameTests gameTests_;

    auto origScore = gameTests_.updateScore();
    gameTests_.newBlast(400.f,600.f);
    gameTests_.modJellyPos(400.f,600.f);

    auto oldHitCount = gameTests_.accessHitCount().at(0);
    auto origBlastPos = gameTests_.accessBlast().at(0).GetPos();

    //call collision check function
    gameTests_.collisionsCheck();

    auto newBlastPos = gameTests_.accessBlast().at(0).GetPos();
    auto newHitCount = gameTests_.accessHitCount().at(0);
    auto newScore = gameTests_.updateScore();

    //TEST
    CHECK(newHitCount == oldHitCount + 1); //hit count should be increased by one
    CHECK(newScore == origScore + 5); //score increases by 5 with one hit of the jellyfish
}

TEST_CASE("Check if lightning blast deleted when it hits jellyfish")
{
    //Construct Game TEST class
    GameTests gameTests_;

    auto origVectSize = gameTests_.accessBlast().size();
    gameTests_.newBlast(400.f,600.f);
    gameTests_.modJellyPos(400.f,600.f);

    //call collision check function
    gameTests_.collisionsCheck();

    auto newVectSize = gameTests_.accessBlast().size();

    //TEST
    CHECK_FALSE(newVectSize == origVectSize); //blast is deleted, decrementing size of vector
}

TEST_CASE("Check Jellyfish not deleted when Hit count < 4")
{
    //Construct Game TEST class
    GameTests gameTests_;

    auto origVectSize = gameTests_.accessJelly().size();
    gameTests_.modJellyPos(400.f,600.f);

    //hit jellyfish 3 times with checks
    gameTests_.newBlast(400.f,600.f);
    gameTests_.collisionsCheck();
    gameTests_.newBlast(400.f,600.f);
    gameTests_.collisionsCheck();
    gameTests_.newBlast(400.f,600.f);
    gameTests_.collisionsCheck();

    auto newVectSize = gameTests_.accessJelly().size();

    //TEST
    CHECK(newVectSize == origVectSize); //jelly vector should remain the same size
}

TEST_CASE("Check Jellyfish deleted when Hit count = 4 and score increased by 15")
{
    //Construct Game TEST class
    GameTests gameTests_;

    auto origScore = gameTests_.updateScore();
    auto origVectSize = gameTests_.accessJelly().size();
    gameTests_.modJellyPos(400.f,600.f);

    //hit jellyfish 4 times with checks
    gameTests_.newBlast(400.f,600.f);
    gameTests_.collisionsCheck();
    gameTests_.newBlast(400.f,600.f);
    gameTests_.collisionsCheck();
    gameTests_.newBlast(400.f,600.f);
    gameTests_.collisionsCheck();
    gameTests_.newBlast(400.f,600.f);
    gameTests_.collisionsCheck();

    auto newVectSize = gameTests_.accessJelly().size();
    auto newScore = gameTests_.updateScore();

    //TEST
    CHECK_FALSE(newVectSize == origVectSize); //jelly vector should have been reduced in size by one
    CHECK(newVectSize == origVectSize -1);
    CHECK(newScore == origScore + 30); //score increases by 30 after 4 hits of jellyfish

}
//--------------------------------------------------------------------------------------------------------------
// LIGHTNING BLAST AND CENTIPEDE COLLISION TESTS
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Check Centipede segment deleted and score increased by 30 when hit once with blast")
{
    //Construct Game TEST class
    GameTests gameTests_;

    auto origScore = gameTests_.updateScore();
    auto origVectSize = gameTests_.accessCenti().size();
    gameTests_.modCentiPos(400.f,600.f);

    //hit centipede segment once with blast
    gameTests_.newBlast(400.f,600.f);
    gameTests_.collisionsCheck();

    auto newScore = gameTests_.updateScore();
    auto newVectSize = gameTests_.accessCenti().size();

    //TEST
    CHECK_FALSE(newVectSize == origVectSize); //Centipede vector should have been reduced in size by one
    CHECK(newVectSize == origVectSize -1);
    CHECK(newScore == origScore + 30); //score increases by 30 after 1 hit of jellyfish
}

TEST_CASE("Check if Centipede segment following destroyed segment becomes a head")
{
    //Construct Game TEST class
    GameTests gameTests_;

    auto origVectSize = gameTests_.accessIsHead().size();
    bool origIsHead = gameTests_.accessIsHead().at(1);

    gameTests_.modCentiPos(400.f,600.f);

    //hit centipede segment once with blast
    gameTests_.newBlast(400.f,600.f);
    gameTests_.collisionsCheck();

    auto newVectSize = gameTests_.accessIsHead().size();
    bool newIsHead = gameTests_.accessIsHead().at(0);

    //TEST
    CHECK_FALSE(newVectSize == origVectSize); //element of isHead vector should be deleted
    CHECK(newVectSize == origVectSize -1); //isHead vector should have been reduced in size by one
    CHECK(origIsHead == false); //following element originally not a head
    CHECK(newIsHead == true); //now moved up in position and is now a head
}

//--------------------------------------------------------------------------------------------------------------
// LIGHTNING BLAST AND OCTOPUS COLLISION TESTS
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Check Octopus position reset and score increased by 15 when hit once with blast")
{
    //Construct Game TEST class
    GameTests gameTests_;

    auto startOctPos = gameTests_.accessOct().at(0).GetOctPos();
    auto origScore = gameTests_.updateScore();
    gameTests_.modOctPos(400.f,600.f);
    auto newOctPos1 = gameTests_.accessOct().at(0).GetOctPos();

    //hit Octopus once with blast
    gameTests_.newBlast(400.f,600.f);
    gameTests_.collisionsCheck();

    auto newScore = gameTests_.updateScore();
    auto newOctPos2 = gameTests_.accessOct().at(0).GetOctPos();

    //TEST
    CHECK(newScore == origScore + 15); //score increases by 25 after 1 hit of jellyfish
    CHECK_FALSE(newOctPos2 == newOctPos1);
    CHECK(newOctPos2 == startOctPos);
}

//--------------------------------------------------------------------------------------------------------------
// ANCHOR RANDOMLY SPAWNS NEW JELLYFISH TESTS (TEST OF A FUNCTION INVOLVING RANDOMNESS)
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Check that Anchor spawns new jellyfish at random in player movement area")
 {
    //NOTE: due to the fact that the jellyfish has a 1 in 20 chance of being spawned, we use a for loop to implement
    //      the check multiple times over to ensure that such an occurence will happen.

    //Construct Game TEST class
    GameTests gameTests_;

    auto origVectSize = gameTests_.accessJelly().size();

    //set positions
    gameTests_.modAnchorPos(390.f,600.f);

    //call collision check function
    for(auto count = 0; count < 50; count++)
    {
        gameTests_.anchorPosCheck();
    }

    auto newVectSize = gameTests_.accessJelly().size();

    //TEST
    CHECK_FALSE(newVectSize == origVectSize);
}

//--------------------------------------------------------------------------------------------------------------
// LIGHTNING BLAST AND DDT BOMB COLLISION TESTS
//--------------------------------------------------------------------------------------------------------------

TEST_CASE("Check DDT Bomb explosion status before and after hit and score increased by 10 when hit once with blast")
{
    //Construct Game TEST class
    GameTests gameTests_;

    gameTests_.modBombPos(400.f,600.f,0);
    auto origScore = gameTests_.updateScore();
    auto newBombPos1 = gameTests_.accessBombs().at(0).getBombPos();
    bool startExplosion = gameTests_.accessExplosion().at(0);

    //hit DDT Bomb with one blast
    gameTests_.newBlast(400.f,600.f);

    gameTests_.collisionsCheck();

    auto newScore = gameTests_.updateScore();

    auto newExplosion = gameTests_.accessExplosion().at(0);

    //TEST
    CHECK(newScore == origScore + 10); //score increases by 1- after 1 hit of The DDT Bomb
    CHECK(startExplosion == false);
    CHECK(newExplosion == true);
}

TEST_CASE("Check number of DDT Bombs in game never reaches above 4 and the explosion status is assigned to each Bomb")
{
    //Construct Game TEST class
    GameTests gameTests_;
    bool startExplosion = gameTests_.accessExplosion().size();
    gameTests_.modBombPos(400.f,600.f,0);
    auto origVectSize = gameTests_.accessBombs().size();
    //Call DDT Bomb constructor function more than 4 times
    gameTests_.modBombPos(160.f,600.f,1);
    gameTests_.modBombPos(400.f,100.f,2);
    gameTests_.modBombPos(400.f,300.f,3);
    gameTests_.modBombPos(200.f,600.f,4);

    auto newVectSize = gameTests_.accessBombs().size();
    auto newExplosionSize = gameTests_.accessExplosion().size();

    //TEST
    CHECK_FALSE(origVectSize == newVectSize); //score increases by 1- after 1 hit of The DDT Bomb
    CHECK(newVectSize == 4);
    CHECK(newExplosionSize == startExplosion + 4);
}

//--------------------------------------------------------------------------------------------------------------
// ENEMY AND DDT BOMB COLLISION TESTS
//--------------------------------------------------------------------------------------------------------------

TEST_CASE("Check Jellyfish is deleted after DDT Bomb explosion and score increased by 10 + 3*15 when hit once with DDT Bomb")
{

    //Construct Game TEST class

    GameTests gameTests_;

    gameTests_.modBombPos(400.f,600.f,0);
    auto origScore = gameTests_.updateScore();
    auto newBombPos1 = gameTests_.accessBombs().at(0).getBombPos();
    bool startExplosion = gameTests_.accessExplosion().at(0);

    //hit DDT Bomb with one blast
    gameTests_.newBlast(400.f,600.f);
    gameTests_.collisionsCheck();
    auto newScore = gameTests_.updateScore();
    bool newExplosion = gameTests_.accessExplosion().at(0);

    //hit Jelly with DDT Bomb explosion
    gameTests_.modJellyPos(380.f,580.f);
    auto origVectSize = gameTests_.accessJelly().size();
    gameTests_.jellyCollisionCheck();

    auto newScore1 = gameTests_.updateScore();
    auto newVectSize = gameTests_.accessJelly().size();

    //TEST
    CHECK(newScore1 == origScore + 10 + 3*15); //score increases after after destroying jellyfish
    CHECK(newVectSize == origVectSize-1);
    CHECK(newExplosion == true);
}

TEST_CASE("Check Octopus is deleted after DDT Bomb explosion and score increased by 10 + 3*15 when hit once with DDT Bomb")
{

    //Construct Game TEST class
    GameTests gameTests_;

    gameTests_.modBombPos(400.f,600.f,0);
    auto origScore = gameTests_.updateScore();
    bool startExplosion = gameTests_.accessExplosion().at(0);

    //hit DDT Bomb with one blast
    gameTests_.newBlast(400.f,600.f);
    gameTests_.collisionsCheck();

    //hit Centipede segment with DDT Bomb explosion
    gameTests_.modOctPos(400.f,600.f);
    auto origVectSize = gameTests_.accessOct().size();
    gameTests_.BombCollisions();

    auto newScore1 = gameTests_.updateScore();
    auto newVectSize = gameTests_.accessOct().size();
    bool newExplosion = gameTests_.accessExplosion().at(0);

    //TEST
    CHECK(newScore1 == origScore + 10 + 3*15); //score increases after 1 hit of Octopus
    CHECK(newVectSize == origVectSize-1);
    CHECK(newExplosion == true);
}
