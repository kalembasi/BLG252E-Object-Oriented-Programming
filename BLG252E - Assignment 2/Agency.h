//  Name:   Ö. Malik Kalembaşı
//  ID  :   150180112

#pragma once

#include <iostream>
#include "Mission.h"
using namespace std;

class Agency
{
    string name;
    int cash, ticketPrice;
    int countNext, countComplete;
    Mission **compeletedMissions;
    Mission **nextMissions;

public:
    Agency(string name, int cash, int ticketPrice);
    int getCountNext() { return countNext; }
    int getCountComplete() { return countComplete; }
    int getTicketPrice() { return ticketPrice; }
    void setTicketPrice(int newPrice) { this->ticketPrice = newPrice; }
    void addMission(Mission newMission);
    void executeNextMission();
    friend ostream &operator<<(ostream &output, Agency &obj);
    ~Agency();
};