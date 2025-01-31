#ifndef MOVE_H
#define MOVE_H

#include <string>
#include <iostream>
#include "Type.h"
using namespace std;

class Pokemon; //behövs för perform()

/*
* Klassen ska innehålla ett namn, en Type och en power som är en int. 
* Alla ska vara icke-muterbara. Om power är negativ ska ett exception kastas 
* under initiering.
* 
* Klassen är abstrakt.
*/

class Move{
private:
    // Ska vara rent virtuell, och därefter implementeras av PhysicalMove och SpecialMove.
    virtual int execute(Pokemon* attacker, Pokemon* defender) const = 0;
protected:
public:
    string name;
    Type type;
    int power;

    // Klassens konstruktor. Den ska initiera klassen.
    // Om power är negativ ska exception kastas.
    Move(const string& name, const Type type, const int power);


    // Move() {} //finns endast för kompilering, kan tas bort senare.

    // Funktionen ska ta 2 Pokemon-pekare som argument, en som är en 
    // attackerare och en försvarare.
    // 
    // Funktionen ska skriva ut till konsollen vilken Pokemon som använder vilken Move. 
    // 
    // Efter det ska den kalla på execute(). execute() ska dock endast kallas 
    // om antingen den attackerandes eller den försvarandes health inte är 0.
    // 
    // Ifall den inte körs, så ska ett meddelande skrivas ut som beskriver situationen.
    // (titta i main.cpp för utskrift).
    // 
    // Ifall den körs, och om försvararens health är 0, ska det skrivas ut att 
    // den har "fainted".
    // 
    void perform(Pokemon* attacker, Pokemon* defender) const;
};

#endif