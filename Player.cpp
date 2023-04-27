#include "Player.hpp"
#include "TexturesLib.hpp"

Player::Player(string texture_file_down, int maxHP = MAXHP) {
    _ort_textures.insert({'D', TexturesLib::assignTexture(texture_file_down)});

    _sprite.setTexture(*_ort_textures['D']);

    _maxHP = maxHP;
    _hp = maxHP;

    _posX = -1; _posY = -1; // hors carte tant que pas place 
    _ort = 'D';
}

Player::Player(string texture_file_up, string texture_file_down, string texture_file_left, 
            string texture_file_right, string attack_file_up, string attack_file_down, 
            string attack_file_left, string attack_file_right, int maxHP = MAXHP) {
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

    _posX = -1; _posY = -1; // hors carte tant que pas place - on ne met pas deux joueurs au mme endroit

    return *this;
}


