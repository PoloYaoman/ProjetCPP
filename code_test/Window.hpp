#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <vector>
#include <iostream>

#include "Tile.hpp"

using namespace std;

class Window {
    private: 
        int _size;  // Taille de la fenetre en nombre des cases
        int _res; //taille d'une case en pixel
        vector<Tile*> _tiles; // Cases rangees ligne par ligne

    public:
        /* Constructeur par defaut : cree une fenetre de 20 cases 
        Constructeur par taille cree un tableau des cases de taille 35 par defaut */
        Window() : Window(20,35) {};
        Window (vector<Tile*> c_tiles) : 
            _tiles(c_tiles), _size(c_tiles.size()) {};
        Window (int size, int res = 35);

        /* Accesseurs pour les cases */
        const Tile* tile(int x, int y) const { return _tiles[_size*x + y]; };    
        void tile(int x, int y, Tile& n_tile);

        /* Accesseurs pour la taille */
        const int size() const;

        /* Accesseurs pour la resolution */
        const int res() const { return _res; };
        void res(int nres);

        void renderWindow();    // Montrer une fenetre avec les cases 
};

#endif