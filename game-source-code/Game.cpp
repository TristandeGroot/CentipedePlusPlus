#include "Game.h"

//--------------------------------------------------------------------------------------------------------------------------------
// Constructor & Destructor
//--------------------------------------------------------------------------------------------------------------------------------
Game::Game()
{
    setVariables();
    setScoreDisplay();
    setWindow();
    setSprites();
    setMusic();
    setCentipede();
    setJellyGrid();
    setOctopus();
    Clock();
    setAnchor();
    gridBlocks.clear();
    while(running())
    {
        refresh();  //update the game
        manifest(); //render the frame
    }
    play_.stop();
    play1_.stop();
}

Game::~Game()
{
    delete window;
}

//--------------------------------------------------------------------------------------------------------------------------------
// SET UP FUNCTIONS
//--------------------------------------------------------------------------------------------------------------------------------
void Game::setVariables()
{
    GameOver = false;
    bool win = false;
    myScore = 0;
    lives = 3;
    firstOct = true;
}

void Game::setWindow()
{
    windowSpecs = sf::VideoMode(1000,720); //set width and height
    window = new sf::RenderWindow(windowSpecs, "Centipede++", sf::Style::Close | sf::Style::Titlebar);
    window->setFramerateLimit(60);
    backgroundSprite.setTexture(resources.backgroundTexture);

    text.setPosition(8.f,685.f);
    text1.setPosition(132.f,685.f);

    // Draw it
    window->draw(backgroundSprite);
    window->draw(text);
    window->draw(text1);
    window->display();
}

void Game::setSprites()
{
    centiSpriteVector = resources.centiSpriteVector();
    jellyText = resources.jellyTexture1;
    OctText = resources.octopusTexture;
    anchorText = resources.anchorTexture;
}

void Game::setMusic()
{
    if(!buffer.loadFromFile("resources/ball.wav"))
    {
        std::cout<< "Error"<<std::endl;
    }
    if(!buffer1.loadFromFile("resources/Blast.wav"))
    {
        std::cout<< "Error"<<std::endl;
    }
    play_.setBuffer(buffer);
    play1_.setBuffer(buffer1);
}

int Game::setRand()
{
    int num = rand()%50;
    return num;
}

time_t Game::Clock()
{
  time_t now;
  double seconds;

  int currentTime = (time(&now))%50;  /* get current time; same as: now = time(NULL)  */

  return currentTime;
}

void Game::setCentipede()
{
    auto segmentPosition = 360.f;
    for (int count=0; count<11; count++)
    {
        segmentPosition = segmentPosition - 30.f;
        Centipede tempCentiObj(segmentPosition,0.f);
        centiVector.push_back(tempCentiObj);
    }

    isHead.push_back(true);

    for (int count=1; count<11; count++)
    {
        isHead.push_back(false);
    }
}

void Game::setBombs()
{

   if(BombVector.size()<4 )
    {
       auto BombPositionX = rand()%900;
       auto BombPositionY = rand()%500;

     if(BombVector.size()>1)
     {
        for(int i=0;i<BombVector.size();i++)
       {
           int LeftBound = BombVector[i].getBombBounds().left;
           int RightBound = BombVector[i].getBombBounds().left + BombVector[i].getBombBounds().width;
           int UpBound = BombVector[i].getBombBounds().top;
           int LowBound = BombVector[i].getBombBounds().top + BombVector[i].getBombBounds().height;

           if((LeftBound < BombPositionX && RightBound > BombPositionX) && (UpBound < BombPositionY && LowBound>BombPositionY))
           {
               break;
           }

           else
           {
                Bomb tempBombObj(BombPositionX,BombPositionY);
                BombVector.push_back(tempBombObj);

                BombTexture = resources.BombTexture;
                BombCloudText = resources.BombCloudText;

                sf::Sprite BombSprite1;
                BombSprite1.setTexture(BombTexture);
                BombSpriteVector.push_back(BombSprite1);
                Exploded.push_back(false);
                Scaled.push_back(false);
                ExplosionTime.push_back(0);
            }
       }
     }
            else
            {
                Bomb tempBombObj(BombPositionX,BombPositionY);
                BombVector.push_back(tempBombObj);

                BombTexture = resources.BombTexture;
                BombCloudText = resources.BombCloudText;

                sf::Sprite BombSprite1;
                BombSprite1.setTexture(BombTexture);
                BombSpriteVector.push_back(BombSprite1);
                Exploded.push_back(false);
                Scaled.push_back(false);
                ExplosionTime.push_back(0);
            }
    }
}

void Game::setJellyGrid()
{
    //set up grid for the Jellyfish to spawn on
    auto blockRowPos = 0.f;
    for (int count2=0; count2<24;count2++)
    {
        auto blockColPos = -30.f;
        std::vector<Grid> rowBlocks;
        for (int count=0; count<33; count++)
        {
            blockColPos = blockColPos + 30.f;
            Grid tempObj(blockColPos,blockRowPos);
            rowBlocks.push_back(tempObj);
        }
        gridBlocks.push_back(rowBlocks);
        blockRowPos = blockRowPos + 30.f;
    }

    //Spawn random Jellyfish
    for (auto count = 1; count<(gridBlocks.size()-5);count++)
    {
        for (auto count2 = 0; count2<gridBlocks[count].size(); count2++)
        {
            auto randNum= rand()%10; //10% chance of being a jellyfish
            if(randNum == 1 )
            {
                Jelly tempJelly(gridBlocks[count][count2].getBlockPos().x,gridBlocks[count][count2].getBlockPos().y);
                JellyVector.push_back(tempJelly);
                hitCount.push_back(0);
                sf::Sprite tempSpriteObj;
                tempSpriteObj.setTexture(jellyText);
                tempSpriteObj.setScale(0.05f,0.05f);
                tempSpriteObj.setPosition(gridBlocks[count][count2].getBlockPos().x,gridBlocks[count][count2].getBlockPos().y);
                jellySpriteVector.push_back(tempSpriteObj);
            }
        }
    }
}

void Game::setOctopus()
{

    Octopus octopus;
    OctopusVector.push_back(octopus);

    sf::Sprite tempSpriteObj;
    tempSpriteObj.setTexture(OctText);
    tempSpriteObj.setScale(0.25f,0.25f);
    OctSpriteVector.push_back(tempSpriteObj);
}

void Game::newJelly(float xPos, float yPos)
{
    //new Jelly in JellyFish class
    Jelly tempJelly(xPos,yPos);
    JellyVector.push_back(tempJelly);

    sf::Sprite tempSpriteObj;
    tempSpriteObj.setTexture(jellyText);
    tempSpriteObj.setScale(0.05f,0.05f);
    tempSpriteObj.setPosition(xPos,yPos);
    jellySpriteVector.push_back(tempSpriteObj);
}

void Game::setAnchor()
{
    Anchor anchor;
    AnchorVector.push_back(anchor);

    sf::Sprite tempSpriteObj;
    tempSpriteObj.setTexture(anchorText);
    tempSpriteObj.setScale(0.1f,0.1f);
    AnchorSpriteVector.push_back(tempSpriteObj);
}

void Game::newBlast(float x, float y)
{
    Blast tempBlastObject(x,y);
    BlastArsenal.push_back(tempBlastObject);
}

//--------------------------------------------------------------------------------------------------------------------------------
// Game Run & Event Functions
//--------------------------------------------------------------------------------------------------------------------------------
const bool Game::running() const
{
    return window->isOpen();
}

void Game::checkEvents()
{
    while(window->pollEvent(windowEvent))
    {
        //events to close: either click X or the key Esc
        switch (windowEvent.type)
        {
        case sf::Event::Closed:
           win = false;
           window->close();
           break;
        case sf::Event::KeyPressed:
           if(windowEvent.key.code == sf::Keyboard::Escape)
           {
              win = false;
              window->close();
              break;
           }
           if(windowEvent.key.code == sf::Keyboard::Space) //Lightning blast is generated
           {
                newBlast(player.GetPos().x + 100.f ,player.GetPos().y);
                play_.play();
           }
        }
    }
}

void Game::setScoreDisplay()
{
    if(!font1.loadFromFile("resources/Ocean Summer.ttf"))
    {
        std::cout << "Error: Could not load texture file" << "\n";
    }

    text.setFont(font1);
    text1.setFont(font1);
    text.setString("SCORE: " + std::to_string(myScore));
    text1.setString("LIVES: " + std::to_string(lives));
    text.setCharacterSize(30);
    text1.setCharacterSize(30);
    text.setFillColor(sf::Color::Black);
    text1.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);
    text1.setStyle(sf::Text::Bold);
}

//--------------------------------------------------------------------------------------------------------------------------------
// Calculations
//--------------------------------------------------------------------------------------------------------------------------------
void Game::monsterVictoryCheck()  //if monster (Octopus or centipede train) hits player subtract life
{
    for (auto count = 0; count< centiVector.size();count++)
    {
        if (centiVector[count].getCentiBounds().intersects(player.getPlayerBounds()) && lives == 0)
        {
            win = false;
            window->close();
        }
        else if (centiVector[count].getCentiBounds().intersects(player.getPlayerBounds()))
        {
            lives = lives -1;
            player.setPos(999.f,719.f);
        }

    }
    if (OctopusVector[0].getOctopusBounds().intersects(player.getPlayerBounds()) && lives == 0)
    {
        win = false;
        window->close();
    }
    else if (OctopusVector[0].getOctopusBounds().intersects(player.getPlayerBounds()))
    {
        lives = lives -1;
        player.setPos(999.f,719.f);
    }

        if (AnchorSpriteVector[0].getGlobalBounds().intersects(player.getPlayerBounds()) && lives == 0)
    {
        win = false;
        window->close();
    }
    else if (AnchorSpriteVector[0].getGlobalBounds().intersects(player.getPlayerBounds()))
    {
        lives = lives -1;
        player.setPos(999.f,719.f);
    }

}

void Game::centiChangeDirCheck()  //if monster hits bottom starts coming up and vice versa
{
    for (auto count = 0; count< centiVector.size();count++)
    {
        if (centiVector[count].getCentiPos().y >= 690.f || centiVector[count].getCentiPos().y < 0.f)
        {
            centiVector[count].setPos(centiVector[count].getCentiPos().x +3.f ,centiVector[count].getCentiPos().y -centiVector[count].getVertSpeed());
            centiVector[count].setCentiDirection();
            centiVector[count].setCentiVertDir();
        }
    }
}

void Game::blastDeleteCheck() //delete blast object when out of bounds
{
    for (auto count=0;count<BlastArsenal.size();count++)
    {
        if(BlastArsenal[count].blastCollisions() == true)
        {
            BlastArsenal.erase(begin(BlastArsenal) + count);
        }
    }
}

void Game::collisionsCheck() //When lightning blast collides when other objects
{
    for (auto count=0;count<BlastArsenal.size();count++)
    {
        //Collision with centipede
        for(auto count2=0;count2<centiVector.size();count2++)
        {
            if(BlastArsenal[count].getBlastBounds().intersects(centiVector[count2].getCentiBounds()))
            {
                //delete lightning blast
                BlastArsenal.erase(begin(BlastArsenal) + count);

                //spawn jellyfish at hit segment position
                newJelly(centiVector[count2].getCentiPos().x,centiVector[count2].getCentiPos().y);

                //delete segment and set next body segment to a head
                centiVector.erase(begin(centiVector)+count2);
                isHead[count2+1]=true;
                isHead.erase(begin(isHead)+count2);

                myScore = myScore + 25;
            }
        }
        //Collision with Jellyfish
        for(auto count1=0;count1  <JellyVector.size();count1++)
        {
            if(BlastArsenal[count].getBlastBounds().intersects(JellyVector[count1].getJellyBounds()))
            {
                //delete lightning blast
                BlastArsenal[count].setPos(3.f, -10.f);

                //increment hit count on jellyfish and check if destroyed
                if(hitCount[count1]==3)
                {
                    JellyVector.erase(begin(JellyVector) + count1);
                    jellySpriteVector.erase(begin(jellySpriteVector)+count1);
                    myScore = myScore + 15;
                    play1_.play();
                }
                else
                {
                    hitCount[count1] = hitCount[count1]+1;
                    myScore = myScore + 5;
                }
            }
        }
        //Collision with DDT Bomb
        for(auto count3=0;count3<BombVector.size();count3++)
        {
            if(BlastArsenal[count].getBlastBounds().intersects(BombVector[count3].getBombBounds()))
            {
                if(Exploded[count3]==false)
                {
                BlastArsenal[count].setPos(3.f, -10.f); //set position off screen will automatically delete object
                ExplosionTime[count3] = Clock();
                Exploded[count3]=true;
                myScore = myScore + 10;
                }
            }
        }
        //Collision with Octopus
        for(auto count4=0;count4<OctopusVector.size();count4++)
        {
            if(BlastArsenal[count].getBlastBounds().intersects(OctopusVector[count4].getOctopusBounds()))
            {
                //destroy lightning blast
                BlastArsenal[count].setPos(3.f, -10.f);

                //destroy oct
                OctopusVector.erase(begin(OctopusVector));
                OctSpriteVector.erase(begin(OctSpriteVector));
                setOctopus();
                myScore = myScore + 15;
                play1_.play();
            }
        }
        //Collisions with Anchor
        for(auto count5=0;count5<AnchorVector.size();count5++)
        {
            if(BlastArsenal[count].getBlastBounds().intersects(AnchorSpriteVector[count5].getGlobalBounds()))
            {
                //destroy lightning blast
                BlastArsenal[count].setPos(3.f, -10.f);

                //destroy Anchor
                AnchorVector.erase(begin(AnchorVector));
                AnchorSpriteVector.erase(begin(AnchorSpriteVector));
                setAnchor();
                myScore = myScore + 5;
                play1_.play();
            }
        }
    }
}

void Game::centiDestroyedCheck() //if player destroys centipede game ends
{
    if(centiVector.empty()==true)
    {
        win = true;
        window->close();
    }
}

void Game::jellyCollisionCheck() //collisions with jellyfish
{
    for (auto count = 0; count<JellyVector.size();count++)
    {
        //when centi collides with jellyfish
        for (auto count1 = 0; count1<centiVector.size(); count1++)
        {
            if (JellyVector[count].getJellyBounds().intersects(centiVector[count1].getCentiBounds()))
            {
                centiVector[count1].setPos(centiVector[count1].getCentiPos().x,centiVector[count1].getCentiPos().y + centiVector[count1].getVertSpeed());
                centiVector[count1].setCentiDirection();
            }
        }
        //if bomb explosion destroys jellyfish
        for (auto count3 =0; count3 < BombVector.size();count3++)
        {
            if (Exploded[count3]==true)
            {
                if (BombVector[count3].getBombBounds().intersects((JellyVector[count].getJellyBounds())))
                {
                    JellyVector.erase(begin(JellyVector) + count);
                    jellySpriteVector.erase(begin(jellySpriteVector)+count);
                    myScore = myScore + 25;
                    play1_.play();
                }
            }
        }
        //if octopus occasionally eats jellyfish
        int chanceEatJelly = rand()%10;
        if (OctopusVector[0].getOctopusBounds().intersects((JellyVector[count].getJellyBounds()))&& chanceEatJelly == 1)
        {
            JellyVector.erase(begin(JellyVector) + count);
            jellySpriteVector.erase(begin(jellySpriteVector)+count);
            myScore = myScore + 3*15;
            play1_.play();
        }
    }
}

void Game::BombCollisions() //collisions between DDT bomb explosion and Centipede and Octopus and Anchor
{
    for(auto count2=0;count2<centiVector.size();count2++)
    {
        for (auto count3 =0; count3 < BombVector.size();count3++)
        {
            if(Exploded[count3]==true)
            {
                if (BombVector[count3].getBombBounds().intersects((centiVector[count2].getCentiBounds())))
                {
                    centiVector.erase(begin(centiVector) + count2);
                    centiSpriteVector.erase(begin(centiSpriteVector)+count2);
                    myScore = myScore + 3*25;
                    play1_.play();
                }
            }
        }
    }

    for (auto count =0; count < BombVector.size();count++)
    {
        if(Exploded[count]==true)
        {
            if (BombVector[count].getBombBounds().intersects((OctopusVector[0].getOctopusBounds())))
            {
                //destroy Octopus
                OctopusVector.erase(begin(OctopusVector));
                OctSpriteVector.erase(begin(OctSpriteVector));
                setOctopus();
                myScore = myScore + 3*15;
                play1_.play();
            }

            if(BombVector[count].getBombBounds().intersects(AnchorSpriteVector[0].getGlobalBounds()))
            {
                //destroy Anchor
                AnchorVector.erase(begin(AnchorVector));
                AnchorSpriteVector.erase(begin(AnchorSpriteVector));
                setAnchor();
                myScore = myScore + 3*5;
                play1_.play();
            }
        }
    }
}

void Game::anchorPosCheck() //checks if Anchor within player movement area to spawn new Jellyfish at random
{
    auto chanceSpawnJelly = rand()%20;
    if( AnchorVector[0].getPos().y > 450.f && chanceSpawnJelly == 1 && AnchorVector[0].getPos().y < 650.f) //within player movement area
    {
        newJelly(AnchorVector[0].getPos().x,AnchorVector[0].getPos().y);
    }
}
//--------------------------------------------------------------------------------------------------------------------------------
// Accessors
//--------------------------------------------------------------------------------------------------------------------------------
int Game::updateScore()
{
    return myScore;
}

//--------------------------------------------------------------------------------------------------------------------------------
// Update & Refresh
//--------------------------------------------------------------------------------------------------------------------------------
void Game::refresh()
{
    //CHECKS
    checkEvents(); //checks if there are inputs
    monsterVictoryCheck(); //if centipede hits player, game ends
    centiChangeDirCheck(); //if centipede hits bottom, reset direction
    blastDeleteCheck(); //checks if blast has exited window
    collisionsCheck(); //collisions between blasts and segments
    centiDestroyedCheck(); //player wins when all centipede segemnts destroyed
    jellyCollisionCheck(); //if centi & jelly collide, move centi up/down and change horiz dir
    BombCollisions(); //collisions check between explosion and centipede
    anchorPosCheck(); //if anchor in player movement area, randomly spawn jellyfish


    //PLAYER UPDATE
    player.refresh(window);

    //CENTIPEDE UPDATE
    std::vector<Centipede>::iterator it;
    for(it = centiVector.begin();it != centiVector.end();++it)
    {
        it->refresh(window);
    }
    for (int count=0; count<centiVector.size(); count++)
    {
        centiSpriteVector[count].setPosition(centiVector[count].getCentiPos().x,centiVector[count].getCentiPos().y);
        if((centiVector[count].centiDirection()==false && isHead[count] == true) )
        {
            centiSpriteVector[count].setTexture(resources.centiTexture2);
        }
        if((centiVector[count].centiDirection()==true && isHead[count] == true) )
        {
            centiSpriteVector[count].setTexture(resources.centiTexture1);
        }
        if((isHead[count] ==false) )
        {
            centiSpriteVector[count].setTexture(resources.centiTexture3);
        }
    }

    //UPDATE SIZE OF CENTIPEDE SPRITE VECTOR
    while(centiVector.size() != centiSpriteVector.size())
    {
        centiSpriteVector.pop_back();
    }

    //UPDATE SIZE OF JELLYFISH SPRITE VECTOR
    while(JellyVector.size() != jellySpriteVector.size())
    {
        jellySpriteVector.pop_back();
    }

    //LIGHTNING BLASTS UPDATE
    if(BlastArsenal.empty()==false)
    {
        std::vector<Blast>::iterator it2;
        for(it2 = BlastArsenal.begin();it2 != BlastArsenal.end();++it2)
        {
           it2->refresh(window);
        }
    }

    //UPDATE OCTOPUS
    OctopusVector[0].refreshOctopus(window);
    OctSpriteVector[0].setPosition(OctopusVector[0].GetOctPos().x,OctopusVector[0].GetOctPos().y);

    //UPDATE ANCHOR
    AnchorVector[0].refresh(window);
    AnchorSpriteVector[0].setPosition(AnchorVector[0].getPos().x,AnchorVector[0].getPos().y);

    //Jellyfish update
    if(JellyVector.empty()==false)
    {
        std::vector<Jelly>::iterator it3;
        for(it3 = JellyVector.begin();it3 != JellyVector.end();++it3)
        {
           it3->refresh(window);
        }
    }

    //UPDATE DDTBOMB
    if(setRand() == Clock() && PrevClock != Clock())
    {
        setBombs();
        PrevClock = Clock();
    }

    for (int count=0; count<BombVector.size(); count++)
    {
        BombSpriteVector[count].setPosition(BombVector[count].getBombPos().x,BombVector[count].getBombPos().y);

        if(Exploded[count]==false)
        {
            BombSpriteVector[count].setTexture(BombTexture);
        }
        if(Exploded[count]==true)
        {
            if(Scaled[count]==false)
            {
                BombSpriteVector[count].setScale(4,4);
                BombVector[count].setBombScale(4,4);
                BombVector[count].setPos(BombVector[count].getBombPos().x-30.f, BombVector[count].getBombPos().y-30.f);
                BombSpriteVector[count].setPosition(BombVector[count].getBombPos().x, BombVector[count].getBombPos().y);

                Scaled[count]=true;
            }
            BombSpriteVector[count].setTexture(BombCloudText);
        }
        if(ExplosionTime[count]+2 == Clock()&& PrevClock2 != Clock()&&Exploded[count] == true)
        {
            PrevClock2 = Clock();
            BombVector.erase(begin(BombVector)+count);
            BombSpriteVector.erase(begin(BombSpriteVector)+count);
            ExplosionTime.erase(begin(ExplosionTime)+count);
            Exploded.erase(begin(Exploded)+count);
            Scaled.erase(begin(Scaled)+count);
        }
    }
}

void Game::manifest()
{
    window->clear();

    //DRAW WINDOW
    window->draw(backgroundSprite);

    //SCORE
    text.setString("SCORE: " + std::to_string(myScore));
    window->draw(text);
    text1.setString("LIVES: " + std::to_string(lives));
    window->draw(text1);

    //DRAW PLAYER
    player.manifest(window);

    //DRAW CENTIPEDE
    for (int count=0; count<centiSpriteVector.size(); count++)
    {
        window->draw(centiSpriteVector[count]);
    }

    //DRAW LIGHTNING BLASTS
    if(BlastArsenal.empty()==false)
    {
        std::vector<Blast>::iterator it2;
        for(it2 = BlastArsenal.begin();it2 != BlastArsenal.end();++it2)
        {
            it2->manifest(window);
        }
    }

    //DRAW OCTOPUS
    window->draw(OctSpriteVector[0]);

    //DRAW ANCHOR
    window->draw(AnchorSpriteVector[0]);

    //DRAW JELLYFISH
    if(JellyVector.empty()==false)
    {
        for (auto count=0; count < JellyVector.size(); count++)
        {
            window->draw(jellySpriteVector[count]);
        }
    }

    //DRAW DDTBOMB
    if(BombVector.empty()==false)
    {
        //std::cout<<" Manifest " << std::endl;
        for(int count = 0;count < BombSpriteVector.size();count++)
        {
           window->draw(BombSpriteVector[count]);
        }
    }

    window->display(); //display new frame
}
