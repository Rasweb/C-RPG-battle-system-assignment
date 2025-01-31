#ifndef POKEMONBUILDER_H
#define POKEMONBUILDER_H
#include <vector>
#include "Type.h"
#include "Move.h"
#include "Pokemon.h"
using namespace std;

// https://www.sandordargo.com/blog/2022/04/27/the-4-use-of-using-in-cpp 
using StrategyFunction = const Move* (*)(const Pokemon*, const Pokemon*);
// 
//return_type(*FuncPtr) (parameter type, ....);
//


class PokemonBuilder {
private:
	string name;
	vector<Type> typeVector;
	vector<const Move*> moveVector;
	int health;
	int attack;
	int spAttack;
	int defense;
	int spDefense; 
	int speed;
public:
	StrategyFunction strategy = NULL;
	PokemonBuilder();
	PokemonBuilder& setName(string incN);
	PokemonBuilder& addType(Type incT);
	PokemonBuilder& addMove(Move* incM);
	PokemonBuilder& setHealth(int incH);
	PokemonBuilder& setAttack(int incA);
	PokemonBuilder& setSpecialAttack(int incSA);
	PokemonBuilder& setDefense(int incD);
	PokemonBuilder& setSpecialDefense(int incSD);
	PokemonBuilder& setSpeed(int incS);
	PokemonBuilder& setStrategy(StrategyFunction incStrat);
	Pokemon* build();
};

#endif
