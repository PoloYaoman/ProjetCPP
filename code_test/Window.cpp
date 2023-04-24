#include <iostream>

#include "Window.hpp"
#include "WalkableTile.hpp"

/* Constructeur a partir du nombre des cases et leur taille */
Window::Window(int size, int res) {
    this->_size = size;
    this->_res = res;

    for (int i=0; i<size*size; i++)
        this->_tiles.push_back(new Tile()); //meettre des cases une par une

    this->res(res); //changer leur resolution
}

/* Setter d'une case */
void Window::tile(int x, int y, Tile* n_tile) {
    int index = this->_size*x + y;  //chercher la bonne case
    //mettre la nouvelle case a la bonne resolution 
    if (this->_res != n_tile->size())   n_tile->size(this->_res);
    this->_tiles[index] = n_tile;
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
                this->_tiles[index]->renderTile(win, i, j);
            }
        }

        win.display();
    }
}

Window* Window::map1() {
    Window* nwin = new Window(15,40);

    for (int i = 0; i < nwin->_size; i++) {
        for (int j = 0; j < nwin->_size; j++) {
            WalkableTile* nt = new WalkableTile();
            nwin->tile(i,j,nt);
        }
    }   

    return nwin;
}

const bool Window::placeCharacter(int x, int y, Character* chr) {
    if (x < 0 || y < 0 || x >= this->_size || y >= this->_size) {
        throw std::invalid_argument("The coordinates must be inside the window");
        return false;
    }
    chr->pos(x,y);
    return true;
}