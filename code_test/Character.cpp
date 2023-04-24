#include "Character.hpp"
#include "TexturesLib.hpp"

Character::Character (string filename, int size, int posX, int posY) {
    this->_size = size;

    this->_texture = *(TexturesLib::assignTexture(filename));

    this->setScale2Texture();

    this->_posX = posX;
    this->_posY = posY;
}

void Character::renderTile (sf::RenderWindow& win, int x, int y, int size_tile) {
    float xoffset = size_tile*x + size_tile/2-this->_size/2;
    float yoffset = size_tile*y + size_tile/2-this->_size/2;
    this->move(xoffset, yoffset);
    win.draw(this->_sprite);
}

void Character::go (string dir, int size) {
    if (dir == "U") {
        if (this->_posY > 0)   pos(this->_posX, this->_posY-1);
    } else if (dir == "D") {
        if (this->_posY < size-1)   pos(this->_posX, this->_posY+1);
    } else if (dir == "L") {
        if (this->_posX > 0)   pos(this->_posX-1, this->_posY);
    } else if (dir == "R") {
        if (this->_posX < size-1)   pos(this->_posX+1, this->_posY);
    } else if (dir == "UL") {
        this->go("U",size);
        this->go("L",size);
    } else if (dir == "UR") {
        this->go("U",size);
        this->go("R",size);
    } else if (dir == "DL") {
        this->go("D",size);
        this->go("L",size);
    } else if (dir == "DR") {
        this->go("D",size);
        this->go("R",size);
    }
}

void Character::setScale2Texture() {
    int wid = this->_texture.getSize().x;  //prendre la taille de l'image
    int hgt = this->_texture.getSize().y;

    //assigner la nouvelle texture et mettre a l'echelle de base
    this->_sprite.setTexture(this->_texture);  
    this->_sprite.setScale(float(this->_size)/wid, float(this->_size)/hgt);
}

void Character::move(float x, float y) {
    this->_sprite.setPosition(0.f, 0.f);
    this->_sprite.move(x, y);
}