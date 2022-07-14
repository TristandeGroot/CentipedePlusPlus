#include "Splashscreen.h"
//------------------------------------------------------------------------------------------------------------------------------------
// CONSTRUCTOR & DESTRUCTOR
//------------------------------------------------------------------------------------------------------------------------------------
Splashscreen::Splashscreen()
{
    setVariables();
    setWindow();
    setMusic();
    while(running())
    {
        refresh();  //update the splash
    }
    play_.stop();
}

Splashscreen::Splashscreen(int score, bool win, int highScore)
{
    myScore = score;
    topScore = highScore;
    if (win == true)
    {
        readInFonts();
        setWinSplash(score);
    }
    else
    {
        readInFonts();
        setLoseSplash(score);
    }
        setMusic();
    while(running())
    {
        refresh();  //update the splash
    }
    play_.stop();
}

Splashscreen::~Splashscreen()
{
    delete window;
}

//------------------------------------------------------------------------------------------------------------------------------------
// PRIVATE FUNCTIONS [SET UP]
//------------------------------------------------------------------------------------------------------------------------------------
void Splashscreen::setVariables()
{
    GameOver = false;
}

void Splashscreen::setWindow()
{
    windowSpecs = sf::VideoMode(1000,720); //set width and height
    window = new sf::RenderWindow(windowSpecs, "Centipede++ (START MENU) ", sf::Style::Close | sf::Style::Titlebar ); //can name game and set style

    //texture of splash screen
    sf::Texture texture;
    texture.loadFromFile("resources/NemoScreen.jpeg");
    sf::Sprite s(texture);

    // Draw it
    window->draw(s);
    window->display();

}

void Splashscreen::setMusic()
{
    if(!buffer.loadFromFile("resources/SplashScreenMusic.wav"))
    {
        std::cout<< "Error"<<std::endl;
    }
        play_.setBuffer(buffer);
        play_.play();
}

void Splashscreen::readInFonts()
{
    if(!font1.loadFromFile("resources/Ocean Summer.ttf"))
    {
        std::cout << "Error: Could not load texture file" << "\n";
    }

    text.setFont(font1);
    text.setString(std::to_string(myScore));
    text.setCharacterSize(48); // in pixels, not points!
    text.setFillColor(sf::Color::Red);
    text.setStyle(sf::Text::Bold);

    text2.setFont(font1);
    text2.setString(std::to_string(topScore));
    text2.setCharacterSize(48);
    text2.setFillColor(sf::Color::Red);
    text2.setStyle(sf::Text::Bold);
}

//-------------------------------------------------------------------------------------------------------------------------------
// AFTER GAME SPLASH (WIN OR LOSE)
//-------------------------------------------------------------------------------------------------------------------------------
void Splashscreen::setWinSplash(int score)
{
    windowSpecs = sf::VideoMode(1000,720); //set width and height
    window = new sf::RenderWindow(windowSpecs, "Centipede++ WIN", sf::Style::Close | sf::Style::Titlebar ); //can name game and set style

    //texture of splash screen
    sf::Texture texture;
    texture.loadFromFile("resources/winSplash.png");
    sf::Sprite s(texture);

    text.move(410.f, 275.f);
    text2.move(410.f, 335.f);

    // Draw it
    window->draw(s);
    window->draw(text);
    window->draw(text2);
    window->display();
}

void Splashscreen::setLoseSplash(int score)
{
    windowSpecs = sf::VideoMode(1000,720); //set width and height
    window = new sf::RenderWindow(windowSpecs, "Centipede++ LOSE ", sf::Style::Close | sf::Style::Titlebar ); //can name game and set style

    //texture of splash screen
    sf::Texture texture;
    texture.loadFromFile("resources/loseSplash.png");
    sf::Sprite s(texture);

    text.move(650.f, 285.f);
    text2.move(650.f, 340.f);

    // Draw it
    window->draw(s);
    window->draw(text);
    window->draw(text2);
    window->display();
}

//------------------------------------------------------------------------------------------------------------------------------------
// PUBLIC FUNCTIONS
//------------------------------------------------------------------------------------------------------------------------------------
const bool Splashscreen::running() const
{
    return window->isOpen();
}

const bool Splashscreen::endGameCheck(bool GameOver) const
{
    return GameOver;
}

void Splashscreen::checkEvents()
{
    while(window->pollEvent(windowEvent))
    {
        //events to close: either click X or the key Esc
        switch (windowEvent.type)
        {
        case sf::Event::Closed:
           window->close();
           GameOver=true;
           endGameCheck(GameOver);
           break;
        case sf::Event::KeyPressed:
           if(windowEvent.key.code == sf::Keyboard::Escape)
           {
              window->close();
              GameOver=true;
              endGameCheck(GameOver);
              break;
           }
           if(windowEvent.key.code == sf::Keyboard::Enter)
           {
                GameOver = false;
                window->close();
                break;
           }
        }
    }
}
//------------------------------------------------------------------------------------------------------------------------------------
// UPDATE & RENDER
//------------------------------------------------------------------------------------------------------------------------------------
void Splashscreen::refresh()
{
    checkEvents();
}
