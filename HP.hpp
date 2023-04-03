#ifndef HP_HPP
#define HP_HPP

#define AVG_MAX 100

class HP {
    private :
        int hp_total;   // Nombre total des points de vie autorises par personnage
        int hp_level;   // Niveau de points de vie actuel

        /* Pour calculer le degat en fonction de l'armure */
        //int calculateDamage();

    public:
        HP() : hp_total(AVG_MAX), hp_level(AVG_MAX) {};
        HP(int total) : hp_total(total) {};
        HP(int total, int level) : hp_total(total), hp_level(level) {};

        void set_hp_total(int total) { hp_total = total; }
        const int get_hp_level () const { return hp_level; }
        const int get_hp_total() const { return hp_total; }

        /* Enleve dmg points de vie du niveau actuel et renvoie true si le 
        personnage meurt et false sinon */
        bool takeDamage(int dmg);
        /* Ajoute hp points de vie au niveau actuel jusqu'a atteindre le 
        niveau total autorise */
        void heal(int hp);
};

#endif