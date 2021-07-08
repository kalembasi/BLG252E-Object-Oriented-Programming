// Ömer Malik KALEMBAŞI
//150180112

#include "Elves.h"

using namespace std;

void Elves::PerformAttack()
{
    if (firstEnemy->IsAlive() && secondEnemy->IsAlive())
    {
        int sixty = numberOfUnits * 6 / 10;
        int fourty = numberOfUnits - sixty;
        if (firstEnemy->getName() == "Orcs")
        {
            firstEnemy->ReceiveAttack(name, sixty * attackPoint * 3 / 2);
            secondEnemy->ReceiveAttack(name, fourty * attackPoint);
            return;
        }
        secondEnemy->ReceiveAttack(name, sixty * attackPoint * 3 / 2);
        firstEnemy->ReceiveAttack(name, fourty * attackPoint);
        return;
    }
    if (firstEnemy->IsAlive())
    {
        if (firstEnemy->getName() == "Orcs")
        {
            firstEnemy->ReceiveAttack(name, numberOfUnits * attackPoint * 1.5);
        }
        else
        {
            firstEnemy->ReceiveAttack(name, numberOfUnits * attackPoint);
        }
    }
    else
    {
        if (secondEnemy->getName() == "Orcs")
        {
            secondEnemy->ReceiveAttack(name, numberOfUnits * attackPoint * 1.5);
        }
        else
        {
            secondEnemy->ReceiveAttack(name, numberOfUnits * attackPoint);
        }
    }
}

void Elves::ReceiveAttack(string name, int damage)
{
    if (name == "Orcs")
    {
        damage = damage * 1.25;
    }
    else
    {
        damage = damage * 0.75;
    }
    numberOfUnits -= damage / healthPoint;
}

int Elves::PurchaseWeapons(int number)
{
    attackPoint += number * 2;
    return number * 15;
}

int Elves::PurchaseArmors(int number)
{
    healthPoint += number * 4;
    return number * 5;
}

void Elves::Print()
{
    cout << "You cannot reach our elegance." << endl;
    Faction::Print();
}