#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Tile.hpp"

class Character : public Tile {
    private:
        sf::Texture _texture;
        sf::Sprite _sprite;
        int _size;   // taille en pixels

        int _posX;  // position en numero de case
        int _posY;

    public:
        /* Constructeur par defaut : charge une texture dpar defaut de taille 35 */
        Character() : Character("jerma.png") {};
        Character(sf::Sprite& sprite, int size = 35, int posX = 0, int posY =0) : 
            _sprite(sprite), _size(size), _texture(*(sprite.getTexture())), 
            _posX(posX), _posY(posY) {};
        Character(string filename, int size = 35, int posX = 0, int posY = 0);

        /* Accesseurs de _posX et _posY*/
        const bool pos(int x, int y);
        const int posX() const;
        const int posY() const;

        /* Faire deplacer le personnage d'une case dans une direction : 
        "U", "D", "L", "R", "UL", "UR", "DL", "DR" */
        const bool go(string direction);

        // Affichage du personnage
        void renderTile(sf::RenderWindow& win, int x, int y, int size_tile);
};

#endif