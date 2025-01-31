#pragma once

#include <string>
#include "Pokemon.h"

/*
* Klassen representerar Pokemon som har tv� typer ist�llet f�r en.
* 
* Klassen �rver fr�n Pokemon-klassen. Ut�ver det s� ska det ha en const Type 
* som representerar dess andra typ.
*/

class DualTypePokemon : public Pokemon {
private:
    const Type type2;
protected:
public:

    // Klassens konstruktor. Den ska initiera klassen.
    DualTypePokemon(const string name, const Type type1, const Type type2, const Move* move1, const Move* move2, const Move* move3, const Move* move4, int health, const int attack, const int spAttack, const int defense, const int spDefense, const int speed, const Move* (*stratPtr)(const Pokemon* p1, const Pokemon* p2));

    // Ska fungera p� samma s�tt som originalet, f�rutom att logiken ska vara 
    // Multiplier = Multiplier1 * Multiplier2, d�r Multiplier1 �r "damage multiplier" 
    // f�r f�rsta typen och Multiplier2 �r f�r den andra typen.
    // 
    //calculateDamageMultiplier();
    double calculateDamageMultiplier(Type attackMove) override;
};