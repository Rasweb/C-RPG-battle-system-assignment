#ifndef BATTLE_H
#define BATTLE_H
#include "Pokemon.h"
#include "vector"
using namespace std;


//--Battle:
//Skapa en ny klass med detta namn.Klassen ska innehålla
//två samlingar av Pokemonpekare, vilket representerar varsitt
//lag.Konstruktorn ska vara tom och inte ta några argument.
//
//Funktionerna addTeamA(Pokemon*) och addTeamB(Pokemon*) lägger
//till en Pokemon till respektive lag, och därefter returnera
//en Battle - referens.I klassens destruktor ska den köra delete
//på alla lagrade Pokemon.

class Battle {
private:
	vector<Pokemon*> teamA;
	vector<Pokemon*> teamB;
	string checkIfNewPokemon(string lastP, string currP, char teamChar);
	void checkWinner(int sizeA, int sizeB);
public:
	Battle();
	Battle& addTeamA(Pokemon* p);
	Battle& addTeamB(Pokemon* p);
	void start();
	~Battle();
};
#endif


