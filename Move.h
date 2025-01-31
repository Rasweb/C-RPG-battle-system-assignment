#ifndef MOVE_H
#define MOVE_H

#include <string>
#include <iostream>
#include "Type.h"
using namespace std;

class Pokemon; //beh�vs f�r perform()

/*
* Klassen ska inneh�lla ett namn, en Type och en power som �r en int. 
* Alla ska vara icke-muterbara. Om power �r negativ ska ett exception kastas 
* under initiering.
* 
* Klassen �r abstrakt.
*/

class Move{
private:
    // Ska vara rent virtuell, och d�refter implementeras av PhysicalMove och SpecialMove.
    virtual int execute(Pokemon* attacker, Pokemon* defender) const = 0;
protected:
public:
    string name;
    Type type;
    int power;

    // Klassens konstruktor. Den ska initiera klassen.
    // Om power �r negativ ska exception kastas.
    Move(const string& name, const Type type, const int power);


    // Move() {} //finns endast f�r kompilering, kan tas bort senare.

    // Funktionen ska ta 2 Pokemon-pekare som argument, en som �r en 
    // attackerare och en f�rsvarare.
    // 
    // Funktionen ska skriva ut till konsollen vilken Pokemon som anv�nder vilken Move. 
    // 
    // Efter det ska den kalla p� execute(). execute() ska dock endast kallas 
    // om antingen den attackerandes eller den f�rsvarandes health inte �r 0.
    // 
    // Ifall den inte k�rs, s� ska ett meddelande skrivas ut som beskriver situationen.
    // (titta i main.cpp f�r utskrift).
    // 
    // Ifall den k�rs, och om f�rsvararens health �r 0, ska det skrivas ut att 
    // den har "fainted".
    // 
    void perform(Pokemon* attacker, Pokemon* defender) const;
};

#endif