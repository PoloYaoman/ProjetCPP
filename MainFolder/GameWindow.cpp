#include "GameWindow.hpp"

// Constructor
GameWindow::GameWindow(void) {
    // Window size : (16* 64) * ((10 * 64) + 64) = 1024 * 704
    this->window = nullptr; // initialisation � nullptr par mesure de securit�
    this->window = new sf::RenderWindow(sf::VideoMode(windoWwidth, windowHeight), "Game"); // creation de la fenetre
    std::cout << "window create " << this << std::endl;
}



// Destructor
GameWindow::~GameWindow(void) {
    delete[] window;
    std::cout << "window delete " << this << std::endl;
}

// gestion clavier et souris 

void GameWindow::pollEvent(void) {
    if (this->window->pollEvent(this->event)) { //permet de v�rifier s'il y a un �v�nement en attente dans la file d'attente des �v�nements, si c'st le cas event stock l'evenement
        if (this->event.type == sf::Event::Closed) { // event=fermeture de la fenetre ?
            this->window->close();
        }
        else if (this->event.type == sf::Event::KeyPressed) { // utilisation du clavier ?
            if (this->event.key.code == sf::Keyboard::Escape) {
                this->window->close();
            }
            else if (this->event.key.code == sf::Keyboard::Down) {
                //game.keyDown();
            }
            else if (this->event.key.code == sf::Keyboard::Up) {
                //game.keyUp();
            }
            else if (this->event.key.code == sf::Keyboard::Left) {
                //game.keyLeft();
            }
            else if (this->event.key.code == sf::Keyboard::Right) {
                //game.keyRight();
            }
            else if (this->event.key.code == sf::Keyboard::Space) {
                //game.keySpace();
            }
        }
    }
}

void GameWindow::drawSprite(sf::Sprite sprite) {
    this->window->draw(sprite);
}

void GameWindow::drawText(sf::Text text) {
    this->window->draw(text);
}

void GameWindow::drawVectorSprite(std::vector <sf::Sprite> vector) {
    for (int number = 0; number < vector.size(); number++) {
        drawSprite(vector[number]);
    }
}

void GameWindow::drawVectorText(std::vector <sf::Text> vector) {
    for (int number = 0; number < vector.size(); number++) {
        drawText(vector[number]);
    }
}

bool GameWindow::isRunning(void) { // check si la fenetre est ouverte
    return window->isOpen();
}

void GameWindow::limitFrameRate(int frame) { //limite le nombre de FPS
    this->window->setFramerateLimit(frame);
}

/*void GameWindow::updateWindow(void) { // met a jour la fentre en utilisation des methodes priv�s
    this->window->clear();
    this->drawVectorSprite(this->Game.getDrawingSprite());
    this->drawVectorText(this->Game.getDrawingText());
    this->window->display();
}*/

/*void GameWindow::verificationWindow(void) { // regarde dans quel etat doit se trouver la fenetre
    this->Game.executionGame();
    if (!this->Game.playerIsAlive()) {
        this->window->close();
    }
}*/

void GameWindow::controlWindow(void) {
    this->pollEvent();
}

