#ifndef HP_HPP
#define HP_HPP

class HP {
    private :
        int hp_total;   // Nombre total des points de vie autorises par personnage
        int hp_level;   // Niveau de points de vie actuel

    public:
        void set_hp_total(int total) { hp_total = total; }
        int get_hp_level() { return hp_level; }
        int get_hp_total() { return hp_total; }

        /* Enleve dmg points de vie du niveau actuel et renvoie true si le 
        personnage meurt et false sinon */
        bool takeDamage(int dmg);
        /* Ajoute hp points de vie au niveau actuel jusqu'a atteindre le 
        niveau total autorise */
        void heal(int hp);
};

#endif