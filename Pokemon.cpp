#include "Pokemon.h"
#include "Move.h"

Pokemon::Pokemon(const string name, const Type type, const Move* move1, const Move* move2, const Move* move3, const Move* move4, int health, const int attack, const int spAttack, const int defense, const int spDefense, const int speed, const Move* (*stratPtr)(const Pokemon* p1, const Pokemon* p2))
	: move1(move1), move2(move2), move3(move3), move4(move4), type(type), name(name), attack(attack), health(health), specialAttack(spAttack), defence(defense), specialDefence(spDefense), speed(speed), stratPtr(stratPtr)
{
	bool if_Bad_Attack(attack < 1);
	bool if_Bad_Health(health < 1);
	bool if_Bad_SpAttack(spAttack < 1);
	bool if_Bad_Defense(defense < 1);
	bool if_Bad_SpDefense(spDefense < 1);
	bool if_Bad_Speed(speed < 1);

	if (if_Bad_Attack || if_Bad_Health || if_Bad_SpAttack || if_Bad_Defense || if_Bad_SpDefense || if_Bad_Speed) {
		throw "Cant be bellow zero";
	}
}

void Pokemon::executeMove1(Pokemon* target) {
	move1->perform(this, target);
};
void Pokemon::executeMove2(Pokemon* target) {
	move2->perform(this, target);
};
void Pokemon::executeMove3(Pokemon* target) {
	move3->perform(this, target);
};
void Pokemon::executeMove4(Pokemon* target) {
	move4->perform(this, target);
};
void Pokemon::reduceHealth(int damage) {
	health -= damage;
	if (health < 0) {
		health = 0;
	}
}

double Pokemon::calculateDamageMultiplier(Type attType) {
	return TypeChart::getDamageMultiplier(attType, this->type);
}

