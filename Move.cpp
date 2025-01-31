#include "Move.h"
#include "Pokemon.h"


Move::Move(const string& name, const Type type, const int power)
	: name(name), type(type), power(power)
{
	if (power < 0) {
		throw "Negative power";
	}
}

void Move::perform(Pokemon* attacker, Pokemon* defender) const {
	if (attacker->health != 0) {
		if (defender->health == 0) {
			cout << "\n" << attacker->name << " cannot perform the move, " << defender->name << " has already fainted" << endl;
		}
		else {
			cout << attacker->name << " used " << Move::name << endl;
			int damage = this->execute(attacker, defender);
			defender->reduceHealth(damage);
			if (defender->health == 0) {
				cout << "\n" << defender->name << " has fainted" << endl;
			}
		}
	}
	else {
		cout << "\n" << attacker->name << " is in a fainted state and can't move." << endl;
	}
};