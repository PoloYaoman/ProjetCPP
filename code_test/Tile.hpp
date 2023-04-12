#ifndef TILE_HPP
#define TILE_HPP

#include <SFML/Graphics.hpp>
#include <map>

using namespace std;

class Tile {
    private:
        //bibliotheque des textures classee par nom du fichier
        static map<string, sf::Texture*> _textures; 
        sf::Texture _texture;
        sf::Sprite _sprite;
        int _size;   // taille en pixels


    public:
        /* Constructeur par defaut : cree une case avec une tete de Jerma de 
        taille 35 pixels;
        Les constructeurs par sprite et par nom de fichier ont une taille 
        par defaut de 35 pixels */
        Tile() : Tile("jerma.png",50) {};
        Tile(sf::Sprite& sprite, int size = 50) : 
            _sprite(sprite), _size(size), _texture(*(sprite.getTexture())) {};
        Tile(string filename, int size = 50);

        /* Accesseurs de sprite */
        const sf::Sprite& sprite() const { return _sprite; };
        void sprite(sf::Sprite& n_sprite);
        const bool sprite(string filename);

        /* Accesseurs de size */
        const int& size() const { return _size; };
        void size(int size);

        /* Accesseurs de textures */
        sf::Texture* texture (string filename);

        // position de la case dans la fenetre
        void move(float x, float y);   
};

#endif