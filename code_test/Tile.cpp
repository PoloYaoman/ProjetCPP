#include <iostream>

#include "TexturesLib.hpp"
#include "Tile.hpp"

using namespace std;

/* Constructeur a partir du nom de fichier de la texture et la taille de la 
case*/
Tile::Tile(string filename, int size) {
    this->_size = size;

    this->_texture = *(TexturesLib::assignTexture(filename));

    this->setScale2Texture();
}

/* Setter a partir de sprite */
void Tile::sprite(sf::Sprite& n_sprite) {
    this->_texture = *(n_sprite.getTexture());
    //trouver la taille du sprite
    int sx = this->getTextureX() * n_sprite.getScale().x;
    int sy = this->getTextureY() * n_sprite.getScale().y;

    this->_sprite = n_sprite;

    if (sx!=sy) //rendre carre si c'est pas deja le cas
        this->_sprite.setScale(1,float(sx)/sy);  

    this->_size = sx;
}

/* Setter a partir du nom de fichier */
const bool Tile::sprite(string filename){
    this->_texture = *(TexturesLib::assignTexture(filename));

    this->setScale2Texture();

    return true;
}

/* Setter de la taille */
void Tile::size(int size) {
    this->_size = size;

    this->setScale2Texture();
}

/* Position de la case dans la fenetre */
void Tile::move(float x, float y) {
    this->_sprite.setPosition(0.f, 0.f);
    this->_sprite.move(x, y);
}

void Tile::setScale2Texture() {
    int wid = this->_texture.getSize().x;  //prendre la taille de l'image
    int hgt = this->_texture.getSize().y;

    //assigner la nouvelle texture et mettre a l'echelle de base
    this->_sprite.setTexture(this->_texture);  
    this->_sprite.setScale(float(this->_size)/wid, float(this->_size)/hgt);
}

void Tile::renderTile(sf::RenderWindow& win, int x, int y) {
    this->move(this->_size*x, this->_size*y);
    win.draw(this->_sprite);
}