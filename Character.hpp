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

    public:
        Character(string name, HP hp, Position position);
        Character(string name, HP hp, int posX, int posY);
        Character(string name, int hp_total, Position position);
        Character(string name, int hp_total, int posX, int posY);

        void setName(string name) { this->name = name; };
        string getName() { return this->name; };
        HP getHP() { return this->hp; };
        void setPosition(int posX, int posY);
        void setPosition(Position position);
        Position getPosition() { return this->position; };
};

#endif