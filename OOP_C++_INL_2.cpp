#include "PhysicalMove.h"
#include "SpecialMove.h"
#include "DualTypePokemon.h"
#include "PokemonBuilder.h"
#include "Battle.h"
#include "Type.h"

// VG-del. Kommentera in denna kod och kommentera ut den gamla main
// ifall ni vill arbeta för VG.

//I main.cpp sitter i dess VG - del tre funktioner,
//simpleStrategy(), myStrategy(), och optimalStrategy().De
//returnerar en Move* baserat på olika faktorer i spelet.
//
//simpleStrategy() är redan implementerad och ska inte ändras.
//
//playerStrategy() ska du implementera, som visar användaren
//vilka Moves det finns att välja imellan och frågar efter
//vilken som ska användas.
//(Detta är igentligen ett dåligt sätt att implementera
//	spelarinteraktion på, men det fungerar för tillfället)
//
//	optimalStrategy() ska returnera det Move som gör mest skada
//	på motståndaren.

const Move* simpleStrategy(const Pokemon* attacker, const Pokemon* defender) {
	return attacker->move1; //färdig
}

const Move* playerStrategy(const Pokemon* attacker, const Pokemon* defender) {
	const Move* s[4] = { attacker->move1, attacker->move2, attacker->move3, attacker->move4 };
	int choice;

	cout << "\n" << "Current available moves" << endl;

	for (int i = 0; i < 4; i++)
	{
		cout << i << ": " << s[i]->name << endl;
	}

	cout << "Choose one of the moves for: " << attacker->name << endl;
	cin >> choice;

	if (choice >= 0 && choice <= 4) {
		return s[choice];
	}
	else {
		cout << "Not a valid option, choosing choice: " << s[0]->name << endl;
		return s[0];
	}
}

const Move* optimalStrategy(const Pokemon* attacker, const Pokemon* defender) {
	float multiplierMove1 = TypeChart::getDamageMultiplier(attacker->move1->type, defender->type);
	float multiplierMove2 = TypeChart::getDamageMultiplier(attacker->move2->type, defender->type);
	float multiplierMove3 = TypeChart::getDamageMultiplier(attacker->move3->type, defender->type);
	float multiplierMove4 = TypeChart::getDamageMultiplier(attacker->move4->type, defender->type);

	const Move* move1 = attacker->move1;
	const Move* move2 = attacker->move2;
	const Move* move3 = attacker->move3;
	const Move* move4 = attacker->move4;

	int move1TotDamage = attacker->move1->power * multiplierMove1;
	int move2TotDamage = attacker->move2->power * multiplierMove2;
	int move3TotDamage = attacker->move3->power * multiplierMove3;
	int move4TotDamage = attacker->move4->power * multiplierMove4;

	const Move* highestDamageMove = move1;
	int highestDamage = move1TotDamage;

	if (move2TotDamage > highestDamage) {
		highestDamage = move2TotDamage;
		highestDamageMove = move2;
	}
	if (move3TotDamage > highestDamage) {
		highestDamage = move3TotDamage;
		highestDamageMove = attacker->move3;
	}
	if (move4TotDamage > highestDamage) {
		highestDamage = move4TotDamage;
		highestDamageMove = attacker->move4;
	}
	return highestDamageMove;
}

void main() {
	srand(time(0));
	PhysicalMove quickAttack("Quick Attack", NORMAL, 70);
	SpecialMove swift("Swift", NORMAL, 60);
	PhysicalMove ironTail("Iron Tail", STEEL, 100);
	SpecialMove thunder("Thunder", ELECTRIC, 110);
	SpecialMove shadowBall("Shadow Ball", GHOST, 80);
	PhysicalMove payback("Payback", DARK, 50);
	PhysicalMove earthquake("Earthquake", GROUND, 100);
	PhysicalMove dragonClaw("Dragon Claw", DRAGON, 80);
	SpecialMove inferno("Inferno", FIRE, 100);
	PhysicalMove fly("Fly", FLYING, 80);
	PhysicalMove crunch("Crunch", DARK, 80);
	PhysicalMove crossChop("Cross Chop", FIGHTING, 100);
	SpecialMove hyperBeam("Hyper Beam", NORMAL, 150);
	PhysicalMove rockTomb("Rock Tomb", ROCK, 60);
	SpecialMove dracoMeteor("Draco Meteor", DRAGON, 130);

	auto strategy1 = simpleStrategy;
	auto strategy2 = playerStrategy;
	auto strategy3 = optimalStrategy;

	Pokemon* pikachu = PokemonBuilder()
		.setName("Pikachu")
		.addType(ELECTRIC)
		.addMove(&quickAttack)
		.addMove(&swift)
		.addMove(&ironTail)
		.addMove(&thunder)
		.setHealth(30)
		.setAttack(90)
		.setSpecialAttack(90)
		.setDefense(70)
		.setSpecialDefense(60)
		.setSpeed(100)
		.setStrategy(strategy1)
		.build();

	Pokemon* gengar = PokemonBuilder()
		.setName("Gengar")
		.addType(POISON)
		.addType(GHOST)
		.addMove(&thunder)
		.addMove(&shadowBall)
		.addMove(&payback)
		.addMove(&earthquake)
		.setHealth(40)
		.setAttack(80)
		.setSpecialAttack(100)
		.setDefense(80)
		.setSpecialDefense(80)
		.setSpeed(40)
		.setStrategy(strategy2)
		.build();

	Pokemon* charizard = PokemonBuilder()
		.setName("Charizard")
		.addType(FIRE)
		.addType(FLYING)
		.addMove(&swift)
		.addMove(&dragonClaw)
		.addMove(&inferno)
		.addMove(&fly)
		.setHealth(50)
		.setAttack(80)
		.setSpecialAttack(100)
		.setDefense(80)
		.setSpecialDefense(80)
		.setSpeed(60)
		.setStrategy(strategy3)
		.build();

	Pokemon* raticate = PokemonBuilder()
		.setName("Raticate")
		.addType(NORMAL)
		.addMove(&quickAttack)
		.addMove(&swift)
		.addMove(&crunch)
		.addMove(&thunder)
		.setHealth(30)
		.setAttack(90)
		.setSpecialAttack(90)
		.setDefense(80)
		.setSpecialDefense(50)
		.setSpeed(90)
		.setStrategy(strategy1)
		.build();

	Pokemon* machamp = PokemonBuilder()
		.setName("Machamp")
		.addType(FIGHTING)
		.addMove(&inferno)
		.addMove(&crossChop)
		.addMove(&hyperBeam)
		.addMove(&rockTomb)
		.setHealth(40)
		.setAttack(100)
		.setSpecialAttack(80)
		.setDefense(80)
		.setSpecialDefense(80)
		.setSpeed(40)
		.setStrategy(strategy2)
		.build();

	Pokemon* dragonite = PokemonBuilder()
		.setName("Dragonite")
		.addType(DRAGON)
		.addType(FLYING)
		.addMove(&thunder)
		.addMove(&dracoMeteor)
		.addMove(&hyperBeam)
		.addMove(&fly)
		.setHealth(50)
		.setAttack(80)
		.setSpecialAttack(100)
		.setDefense(80)
		.setSpecialDefense(80)
		.setSpeed(60)
		.setStrategy(strategy3)
		.build();

	{
		Battle()
			.addTeamA(pikachu)
			.addTeamA(gengar)
			.addTeamA(charizard)
			.addTeamB(raticate)
			.addTeamB(machamp)
			.addTeamB(dragonite)
			.start();

		// The battle has started !
		// Team A sends out Pikachu
		// Team B sends out Raticate

		// Pikachu used Quick Attack
		// Raticate used Quick Attack

		//...

		// Team A is the winner !

	}

	//(alla pokemon ska ha blivit deletad av Battle-destruktorn)
	std::cout << (pikachu->attack) << std::endl;
	// 0
}




// G
//int main() {
//	PhysicalMove quickAttack("Quick Attack", NORMAL, 70);
//	SpecialMove swift("Swift", NORMAL, 60);
//	PhysicalMove ironTail("Iron Tail", STEEL, 100);
//	SpecialMove thunder("Thunder", ELECTRIC, 110);
//	SpecialMove shadowBall("Shadow Ball", GHOST, 80);
//	PhysicalMove payback("Payback", DARK, 50);
//	PhysicalMove earthquake("Earthquake", GROUND, 100);
//
//	Pokemon* pikachu = new Pokemon("Pikachu", ELECTRIC, &quickAttack, &swift, &ironTail, &thunder, 30, 90, 90, 60, 50);
//	Pokemon* gengar = new DualTypePokemon("Gengar", POISON, GHOST, &thunder, &shadowBall, &payback, &earthquake, 40, 80, 100, 80, 80);
//	
//	
//	//utskrifterna kan skiljas beroende på formel för damage.
//	pikachu->executeMove1(gengar);
//	// Pikachu used Quick Attack.
//	// It doesn't affect Gengar.
//	gengar->executeMove1(pikachu);
//	// Gengar used Thunder.
//	// It's not very effective...
//	pikachu->executeMove2(gengar);
//	// Pikachu used Swift.
//	// It doesn't affect Gengar.
//	gengar->executeMove2(pikachu);
//	// Gengar used Shadow Ball.
//	pikachu->executeMove3(gengar);
//	// Pikachu used Iron Tail.
//	gengar->executeMove3(pikachu);
//	// Gengar used Payback.
//	pikachu->executeMove4(gengar);
//	// Pikachu used Thunder.
//	gengar->executeMove4(pikachu);
//	// Gengar used Earthquake.
//	// It's super effective!
//	pikachu->executeMove3(gengar);
//	// Pikachu used Iron Tail.
//	gengar->executeMove4(pikachu);
//	// Gengar used Earthquake.
//	// It's super effective!
//	// Pikachu fainted.
//	pikachu->executeMove3(gengar);
//	// Pikachu is in a fainted state and can't move.
//	gengar->executeMove4(pikachu);
//	// Gengar cannot perform the move, Pikachu has already fainted.
//
//	//gengar->executeMove4(pikachu);
//	//gengar->executeMove4(pikachu);
//	//pikachu->executeMove3(gengar);
//	//gengar->executeMove4(pikachu);
//	//pikachu->executeMove3(gengar);
//	//gengar->executeMove4(pikachu);
//
//	//gengar->executeMove4(pikachu);
//
//
//
//
//	delete pikachu;
//	delete gengar;
//
//	return 0;
//}









