#include "Tile.hpp"

/* Constructeur a partir du nom de fichier de la texture et la taille de la 
case*/
Tile::Tile(string filename, int size) {
    this->_size = size;

    sf::Texture texture;
    if (!texture.loadFromFile(filename))    //charger le fichier
        throw runtime_error("Couldn't load texture from file " + filename);

    int wid = texture.getSize().x;  //prendre la taille de l'image
    int hgt = texture.getSize().y;

    this->_sprite.setTexture(texture);  //donner la texture au sprite
    this->_sprite.setScale(size/wid,size/hgt);  //mettre a l'echelle de size
}

/* Setter a partir de sprite */
void Tile::sprite(sf::Sprite& n_sprite) {
    //trouver la taille du sprite
    int sx = n_sprite.getTexture()->getSize().x * n_sprite.getScale().x;
    int sy = n_sprite.getTexture()->getSize().y * n_sprite.getScale().y;

    this->_sprite = n_sprite;

    if (sx!=sy) //rendre carre si c'est pas deja le cas
        this->_sprite.setScale(1,sx/sy);  

    this->_size = sx;
}

/* Setter a partir du nom de fichier */
const bool Tile::sprite(string filename){
    sf::Texture texture;
    if (!texture.loadFromFile(filename)) {  //charger la nouvelle texture
        throw runtime_error("Couldn't load texture from file " + filename);
        return false;
    }

    int wid = texture.getSize().x;  //prendre la taille de l'image
    int hgt = texture.getSize().y;

    //assigner la nouvelle texture et mettre a l'echelle de base
    this->_sprite.setTexture(texture);  
    this->_sprite.setScale(this->_size/wid, this->_size/hgt);

    return true;
}

/* Setter de la taille */
void Tile::size(int size) {
    int size_tmp = this->_size;
    this->_size = size;

    //mettre a la nouvelle echelle
    this->_sprite.setScale(size_tmp/size, size_tmp/size);
}

/* Position de la case dans la fenetre */
void Tile::position(float x, float y) {
    this->_sprite.setPosition(x, y);
}
