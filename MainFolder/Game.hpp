#ifndef _GAME_HPP_
#define _GAME_HPP_

/// Special library
#include <SFML/Graphics.hpp>

/// STL
#include <iostream>
#include <vector>
#include <string>

/// Header create
#include "./MovableObject/Player.hpp"
#include "./MovableObject/Monster.hpp"
//#include "./ImmovableObject/Wall.hpp"
#include "./ImmovableObject/Ground.hpp"
#include "DrawInterface.hpp"
#include "ControlInterface.hpp"
#include "ColisionInterface.hpp"
//#include "./Items/Sword.hpp"
#include "MapGenerator.hpp"


/// Size Sprite
#define SPRITE_SIZE             64 // j'ai vu que c'etait souvent la norme dans ce style de jeu

/// Size Game
#define LIMIT_UP_GAME           64
#define LIMIT_DOWN_GAME         768
#define LIMIT_RIGHT_GAME        1024
#define LIMIT_LEFT_GAME         0

#define NO_COLLIDE              0
#define LEFT_COLLIDE            1
#define RIGHT_COLLIDE           2
#define UP_COLLIDE              3
#define DOWN_COLLIDE            4

class Game : public DrawInterface , public ControlInterface, public ColisionInterface{
private:
    /// Picture's adress for sprite

    //Decor
    const char* classicGrass_c,
        * classicTree_c,
        * classicRock_c;

    /// Vector monster for all monster test
   std::vector <Monster> listMonster;

    
    /// Class Joueur
    Player player;

    /// Class Monster
    Monster monster;

    //Class Wall
    // Wall classicTree,
    //     classicRock;

    /// Class Ground
    Ground classicGrass;


    /// Class MapGenerator
    MapGenerator map;

    /// Class Sword
    //Sword sword;

    ////////////////////////////////////////

    /// Call all function for create a new map
    void setMapUpdate(void);

    /// Check if the player is in the limit of the map and where
    void switchMap(void);

    /// Combine the list of vector2 with their sprite
    void setBackground(void);

    ///
    void gainChest(void);

    ////////////////////////////////////////

    /// Check for all Monster if they are in contact with the Sword
    void swordAttack(void);

    /// Afflict damage at the mob in conatct with the sword
    /// \param mob position in the vector
    void monsterReceveAttack(int monster);

    ////////////////////////////////////////

    /// Move and check if the monster can move
    void moveMonster(void);

    /// Make the list of the monster
    void makeListMonster(void);

    ////////////////////////////////////////



public:
    /// Default Constructor
    Game() = default;

    /// \return true if player is alive
    bool playerIsAlive(Player& player);
   
};

#endif
