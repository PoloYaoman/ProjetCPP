#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <string>

using namespace std;

class Weapon {
private:

	string name;
	//Grade grade;
	HP hp;
	int degat;

public :

	//constructeur
	Weapon(String name, HP hp, int degat) : name(name) hp(hp) degat(degat){}



	const &int getDegat const() { return degat; }
	int& setHp(int newHp){ hp = newHp; }
	virtual void attaque(Personnage perso) const = 0;
	// const &Grade getGrade() const{ return grade;}
	const& HP getHp() const { return HP; }
	string getName() const{ return name; }



};
#endif 