#ifndef POSITION_HPP
#define POSITION_HPP

class Position {
    private:
        int posX;
        int posY;

    public:
        Position() : posX(0), posY(0) {};
        Position(int posX, int posY) : posX(posX), posY(posY) {};
        
        const int getPosX() const { return posX; }
        void setPosX(int posX) { this->posX = posX; }
        const int getPosY() const { return posY; }
        void setPosY(int posY) { this->posY = posY; }

        const int calculateDistance(Position& other) const;
};

#endif