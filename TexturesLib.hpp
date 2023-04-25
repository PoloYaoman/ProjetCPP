#ifndef TEXTURESLIB_HPP
#define TEXTURESLIB_HPP

#include <SFML/Graphics.hpp>

using namespace std;

class TexturesLib {
    private:
        //bibliotheque des textures classee par nom du fichier
        static map<string, sf::Texture*> _textures; 

    public:
        /* Accesseurs */
        const bool addTexture(string filename, sf::Texture* texture);

        static sf::Texture* assignTexture (string filename);
};

#endif