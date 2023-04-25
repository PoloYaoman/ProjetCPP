#include "TexturesLib.hpp"

// Initialisation de l'attribut statique 
map<string, sf::Texture*> TexturesLib::_textures = *(new map<string, sf::Texture*>());

/* Charge une texture dans la map si elle est pas deja dedans et renvoie la texture 
demandee*/
sf::Texture* TexturesLib::assignTexture (string filename) {
    if (_textures.count(filename) == 0) {
        _textures.insert({filename, new sf::Texture});
        if (!_textures[filename]->loadFromFile(filename))    //charger le fichier
            throw runtime_error("Couldn't load texture from file " + filename);
    }

    return _textures[filename];
}