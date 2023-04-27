#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>

#include "Character.hpp"

#include "./Items/Sword.hpp"

#define MAXHP_PLAYER 10    // vie max par defaut

using namespace std;

class Player : public Character {
    private:
        map<char, sf::Texture*> _ort_textures;    // textures pour les differentes orientations 
        map<char, sf::Texture*> _attack_textures; // pareil pais pour une attaque 

        sf::Sprite _sprite;
        int _posX;  int _posY;  // position en numero de case
        char _ort;              // orientation 'U', 'D', 'L', 'R'

        int _hp;
        int _maxHP;

        bool _alive;

        int _rubis;

        // vector<Item*> _items;   // inventaire
        Sword* _aweapon = NULL;       // arme active
        // Armor& _aarmor;         // armure active

        /* Fonctions utiles */
        //void loadSprite(sf::Sprite& sp);    // met la texture a la bonne echelle 

        void setWindowPosition(float x, float y);

    public:
        /* Constructeurs */
        Player(string texture_file_up, int maxHP = MAXHP_PLAYER);
        Player(string texture_file_up, string texture_file_down, string texture_file_left, 
            string texture_file_right, string attack_file_up, string attack_file_down, 
            string attack_file_left, string attack_file_right, int maxHP = MAXHP_PLAYER);
        Player(const Player& cp);

        /* Operateurs*/
        Player& operator=(const Player& cp);

        /* Destructeur */
        ~Player();

        /* Accesseurs */

        /* Fonctions */
        void render(sf::RenderWindow win, int x, int y);

        void move(char dir);    // bouger dans le sens 'U', 'D', 'L', 'R'
        void turn(char dir);    // tourner sur place dans le sens 'U', 'D', 'L', 'R'

        //sf::Vector2f position() { return _sprite.getPosition(); }

        //void interact(int action, Tile obj_type);   // 1 pour attaquer, 2 pour parler, 3 pour utiliser (ouvrir par exemple)

        void receiveDamage(int dmg);
        void heal(int hp);

        void updateRubis(int rubis) { _rubis += rubis; };

        char inRange(const Character& target);
};

#endif