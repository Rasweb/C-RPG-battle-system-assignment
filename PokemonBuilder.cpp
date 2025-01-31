#include "PokemonBuilder.h"

PokemonBuilder::PokemonBuilder() 
	: health(-1),attack(-1),spAttack(-1),defense(-1),spDefense(-1),speed(-1)
{};

PokemonBuilder& PokemonBuilder::setName(string incN) {
	name = incN;
	return *this;
};

PokemonBuilder& PokemonBuilder::addType(Type incT) {
	if (typeVector.size() >= 2) {
		throw "There can only be 2 types";
	}
	typeVector.push_back(incT);
	return *this;
};
PokemonBuilder& PokemonBuilder::addMove(Move* incM) {
	if (moveVector.size() >= 4) {
		throw "There can only be 4 Moves";
	}
	moveVector.push_back(incM);
	return *this;
};

PokemonBuilder& PokemonBuilder::setHealth(int incH) {
	health = incH;
	return *this;
};

PokemonBuilder& PokemonBuilder::setAttack(int incA) {
	attack = incA;
	return *this;
};

PokemonBuilder& PokemonBuilder::setSpecialAttack(int incSA) {
	spAttack = incSA;
	return *this;
};

PokemonBuilder& PokemonBuilder::setDefense(int incD) {
	defense = incD;
	return *this;
};

PokemonBuilder& PokemonBuilder::setSpecialDefense(int incSD) {
	spDefense = incSD;
	return *this;
};

PokemonBuilder& PokemonBuilder::setSpeed(int incS) {
	speed = incS;
	return *this;
};

PokemonBuilder& PokemonBuilder::setStrategy(StrategyFunction incStrat) {
	strategy = incStrat;
	return *this;
};

Pokemon* PokemonBuilder::build() {
	bool if_bad_type = (typeVector.size() < 1 || typeVector.size() > 2);
	bool if_bad_move = (moveVector.size() != 4);

	if (if_bad_type || if_bad_move) {
		throw "Error while building a new pokemon";
	}

	Pokemon* newPokemon = new Pokemon(name, typeVector[0], moveVector[0], moveVector[1], moveVector[2], moveVector[3], health, attack, spAttack, defense, spDefense, speed, strategy);
	//Pokemon* newPokemon = new Pokemon(name, typeVector, moveVector, health, attack, spAttack, defense, spDefense, speed, strategy);
	return newPokemon;
};
