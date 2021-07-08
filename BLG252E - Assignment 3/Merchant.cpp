// Ömer Malik KALEMBAŞI
//150180112

#include "Merchant.h"

using namespace std;

Merchant::Merchant(int weapon, int armor)
{
    starting_weapon_point = weapon;
    starting_armor_point = armor;
    revenue = 0;
    weaponPoint = weapon;
    armorPoint = armor;
    firstFaction = NULL;
    secondFaction = NULL;
    thirdFaction = NULL;
}

void Merchant::AssignFactions(Faction *faction1, Faction *faction2, Faction *faction3)
{
    firstFaction = faction1;
    secondFaction = faction2;
    thirdFaction = faction3;
}

bool Merchant::SellWeapons(string name, int amount)
{
    if (firstFaction->getName() == name)
    {
        if (!firstFaction->IsAlive())
        {
            cout << "The faction you want to sell weapons is dead!" << endl;
            return false;
        }
        if (amount > weaponPoint)
        {
            cout << "You try to sell more weapons than you have in possession." << endl;
            return false;
        }
        weaponPoint -= amount;
        revenue += firstFaction->PurchaseWeapons(amount);
        cout << "Weapons sold!" << endl;
        return true;
    }
    if (secondFaction->getName() == name)
    {
        if (!secondFaction->IsAlive())
        {
            cout << "The faction you want to sell weapons is dead !" << endl;
            return false;
        }
        if (amount > weaponPoint)
        {
            cout << "You try to sell more weapons than you have in possession." << endl;
            return false;
        }
        weaponPoint -= amount;
        revenue += secondFaction->PurchaseWeapons(amount);
        cout << "Weapons sold!" << endl;
        return true;
    }
    if (thirdFaction->getName() == name)
    {
        if (!thirdFaction->IsAlive())
        {
            cout << "The faction you want to sell weapons is dead !" << endl;
            return false;
        }
        if (amount > weaponPoint)
        {
            cout << "You try to sell more weapons than you have in possession." << endl;
            return false;
        }
        weaponPoint -= amount;
        revenue += thirdFaction->PurchaseWeapons(amount);
        cout << "Weapons sold!" << endl;
        return true;
    }
    return false;
}

bool Merchant::SellArmors(string name, int amount)
{
    if (firstFaction->getName() == name)
    {
        if (!firstFaction->IsAlive())
        {
            cout << "The faction you want to sell armors is dead !" << endl;
            return false;
        }
        if (amount > armorPoint)
        {
            cout << "You try to sell more armors than you have in possession." << endl;
            return false;
        }
        armorPoint -= amount;
        revenue += firstFaction->PurchaseArmors(amount);
        cout << "Armors sold!" << endl;
        return true;
    }
    if (secondFaction->getName() == name)
    {
        if (!secondFaction->IsAlive())
        {
            cout << "The faction you want to sell armors is dead !" << endl;
            return false;
        }
        if (amount > armorPoint)
        {
            cout << "You try to sell more armors than you have in possession." << endl;
            return false;
        }
        armorPoint -= amount;
        revenue += secondFaction->PurchaseArmors(amount);
        cout << "Armors sold!" << endl;
        return true;
    }
    if (thirdFaction->getName() == name)
    {
        if (!thirdFaction->IsAlive())
        {
            cout << "The faction you want to sell armors is dead !" << endl;
            return false;
        }
        if (amount > armorPoint)
        {
            cout << "You try to sell more armors than you have in possession." << endl;
            return false;
        }
        armorPoint -= amount;
        revenue += secondFaction->PurchaseArmors(amount);
        cout << "Armors sold!" << endl;
        return true;
    }
    return false;
}

void Merchant::EndTurn()
{
    weaponPoint = starting_weapon_point;
    armorPoint = starting_armor_point;
}
