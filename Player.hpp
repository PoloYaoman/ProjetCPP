#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>

#define RES 40      // taille d'une case en pixels
#define MAXHP 10    // vie max par defaut

using namespace std;

class Player {
    private:
        map<char, sf::Texture*> _ort_textures;    // textures pour les differentes orientations 
        map<char, sf::Texture*> _attack_textures; // pareil pais pour une attaque 

        sf::Sprite _sprite;
        int _posX;  int _posY;  // position en numero de case
        char _ort;              // orientation 'U', 'D', 'L', 'R'

        int _hp;
        int _maxHP;

        // vector<Item*> _items;   // inventaire
        // Weapon& _aweapon;       // arme active
        // Armor& _aarmor;         // armure active

        /* Fonctions utiles */
        //void loadSprite(sf::Sprite& sp);    // met la texture a la bonne echelle 

    public:
        /* Constructeurs */
        Player(string texture_file_up, int maxHP = MAXHP);
        Player(string texture_file_up, string texture_file_down, string texture_file_left, 
            string texture_file_right, string attack_file_up, string attack_file_down, 
            string attack_file_left, string attack_file_right, int maxHP = MAXHP);
        Player(const Player& cp);

        /* Operateurs*/
        Player& operator=(const Player& cp);

        /* Destructeur */
        //~Player();

        /* Accesseurs */
        //const sf::Sprite& sprite() const { return _sprite; };   //accesseur constant (a voir)
        void sprite(string texture_file);

        const int& posx() const { return _posX; };
        const int& posy() const { return _posY; };
        const bool pos(int x, int y);

        const char& orientation() const { return _ort; };
        void orientation(char nort) { _ort = nort; };

        const int& hp() const { return _hp; };
        const int& maxHP() const { return _maxHP; };
        void maxHP(int nmhp) { _maxHP = nmhp; };

        /* Fonctions */
        void render() const;

        void move(char dir);    // bouger dans le sens 'U', 'D', 'L', 'R'
        void turn(char dir);    // tourner sur place dans le sens 'U', 'D', 'L', 'R'

        //void interact(int action, Tile obj_type);   // 1 pour attaquer, 2 pour parler, 3 pour utiliser (ouvrir par exemple)
};

#endif