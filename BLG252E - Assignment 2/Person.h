//  Name:   Ö. Malik Kalembaşı
//  ID  :   150180112

#pragma once

#include <iostream>

using namespace std;

class Person
{
    string name, surname;

public:
    Person(string name, string surname);
    string getName();
    string getSurname();
};

class Passenger : public Person
{
    int cash;
    bool ticket;

public:
    Passenger(string name, string surname, int cash = 0) : Person(name, surname)
    {
        this->cash = cash;
        this->ticket = false;
    }
    bool buyTicket(int price);
    bool getTicket();
};

class Astronaut : public Person
{
    int numMissions;

public:
    Astronaut(string name, string surname, int numMissions = 0) : Person(name, surname)
    {
        if (numMissions < 0)
        {
            cout << "Number of missions that astronaut completed can't be negative. It is set to 0." << endl;
            this->numMissions = 0;
        }
        else
        {
            this->numMissions = numMissions;
        }
    }
    void completeMission();
    int getNumMissions();
};