#ifndef WALKABLETILE_HPP
#define WALKABLETILE_HPP

#include "Tile.hpp"

class WalkableTile : public Tile {
    private:
        sf::Texture _texture;
        sf::Sprite _sprite;
        int _size;   // taille en pixels

        bool _presence;
        //Character _chr;

    public:
        WalkableTile() : Tile("sand.jpg",50), _presence(false) {};
        WalkableTile(sf::Sprite& sprite, int size = 50) : 
            _sprite(sprite), _size(size), 
            _texture(*(sprite.getTexture())), _presence(false) {};
        WalkableTile(string filename, int size = 50);

        void renderCharacter();
};

#endif