#include "HP.hpp"

bool HP::takeDamage(int damage) {
    this->hp_level -= damage;
    if (this->hp_level <= 0)    return true;
    return false;
}

void HP::heal(int hp) {
    this->hp_level += hp;
    if (this->hp_level > hp_total)  this->hp_level = this->hp_total;
}