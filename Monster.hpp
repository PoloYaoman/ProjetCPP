#ifndef _MONSTER_HPP_
#define _MONSTER_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Gain.hpp"
#include "Heart.hpp"

class Monster {
public:
    // Constructeur / Destructeur
    // Constructeur
    Monster(void);

    Monster(const char *name);

    // Destructeur
    ~Monster(void);

    // Accessor
    Monster *getAdress(void);

    Monster getMonster(void);

    // Sprite
    sf::Sprite getSprite(void);

    // Position
    sf::Vector2f getPosition(void);

    sf::Vector2f getNextPosition(void);

    // Power
    int getPower(void);

    // alive
    //fait appel à  des fonction de la class Heart
    bool isAlive(void);

    bool isInvulnerable(void);

    // fait appel à  des fonction de la class Gain

    int getGainRubisValor(void);

    int getGainLifeValor(void);

    bool thereGain(void); // fonction permettant de dire une fois tué le monstre donne ou non une recompense , fait appel à une fonction de la class Gain

    // Function
    // Attribution
    void setPower(int power);

    void move(void);

    void nextPosition(void); // utilise createPaternRelative() pour creer une nouveau deplacment aleatoire pour le monstre

    

    // les recoil font appel à move

    void recoilUp(void);

    void recoilDown(void);

    void recoilRight(void);

    void recoilLeft(void);

    void createPaternRelative(void); // rempli pattern

    void gainIsGet(void);

    //fait appel à  des fonction de la class Heart
    void frameInvulnerable(void);

    void setDamage(int power);

private:
    // Variable
    // basic
    int moveaction = 0,
            power = 4;

    const char *m_monster ; // chemin vers l'image

    // std
    std::vector <sf::Vector2f> patern; //contient les mouvement ( les prochaines positions )  pre-definie du monstre 

    // SFML
    sf::Sprite sprite;
    sf::Texture texture;

    // class
    Gain Gain;
    Heart Heart;

    // Function
    void loadTexture(const char *name); // meme principe que dans joueur

    void loadSprite(void);

    void initSprite(void); // fait appel à  loadTexture(m_monster) puis à loadSprite() et ensuite à loadPosition()

    void loadPosition(void);

    //fait appel à  des fonction de la class Heart

    void dropGain(void);

};

#endif