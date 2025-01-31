#pragma once

#include <string>
#include "Move.h"

class PhysicalMove : public Move {
private:
protected:
public:
	//Klassens konstruktor. Den ska initiera klassen.
	PhysicalMove(const string& name, const Type type, const int power);
	/*execute() ska r�kna ut hur mycket skada denna Move ska
	g�ra p� f�rsvarande Pokemon. Du best�mmer sj�lv exakt vilken formel
	funktionen ska anv�nda sig av, s� l�nge du kan motivera din design
	och s� l�nge f�ljande variabler anv�nds (men samma formel f�r SpecialMove):

	power, attackersAttack, defendersDefence, multiplier

	PhysicalMove-klassen ska anv�nda sig utav attack och defence,
	medans SpecialMove ska anv�nda sig av specialAttack och
	specialDefence. Funktionen ska skriva ut:

	"It doesn't affect {f�rsvarandePokemon}."
	om multiplier �r 0,

	"It's not very effective..."
	om multiplier �r under 1 men inte 0,

	"It's super effective!"
	om multiplier �r �ver 1.*/
	//execute() override
	int execute(Pokemon* attacker, Pokemon* defender) const override;

};