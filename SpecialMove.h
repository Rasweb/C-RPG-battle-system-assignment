#pragma once

#include <string>
#include "Move.h"

class SpecialMove : public Move {
private:
protected:
public:

    //Klassens konstruktor. Den ska initiera klassen.
    SpecialMove(const string& name, const Type type, const int power);
    // Exakt som i PhysicalMove, förutom att denna ska använda sig av 
    // specialDefence och specialAttack istället för attack och defence.
    // 
    //execute() override
    int execute(Pokemon* attacker, Pokemon* defender) const override;

};
