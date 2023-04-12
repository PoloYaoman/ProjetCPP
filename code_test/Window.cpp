#include <iostream>

#include "Window.hpp"

/* Constructeur a partir du nombre des cases et leur taille */
Window::Window(int size, int res) {
    this->_size = size;
    this->_res = res;

    for (int i=0; i<size*size; i++) {
        this->_tiles.push_back(new Tile()); //meettre des cases une par une
        this->_tiles[i]->size(res); //changer leur resolution
    }
}

/* Setter d'une case */
void Window::tile(int x, int y, Tile& n_tile) {
    int index = this->_size*x + y;  //chercher la bonne case
    //mettre la nouvelle case a la bonne resolution 
    if (this->_res != n_tile.size())    n_tile.size(this->_res);
    this->_tiles[index] = &n_tile;
}

/* Changer la taille des cases */
void Window::res(int nres) {
    for (int i=0; i<(this->_size*this->_size); i++)   
        this->_tiles[i]->size(nres);
}

/* Montrer la fenetre */
void Window::renderWindow() {
    int wid = this->_size * this->_res; //taille de la fenetre en pixels
    sf::RenderWindow win(sf::VideoMode(wid, wid), "SFML works!");

    while (win.isOpen()) {
        sf::Event event;

        while (win.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                win.close();
        }

        win.clear();

        for (int i = 0; i < this->_size; i++) {
            for (int j = 0; j < this->_size; j++) {
                int index = this->_size*i + j;
                //mettre la case a la bonne position 
                this->_tiles[index]
                    ->move(float(this->_res * i), float(this->_res * j));
                cout << "Position x = " << this->_res * i << " , y = " << this->_res * j << endl;

                win.draw(_tiles[index]->sprite());
            }
        }

        win.display();
    }
}