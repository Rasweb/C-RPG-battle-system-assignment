#pragma once

#include <string>
#include "Move.h"

class PhysicalMove : public Move {
private:
protected:
public:
	//Klassens konstruktor. Den ska initiera klassen.
	PhysicalMove(const string& name, const Type type, const int power);
	/*execute() ska räkna ut hur mycket skada denna Move ska
	göra på försvarande Pokemon. Du bestämmer själv exakt vilken formel
	funktionen ska använda sig av, så länge du kan motivera din design
	och så länge följande variabler används (men samma formel för SpecialMove):

	power, attackersAttack, defendersDefence, multiplier

	PhysicalMove-klassen ska använda sig utav attack och defence,
	medans SpecialMove ska använda sig av specialAttack och
	specialDefence. Funktionen ska skriva ut:

	"It doesn't affect {försvarandePokemon}."
	om multiplier är 0,

	"It's not very effective..."
	om multiplier är under 1 men inte 0,

	"It's super effective!"
	om multiplier är över 1.*/
	//execute() override
	int execute(Pokemon* attacker, Pokemon* defender) const override;

};