#ifndef ARMOR
#define ARMOR
#include <string>
using namespace std;


class Armor {

private:
	HP hp;
	string name;
	//Grade grade;
	enumType type;// type de l'armure , pantalon , casque... 

public:

	Armor(String name,HP hp, Grade grade, const enumtype type) : name(name) hp(hp) grade(grade) type(type){}
	void baisserHp(int n) { this->hp = this->baisserHp - n; }
	//const& Grade getGrade() const { return grade; }

};

#endif // !ARMOR
