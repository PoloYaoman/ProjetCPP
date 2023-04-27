#include "Player.hpp"
#include "./MainFolder/TexturesLib.hpp"

Player::Player(string texture_file_down, int maxHP = MAXHP_PLAYER) {
    _ort_textures.insert({'D', TexturesLib::assignTexture(texture_file_down)});

    _sprite.setTexture(*_ort_textures['D']);

    _maxHP = maxHP;
    _hp = maxHP;

    _posX = -1; _posY = -1; // hors carte tant que pas place 
    _ort = 'D';

    _alive = true;
}

Player::Player(string texture_file_up, string texture_file_down, string texture_file_left, 
            string texture_file_right, string attack_file_up, string attack_file_down, 
            string attack_file_left, string attack_file_right, int maxHP = MAXHP_PLAYER) {
    _ort_textures.insert({'U', TexturesLib::assignTexture(texture_file_up)});
    _ort_textures.insert({'D', TexturesLib::assignTexture(texture_file_down)});
    _ort_textures.insert({'L', TexturesLib::assignTexture(texture_file_left)});
    _ort_textures.insert({'R', TexturesLib::assignTexture(texture_file_right)});

    _attack_textures.insert({'U', TexturesLib::assignTexture(attack_file_up)});
    _attack_textures.insert({'D', TexturesLib::assignTexture(attack_file_down)});
    _attack_textures.insert({'L', TexturesLib::assignTexture(attack_file_left)});
    _attack_textures.insert({'R', TexturesLib::assignTexture(attack_file_right)});

    _sprite.setTexture(*_ort_textures['D']);

    _maxHP = maxHP;
    _hp = maxHP;

    _posX = -1; _posY = -1; // hors carte tant que pas place 
    _ort = 'D';

    _alive = true;
}

Player::Player(const Player& cp) {
    *this = cp;
}


Player& Player::operator=(const Player& cp) {
    this->_ort_textures.insert({'U', cp._ort_textures.at('U')});
    this->_ort_textures.insert({'D', cp._ort_textures.at('D')});
    this->_ort_textures.insert({'L', cp._ort_textures.at('L')});
    this->_ort_textures.insert({'R', cp._ort_textures.at('R')});

    this->_attack_textures.insert({'U', cp._attack_textures.at('U')});
    this->_attack_textures.insert({'D', cp._attack_textures.at('D')});
    this->_attack_textures.insert({'L', cp._attack_textures.at('L')});
    this->_attack_textures.insert({'R', cp._attack_textures.at('R')});

    this->_ort = cp._ort;
    this->_sprite.setTexture(*_ort_textures[_ort]);

    this->_maxHP = cp._maxHP;
    this->_hp = cp._hp;

    this->_alive = cp._alive;

    _posX = -1; _posY = -1; // hors carte tant que pas place - on ne met pas deux joueurs au mme endroit

    return *this;
}


Player::~Player() {
    _ort_textures.clear();
    _attack_textures.clear();
}


void Player::setWindowPosition(float x, float y){
    _sprite.setPosition(0.f, 0.f);
    _sprite.move(x, y);
}


void Player::render(sf::RenderWindow win, int x, int y) {
    float xoffset = RES*x; float yoffset = RES*y;
    setWindowPosition(xoffset, yoffset);
    win.draw(_sprite);
}


void Player::move(char dir) {
    switch (dir) {
        case 'U':
            turn(dir);
            if (_posX > 0) {
                _posX--;
                setWindowPosition(float(_posX*RES), float(_posY*RES));
            }

        case 'D':
            turn(dir);
            if (_posX < WIN_RES) {
                _posX++;
                setWindowPosition(float(_posX*RES), float(_posY*RES));
            }

        case 'L':
            turn(dir);
            if (_posY > 0) {
                _posY--;
                setWindowPosition(float(_posX*RES), float(_posY*RES));
            }

        case 'R':
            turn(dir);
            if (_posY < WIN_RES) {
                _posY++;
                setWindowPosition(float(_posX*RES), float(_posY*RES));
            }
    }
}

void Player::turn(char dir) {
    _ort = dir;
    _sprite.setTexture(*_ort_textures[dir]);
}

void Player::receiveDamage(int dmg) {
    _hp -= dmg;
    if (_hp < 0) {
        _alive = false;
        _hp = 0;
    }
}

void Player::heal(int hp) {
    _hp += hp;
    if (_hp > _maxHP)   _hp = _maxHP;
}

char Player::inRange(const Character& target) {

}

