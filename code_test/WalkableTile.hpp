#ifndef WALKABLETILE_HPP
#define WALKABLETILE_HPP

#include "Tile.hpp"

class WalkableTile : public Tile {
    private:
        sf::Texture _texture;
        sf::Sprite _sprite;
        int _size;   // taille en pixels

        //static vector<int, Character*> _chrs;
        int _presence;  // numero du personnage present sur la case (-1 si aucun)

    public:
        WalkableTile() : Tile("sand.jpg",50), _presence(-1) {};
        WalkableTile(sf::Sprite& sprite, int size = 50) : 
            _sprite(sprite), _size(size), 
            _texture(*(sprite.getTexture())), _presence(-1) {};
        WalkableTile(string filename, int size = 50);

        void renderTile(sf::RenderWindow& win, int x, int y);
};

#endif