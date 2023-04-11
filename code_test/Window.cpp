#include "Window.hpp"

Window::Window(int size, int res) {
    this->_size = size;

    for (int i=0; i<size*size; i++) {
        this->_tiles.push_back(new Tile());
        this->_tiles[i]->size(res);
    }
}

void Window::tile(int x, int y, Tile& n_tile) {
    int index = this->_size*x + y;
    
    if (this->_res != n_tile.size())    n_tile.size(this->_res);
    
    this->_tiles[index] = &n_tile;
}

void Window::res(int nres) {
    for (int i=0; i<(this->_size*this->_size); i++)   
        this->_tiles[i]->size(nres);
}

void Window::renderWindow() {
    sf::RenderWindow window(sf::VideoMode(700, 700), "SFML works!");

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        for (int i = 0; i < this->_size; i++) {
            for (int j = 0; j < this->_size; j++) {
                int index = this->_size*i + j;
                this->_tiles[index]
                    ->position(float(this->_res * i), float(this->_res * j));
                
                window.draw(_tiles[index]->sprite());
            }
        }

        window.display();
    }
}