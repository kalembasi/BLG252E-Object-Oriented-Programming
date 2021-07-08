// Ömer Malik KALEMBAŞI
//150180112

#include "Dwarves.h"

using namespace std;

void Dwarves::PerformAttack()
{
    if (firstEnemy->IsAlive() && secondEnemy->IsAlive())
    {
        firstEnemy->ReceiveAttack(name, numberOfUnits * attackPoint * 0.5);
        secondEnemy->ReceiveAttack(name, numberOfUnits * attackPoint * 0.5);
        return;
    }
    if (firstEnemy->IsAlive())
    {
        firstEnemy->ReceiveAttack(name, numberOfUnits * attackPoint);
        return;
    }
    secondEnemy->ReceiveAttack(name, numberOfUnits * attackPoint);
}
void Dwarves::ReceiveAttack(string name, int damage)
{
    numberOfUnits -= damage / healthPoint;
}

int Dwarves::PurchaseWeapons(int number)
{
    attackPoint += number;
    return number * 10;
}

int Dwarves::PurchaseArmors(int number)
{
    healthPoint += number * 2;
    return number * 3;
}

void Dwarves::Print()
{
    cout << "Taste the power of our axes!" << endl;
    Faction::Print();
}