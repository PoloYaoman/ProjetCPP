#ifndef CHARACTER_HPP
#define CHARACTER_HPP

/* Classe dont heritent les joueurs, les monstres et les NPC */

#include <SFML/Graphics.hpp>

#define RES 64      // taille d'une case en pixels
#define WIN_RES 15

using namespace std;

class Character {
    protected:
        map<char, sf::Texture*> _ort_textures;    // textures pour les differentes orientations 
        map<char, sf::Texture*> _attack_textures; // pareil pais pour une attaque 

        sf::Sprite _sprite;
        int _posX;  int _posY;  // position en numero de case
        char _ort;              // orientation 'U', 'D', 'L', 'R'

        int _hp;
        int _maxHP;

        bool _alive;

        // vector<Item*> _items;   // inventaire
        // Weapon& _aweapon;       // arme active
        // Armor& _aarmor;         // armure active

        /* Fonctions utiles */
        //void loadSprite(sf::Sprite& sp);    // met la texture a la bonne echelle
        virtual void setWindowPosition(float x, float y);   // position dans la fenetre en pixels

    public:
        //Character(string texture_file_up, int maxHP = MAXHP);
        //Character(string texture_file_up, string texture_file_down, string texture_file_left, 
            // string texture_file_right, string attack_file_up, string attack_file_down, 
            // string attack_file_left, string attack_file_right, int maxHP = MAXHP);
        //Character(const Character& cp);

        /* Operateurs*/
        virtual Character& operator=(const Character& cp);

        /* Destructeur */
        //~Player();

        /* Accesseurs */
        virtual const sf::Sprite& sprite() const { return _sprite; };   //accesseur constant (a voir)
        virtual void sprite(string texture_file);

        virtual const int& posx() const { return _posX; };
        virtual const int& posy() const { return _posY; };
        virtual const bool pos(int x, int y);

        virtual const char& orientation() const { return _ort; };
        virtual void orientation(char nort) { _ort = nort; };

        virtual const int& hp() const { return _hp; };
        virtual const int& maxHP() const { return _maxHP; };
        virtual void maxHP(int nmhp) { _maxHP = nmhp; };

        /* Fonctions */
        virtual void render(sf::RenderWindow win, int x, int y);

        virtual void move(char dir);    // bouger dans le sens 'U', 'D', 'L', 'R'
        virtual void turn(char dir);    // tourner sur place dans le sens 'U', 'D', 'L', 'R'

        virtual sf::Vector2f position() { return _sprite.getPosition(); };

        virtual bool isAlive() { return _alive; };

        virtual void receiveDamage(int dmg);

        virtual char inRange(const Character& target); // envoie la direction si la cible est atteignable, 'N' sinon
};

#endif