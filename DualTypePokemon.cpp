#include "DualTypePokemon.h"
#include "Move.h"

DualTypePokemon::DualTypePokemon(const string name, const Type type1, const Type type2, const Move* move1, const Move* move2, const Move* move3, const Move* move4, int health, const int attack, const int spAttack, const int defense, const int spDefense, const int speed, const Move* (*stratPtr)(const Pokemon* p1, const Pokemon* p2))
    : Pokemon(name, type1, move1, move2, move3, move4, health, attack, spAttack, defense, spDefense, speed, stratPtr), type2(type2)
{
	bool if_Bad_Attack(attack < 1);
    bool if_Bad_Health(health < 1);
    bool if_Bad_SpAttack(spAttack < 1);
    bool if_Bad_Defense(defense < 1);
    bool if_Bad_SpDefense(spDefense < 1);

    if (if_Bad_Attack || if_Bad_Health || if_Bad_SpAttack || if_Bad_Defense || if_Bad_SpDefense) {
        throw "Cant be below zero";
    }
}

double DualTypePokemon::calculateDamageMultiplier(Type attackMove) {

    double multiplier1 = TypeChart::getDamageMultiplier(attackMove, this->type);
    double multiplier2 = TypeChart::getDamageMultiplier(attackMove, this->type2);

    return multiplier1 * multiplier2;
}
