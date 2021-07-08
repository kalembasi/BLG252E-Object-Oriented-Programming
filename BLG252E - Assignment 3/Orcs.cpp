// Ömer Malik KALEMBAŞI
//150180112

#include "Orcs.h"

using namespace std;

void Orcs::PerformAttack()
{
    if (firstEnemy->IsAlive() && secondEnemy->IsAlive())
    {
        if (firstEnemy->getName() == "Elves")
        {
            firstEnemy->ReceiveAttack(name, numberOfUnits * 0.7 * attackPoint);
            secondEnemy->ReceiveAttack(name, numberOfUnits * 0.3 * attackPoint);
            return;
        }
        secondEnemy->ReceiveAttack(name, numberOfUnits * 0.7 * attackPoint);
        firstEnemy->ReceiveAttack(name, numberOfUnits * 0.3 * attackPoint);
        return;
    }
    if (firstEnemy->IsAlive())
    {
        firstEnemy->ReceiveAttack(name, numberOfUnits * attackPoint);
    }
    else
    {
        secondEnemy->ReceiveAttack(name, numberOfUnits * attackPoint);
    }
}

void Orcs::ReceiveAttack(string name, int damage)
{
    if (name == "Elves")
    {
        damage = damage * 0.75;
        numberOfUnits -= damage / healthPoint;
        return;
    }
    damage = damage * 0.8;
    numberOfUnits -= damage / healthPoint;
}

int Orcs::PurchaseWeapons(int number)
{
    attackPoint += number * 2;
    return number * 20;
}

int Orcs::PurchaseArmors(int number)
{
    healthPoint += number * 3;
    return number;
}

void Orcs::Print()
{
    cout << "Stop running, you'll only die tired!" << endl;
    Faction::Print();
}