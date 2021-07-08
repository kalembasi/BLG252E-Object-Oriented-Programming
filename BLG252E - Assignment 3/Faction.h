// Ömer Malik KALEMBAŞI
//150180112

#pragma once

#include <iostream>

using namespace std;

class Faction
{
protected:
    string name;
    Faction *firstEnemy;
    Faction *secondEnemy;
    int numberOfUnits, attackPoint, healthPoint, unit_regeneration_number, totalHealth;
    bool isAlive;

public:
    Faction();
    Faction(string name, int a, int b, int c, int d);
    void AssignEnemies(Faction *enemy1, Faction *enemy2);
    virtual void PerformAttack() = 0;
    virtual void ReceiveAttack(string name, int damage) = 0;
    virtual int PurchaseWeapons(int number) = 0;
    virtual int PurchaseArmors(int number) = 0;
    virtual void Print();
    void EndTurn();
    bool IsAlive() { return isAlive; }
    string getName() { return name; }
};