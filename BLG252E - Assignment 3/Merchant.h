// Ömer Malik KALEMBAŞI
//150180112

#pragma once

#include <iostream>
#include "Faction.h"

using namespace std;

class Merchant
{
    Faction *firstFaction;
    Faction *secondFaction;
    Faction *thirdFaction;
    int starting_weapon_point, starting_armor_point, revenue, weaponPoint, armorPoint;

public:
    Merchant(int weapon, int armor);
    void AssignFactions(Faction *enemy1, Faction *enemy2, Faction *enemy3);
    bool SellWeapons(string name, int amount);
    bool SellArmors(string name, int amount);
    void EndTurn();
    int GetRevenue() { return revenue; }
    int GetWeaponPoints() { return weaponPoint; }
    int GetArmorPoints() { return armorPoint; }
};