#ifndef _MONSTER_HPP_
#define _MONSTER_HPP_

#include <SFML/Graphics.hpp>
// #include <iostream>
// #include <vector>

#include "Character.hpp"
// // #include "Gain.hpp"
// // #include "Heart.hpp"

#define MAXHP_MONSTER 5
#define DEFAULT_DMG 3

class Monster : public Character {
    private:
        map<char, sf::Texture*> _ort_textures;    // textures pour les differentes orientations 
        map<char, sf::Texture*> _attack_textures; // pareil pais pour une attaque 

        sf::Sprite _sprite;
        int _posX;  int _posY;  // position en numero de case
        char _ort;              // orientation 'U', 'D', 'L', 'R'

        int _hp;
        int _maxHP;

        bool _alive;

        int _power;

        int _heartLoot;
        int _rubisLoot;

        /* Fonctions utiles */
        //void loadSprite(sf::Sprite& sp);    // met la texture a la bonne echelle

    public:
        /* Constructeurs */
        Monster(string texture_file_up, int maxHP = MAXHP_MONSTER);
        Monster(string texture_file_up, string texture_file_down, string texture_file_left, 
            string texture_file_right, string attack_file_up, string attack_file_down, 
            string attack_file_left, string attack_file_right, int maxHP = MAXHP_MONSTER, 
            int power = DEFAULT_DMG, int hpLoot = 0, int rLoot = 0);
        Monster(const Monster& cp);

        /* Operateurs*/
        Monster& operator=(const Monster& cp);

        /* Destructeur */
        ~Monster();

        /* Accesseurs */
        void sprite(string texture_file);

        int power() const { return _power; };
        void power(int dmg) { _power = dmg; };

        int heartLoot() const { return _heartLoot; };
        int rubisLoot() const { return _rubisLoot; };
        void heartLoot(int loot) { _heartLoot = loot; };
        void rubisLoot(int loot) { _rubisLoot = loot; };

        /* Fonctions */
        void render() const;

        void move(char dir);    // bouger dans le sens 'U', 'D', 'L', 'R'
        void turn(char dir);    // tourner sur place dans le sens 'U', 'D', 'L', 'R'

        void receiveDamage(int dmg);
};

// class Monster {
// public:
//     // Constructeur / Destructeur
//     // Constructeur
//     Monster(void);

//     Monster(const char *name);

//     // Destructeur
//     ~Monster(void);

//     // Accessor
//     Monster *getAdress(void);

//     Monster getMonster(void);

//     // Sprite
//     sf::Sprite getSprite(void);

//     // Position
//     sf::Vector2f getPosition(void);

//     sf::Vector2f getNextPosition(void);

//     // Power
//     int getPower(void);

//     // alive
//     //fait appel �  des fonction de la class Heart
//     bool isAlive(void);

//     bool isInvulnerable(void);

//     // fait appel �  des fonction de la class Gain

//     int getGainRubisValor(void);

//     int getGainLifeValor(void);

//     bool thereGain(void); // fonction permettant de dire une fois tu� le monstre donne ou non une recompense , fait appel � une fonction de la class Gain

//     // Function
//     // Attribution
//     void setPower(int power);

//     void move(void);

//     void nextPosition(void); // utilise createPaternRelative() pour creer une nouveau deplacment aleatoire pour le monstre

    

//     // les recoil font appel � move

//     void recoilUp(void);

//     void recoilDown(void);

//     void recoilRight(void);

//     void recoilLeft(void);

//     void createPaternRelative(void); // rempli pattern

//     void gainIsGet(void);

//     //fait appel �  des fonction de la class Heart
//     void frameInvulnerable(void);

//     void setDamage(int power);

// private:
//     // Variable
//     // basic
//     int moveaction = 0,
//             power = 4;

//     const char *m_monster ; // chemin vers l'image

//     // std
//     std::vector <sf::Vector2f> patern; //contient les mouvement ( les prochaines positions )  pre-definie du monstre 

//     // SFML
//     sf::Sprite sprite;
//     sf::Texture texture;

//     // class
//     // Gain Gain;
//     // Heart Heart;

//     // Function
//     void loadTexture(const char *name); // meme principe que dans joueur

//     void loadSprite(void);

//     void initSprite(void); // fait appel �  loadTexture(m_monster) puis � loadSprite() et ensuite � loadPosition()

//     void loadPosition(void);

//     //fait appel �  des fonction de la class Heart

//     void dropGain(void);

// };

#endif