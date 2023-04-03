#ifndef POSITION_HPP
#define POSITION_HPP

class Position {
    private:
        int posX;
        int posY;

    public:
        Position(int posX, int posY) : posX(posX), posY(posY) {};
        
        int getPosX() { return posX; }
        void setPosX(int posX) { this->posX = posX; }
        int getPosY() { return posY; }
        void setPosY(int posY) { this->posY = posY; }
};

#endif