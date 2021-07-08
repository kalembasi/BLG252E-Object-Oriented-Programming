//  Name:   Ö. Malik Kalembaşı
//  ID  :   150180112

#pragma once

#include <iostream>
#include "Person.h"
using namespace std;

class Mission
{
    string name;
    int missionNumber, cost, faultProbability;
    bool completed;
    int a, p;
    Astronaut **crew;
    Passenger **passenger;
    static int numMissions;

public:
    Mission(string name, int cost, int fault, int a = 0, int p = 0, Astronaut **crew = NULL, Passenger **passenger = NULL)
    {
        int l = name.length();
        if (l == 5 && (name[0] >= 'A' && name[0] <= 'Z') && (name[1] >= 'A' && name[1] <= 'Z') && (name[2] >= '-') && (name[3] >= '0' && name[3] <= '9') && (name[4] >= '0' && name[4] <= '9'))
        {
            this->name = name;
        }
        else
        {
            cout << "Given name does not satisfy the mission naming convention. Please set a new name!" << endl;
            this->name = "AA-00";
        }
        this->missionNumber = 0;
        this->cost = cost;
        this->faultProbability = fault;
        this->completed = false;
        this->a = a;
        this->p = p;
        if (crew != NULL)
        {
            this->crew = new Astronaut *[a];
            for (int i = 0; i < a; i++)
            {
                this->crew[i] = new Astronaut(crew[i]->getName(), crew[i]->getSurname(), crew[i]->getNumMissions());
            }
        }
        else
        {
            this->crew = NULL;
        }
        if (passenger != NULL)
        {
            this->passenger = new Passenger *[p];
            for (int i = 0; i < p; i++)
            {
                this->passenger[i] = new Passenger(passenger[i]->getName(), passenger[i]->getSurname());
            }
        }
        else
        {
            this->passenger = NULL;
        }
    }
    void operator+=(Passenger *psg);
    void operator+=(Astronaut *a);
    bool executeMission();
    int calculateProfit(int price);
    string getName() { return this->name; }
    void setName(string newName) { this->name = newName; }
    void setMissionNumber(int n) { this->missionNumber = n; }
    int getMissionNumber() { return this->missionNumber; }
    int getCost() { return this->cost; }
    bool gettt() { return this->completed; }
    int getFaultProbability() { return this->faultProbability; }
    int getASize() { return this->a; }
    int getPSize() { return this->p; }
    Astronaut **getCrew() { return this->crew; }
    Passenger **getPassenger() { return this->passenger; }
};