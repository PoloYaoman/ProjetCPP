#ifndef _GAMEWINDOW_H_
#define _GAMEWINDOW_H_

#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

//include "Game.hpp"

/// Window class and start the game
class GameWindow {
private:
    const int windoWwidth = 1024, windowHeight = 768;

    sf::RenderWindow* window;
    sf::Event event;
    sf::VideoMode videoMode; //VideoMode defines a video mode (width, height, bpp) 

    //Game m_Game;

    void pollEvent(void);// declaration d'un event

    void drawSprite(sf::Sprite sprite); //dessine un sprites sur la main window

    void drawText(sf::Text Text);

    void drawVectorSprite(std::vector <sf::Sprite> vector);

    void drawVectorText(std::vector <sf::Text> vector);

    

public:
    ////////////////////////////////////////

    /// Default Constructor
    GameWindow(void);

    /// Destructor
    ~GameWindow(void);



    ////////////////////////////////////////

    /// \return true if the window is open
    bool isRunning(void);

    ////////////////////////////////////////

    /// Limit FPS
    /// \param frame FPS number
    void limitFrameRate(int frame);

    ///
   void controlWindow(void); //check les event

    //void updateWindow(void);// fais la maj de la windwow a chaquqe fps

    //void verificationWindow(void);
};

#endif