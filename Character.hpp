#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

using namespace std;

#include "HP.hpp"
#include "Position.hpp"

class Character {
    private:
        string name;
        HP hp;
        Position position;
        //Weapon weapon
        //Armor armor

        /* Renvoie true si le personnage est atteignable pour une methode 'a'
        (attaquer), 'h' (soigner) ou 't' (interagir)*/
        const bool inRange(Character& other, char method) const;

    public:
        Character(string name, HP hp, Position position);
        Character(string name, HP hp, int posX, int posY);
        Character(string name, int hp_total, Position position);
        Character(string name, int hp_total, int posX, int posY);

        void setName(string name) { this->name = name; };
        const string getName() const { return this->name; };
        const HP getHP() const { return this->hp; };
        void setPosition(int posX, int posY);
        void setPosition(Position position);
        const Position getPosition() const { return this->position; };

        /* Attaque le personnage character, retourne les degats infliges */
        int attack(Character *target);
        /* Soigne le personnage character */
        //int heal(Character *target);
        /* Interagit avec le personnage character */
        //void talk(Character *target);
};

#endif