#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>

//#include "Heart.hpp"
//#include "Rubis.hpp"

class Joueur {
private:
    // 4 orientations (haut , bas , gauche , droite) possible et 3 etats possible du joeur ( arret, pied gauche en avant ou pied droit en avant)
    const char* s0,
        * s1,
        * s2,
        * s3,
        * s4,
        * s5,
        * s6,
        * s7,
        * s8,
        * s9,
        * s10,
        * s11;

        int  movedown = 0,
            moveup = 0,
            moveleft = 0,
            moveright = 0,
            vitesse = 5;

        bool orientationright = false,
             orientationup = false,
             orientationleft = false,
             orientationdown = false;

        // std
        std::vector<const char *> animationUp,
            animationDown,
            animationRight,
            animationLeft;

        // SFML/Graphics
        sf::Texture texturehero;
        sf::Sprite spritehero;
        sf::Vector2f spawn;

        // class
        // Heart m_Heart;
        // Rubis m_Rubis;

        // Function
        sf::Sprite loadSprite(const char *name, sf::Vector2f vector); // cette focntion appel loadTexture et applique enssuite la texture au sprite

        void loadTexture(const char *name);// ce serait donc cette methode qui appelerait la methode de la classe static 

        void moveUp(void);

        void moveDown(void);

        void moveRight(void);

        void moveLeft(void);

        void makeListeAnimation(void);

        void moveAniamtion(int frame, std::vector<const char *> liste);

public:
        // Constructor / Destructor
        Joueur(void);

        ~Joueur(void);

        // Accessor
        sf::Sprite getSprite(void);

        sf::Vector2f getPosition(void);

        sf::Vector2f getPositionSword(void);

        Joueur *getAdress(void);

        int getLife(void);

        int getMaxLife(void);

        bool isAlive(void);

        bool isInvulnerable(void);

        int getSpeed(void);

        bool getOrientationUp(void);

        bool getOrientationDown(void);

        bool getOrientationLeft(void);

        bool getOrientationRight(void);

        int getOrientationValue(void);

        // Heart
        std::vector<sf::Sprite> getListSpriteHeart(void);

        sf::Sprite getSpriteHeart(int number);

        // Rubis
        sf::Sprite getLogoRubis(void);

        sf::Text getRubisHundred(void);

        sf::Text getRubisTen(void);

        sf::Text getRubisUnit(void);

        int getTotalRubis(void);

        // Function
        void setOrientationUp(void);

        void setOrientationDown(void);

        void setOrientationRight(void);

        void setOrientationLeft(void);

        void setMaxLifeUp(void);

        void setHeart(int life);

        void setDamage(int power);

        void frameInvulnerable(void);

        void setPositionUp(void);

        void setPositionDown(void);

        void setPositionLeft(void);

        void setPositionRight(void);


        // appel les methodes privé move

        void animationMoveDown(void);

        void animationMoveUp(void);

        void animationMoveLeft(void);

        void animationMoveRight(void);
    
        void recoilLeft(void);
    
        void recoilRight(void);
    
        void recoilDown(void);
    
        void recoilUp(void);
};

#endif
