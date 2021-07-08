// Ömer Malik KALEMBAŞI
//150180112

#include "Faction.h"

using namespace std;

Faction::Faction()
{
     name = "";
     numberOfUnits = -1;
     attackPoint = -1;
     healthPoint = -1;
     unit_regeneration_number = -1;
     firstEnemy = NULL;
     secondEnemy = NULL;
     isAlive = true;
     totalHealth = -1;
}

Faction::Faction(string n, int a, int b, int c, int d)
{
     name = n;
     numberOfUnits = a;
     attackPoint = b;
     healthPoint = c;
     unit_regeneration_number = d;
     firstEnemy = NULL;
     secondEnemy = NULL;
     isAlive = true;
     totalHealth = a * c;
}

void Faction::AssignEnemies(Faction *f, Faction *s)
{
     firstEnemy = f;
     secondEnemy = s;
}

void Faction::Print()
{
     cout << "Faction name:"
          << "\t\t" << name << endl;
     if (isAlive)
     {
          cout << "Status:"
               << "\t\t\t"
               << "Alive" << endl;
     }
     else
     {
          cout << "Status:"
               << "\t\t\t"
               << "Defeated" << endl;
     }

     cout << "Number of Units:"
          << "\t" << numberOfUnits << endl;
     cout << "Attack Point:"
          << "\t\t" << attackPoint << endl;
     cout << "Health Point:"
          << "\t\t" << healthPoint << endl;
     cout << "Unit Regen Number:"
          << "\t" << unit_regeneration_number << endl;
     cout << "Total Faction Health:"
          << "\t" << numberOfUnits * healthPoint << endl;
}

void Faction::EndTurn()
{
     if (numberOfUnits <= 0)
     {
          numberOfUnits = 0;
          isAlive = false;
          return;
     }
     numberOfUnits += unit_regeneration_number;
}