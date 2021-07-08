// Ömer Malik KALEMBAŞI
//150180112

#pragma once

#include <iostream>
#include "Faction.h"

using namespace std;

class Dwarves : public Faction
{
public:
    Dwarves(string name, int a, int b, int c, int d) : Faction(name, a, b, c, d) {}
    void PerformAttack();
    void ReceiveAttack(string name, int damage);
    int PurchaseWeapons(int number);
    int PurchaseArmors(int number);
    void Print();
};