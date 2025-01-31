#include "PhysicalMove.h"
#include "Pokemon.h"

PhysicalMove::PhysicalMove(const string& name, const Type type, const int power)
	: Move(name, type, power)
{
}

int PhysicalMove::execute(Pokemon* attacker, Pokemon* defender) const {
	float multiplier = defender->calculateDamageMultiplier(this->type);

	if (multiplier == 0) {
		cout << "It doesn't affect " << defender->name << endl;
		return 0;
	}
	if (multiplier < 1 && multiplier != 0) {
		cout << "It's not very effective.." << endl;
	}
	if (multiplier > 1) {
		cout << "It's super effective!" << endl;
	}

	return (((power * multiplier) + attacker->attack) / defender->defence) + 5;

}