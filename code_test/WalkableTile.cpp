#include "WalkableTile.hpp"

WalkableTile::WalkableTile(string filename, int size) {
    this->_size = size;

    this->_texture = *(this->texture(filename));

    this->setScale2Texture();

    this->_presence = false;
}
