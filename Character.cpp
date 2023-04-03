#include "Character.hpp"

Character::Character(string name, HP hp, Position position) {
    this->name = name;
    this->hp = hp;
    this->position = position;
}

Character::Character(string name, HP hp, int posX, int posY) {
    this->name = name;
    this->hp = hp;
    Position* npos = new Position(posX, posY);
    this->position = (*npos);
}

Character::Character(string name, int hp_total, Position position) {
    this->name = name;
    HP* nhp = new HP(hp_total);
    this->hp = (*nhp);
    this->position = position;
}

Character::Character(string name, int hp_total, int posX, int posY) {
    this->name = name;
    HP* nhp = new HP(hp_total);
    this->hp = (*nhp);
    Position* npos = new Position(posX, posY);
    this->position = (*npos);
}

void Character::setPosition(int posX, int posY) {
    this->position.setPosX(posX);
    this->position.setPosY(posY);
}
void Character::setPosition(Position position) {
    this->position = position;
}

const bool Character::inRange(Character& other, char method) const {
    int rng = 1;    // Distance atteignable par defaut
    switch (method) {
        case 'a' :
            //rng = this->weapon.getRange();
            break;
        case 'h' :
            break;
        case 't' :
            break;
    }

    if (this->position.calculateDistance(other.position)>rng)  return false;
    return true;
}

int Character::attack(Character *target) {
    int dmg = 10;    // Degats par defaut
    //dmg = this->weapon.getDamage();
    //dmg -= dmg * target->armor.getProtection;
    if (this->inRange(*target,'a')) {
        target->hp.takeDamage(dmg);
        return dmg;
    }
    return 0;
}
