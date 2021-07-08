//  Name:   Ö. Malik Kalembaşı
//  ID  :   150180112

#include "Person.h"

using namespace std;

Person::Person(string name, string surname)
{
    this->name = name;
    this->surname = surname;
}

string Person::getName() { return this->name; }
string Person::getSurname() { return this->surname; }

bool Passenger::buyTicket(int price)
{
    if (this->cash >= price)
    {
        this->ticket = true;
    }
    return this->ticket;
}

bool Passenger::getTicket() { return this->ticket; }

void Astronaut::completeMission()
{
    this->numMissions++;
}

int Astronaut::getNumMissions() { return this->numMissions; }