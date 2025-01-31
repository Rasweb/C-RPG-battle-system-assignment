#ifndef BATTLE_H
#define BATTLE_H
#include "Pokemon.h"
#include "vector"
using namespace std;


//--Battle:
//Skapa en ny klass med detta namn.Klassen ska inneh�lla
//tv� samlingar av Pokemonpekare, vilket representerar varsitt
//lag.Konstruktorn ska vara tom och inte ta n�gra argument.
//
//Funktionerna addTeamA(Pokemon*) och addTeamB(Pokemon*) l�gger
//till en Pokemon till respektive lag, och d�refter returnera
//en Battle - referens.I klassens destruktor ska den k�ra delete
//p� alla lagrade Pokemon.

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


