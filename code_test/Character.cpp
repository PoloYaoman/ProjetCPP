#include "Character.hpp"

Character::Character(string filename, int size, int posX, int posY) {
    this->_size = size;

    this->_texture = *(this->texture(filename));

    this->setScale2Texture();

    this->_posX = posX;
    this->_posY = posY;
}

void Character::renderTile(sf::RenderWindow& win, int x, int y, int size_tile) {
    float xoffset = size_tile*x + size_tile/2-this->_size/2;
    float yoffset = size_tile*y + size_tile/2-this->_size/2;
    this->move(xoffset, yoffset);
    win.draw(this->_sprite);
}