#ifndef TILE_HPP
#define TILE_HPP

#include <SFML/Graphics.hpp>

using namespace std;

class Tile {
    private:
        sf::Sprite _sprite;
        int _size;   // taille en pixels


    public:
        /* Constructeur par defaut : cree une case avec une tete de Jerma de 
        taille 35 pixels;
        Les constructeurs par sprite et par nom de fichier ont une taille 
        par defaut de 35 pixels */
        Tile() : Tile("jerma.png",35) {};
        Tile(sf::Sprite& sprite, int size = 35) : 
            _sprite(sprite), _size(size) {};
        Tile(string filename, int size = 35);

        /* Accesseurs de sprite */
        const sf::Sprite& sprite() const { return _sprite; };
        void sprite(sf::Sprite& n_sprite);
        const bool sprite(string filename);

        /* Accesseurs de size */
        const int& size() const { return _size; };
        void size(int size);

        // position de la case dans la fenetre
        void position(float x, float y);   
};

#endif