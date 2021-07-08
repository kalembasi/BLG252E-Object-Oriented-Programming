// Ömer Malik KALEMBAŞI
//150180112

#pragma once

#include <iostream>
#include "Faction.h"

using namespace std;

class Orcs : public Faction
{
public:
    Orcs(string name, int a, int b, int c, int d) : Faction(name, a, b, c, d) {}
    void PerformAttack();
    void ReceiveAttack(string, int);
    int PurchaseWeapons(int);
    int PurchaseArmors(int);
    void Print();
};