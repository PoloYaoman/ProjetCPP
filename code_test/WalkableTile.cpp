#include "WalkableTile.hpp"
#include "Character.hpp"
#include "TexturesLib.hpp"

WalkableTile::WalkableTile(string filename, int size) {
    this->_size = size;

    this->_texture = *(TexturesLib::assignTexture(filename));

    this->setScale2Texture();

    this->_presence = -1;
}

void WalkableTile::renderTile (sf::RenderWindow& win, int x, int y) {
    this->move(this->_size*x, this->_size*y);
    win.draw(this->_sprite);
}