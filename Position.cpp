#include "Position.hpp"

#include <math.h>

const int Position::calculateDistance(Position& other) const {
    int diffX = abs(this->posX - other.posX);
    int diffY = abs(this->posY - other.posY);
    float fdist = sqrt(diffX * diffX + diffY * diffY);
    return round(fdist);
}