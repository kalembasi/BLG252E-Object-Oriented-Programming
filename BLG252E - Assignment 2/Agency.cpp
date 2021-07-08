//  Name:   Ö. Malik Kalembaşı
//  ID  :   150180112

#include "Agency.h"

using namespace std;

Agency::Agency(string name, int cash, int ticketPrice)
{
    this->name = name;
    this->cash = cash;
    if (ticketPrice < 0)
    {
        cout << "Ticket price can't be negative. It is set to 0." << endl;
        this->ticketPrice = 0;
    }
    else
    {
        this->ticketPrice = ticketPrice;
    }
    this->compeletedMissions = NULL;
    this->nextMissions = NULL;
    this->countNext = 0;
    this->countComplete = 0;
}

void Agency::addMission(Mission newMission)
{
    if (this->countNext == 0)
    {
        this->countNext++;
        this->nextMissions = new Mission *[1];
        this->nextMissions[0] = new Mission(newMission.getName(), newMission.getCost(), newMission.getFaultProbability(), newMission.getASize(), newMission.getPSize(), newMission.getCrew());
        this->nextMissions[0]->setMissionNumber(this->countNext);
    }
    else
    {
        this->countNext++;
        Mission **temp = new Mission *[this->countNext];
        for (int i = 0; i < this->countNext; i++)
        {
            temp[i] = this->nextMissions[i];
        }
        temp[countNext - 1] = new Mission(newMission.getName(), newMission.getCost(), newMission.getFaultProbability(), newMission.getASize(), newMission.getPSize(), newMission.getCrew());
        temp[countNext - 1]->setMissionNumber(countNext);
        this->nextMissions = temp;
    }
}

void Agency::executeNextMission()
{
    if (this->nextMissions == NULL)
    {
        cout << "No available mission to execute!" << endl;
        return;
    }
    bool result = this->nextMissions[0]->executeMission();
    if (result)
    {
        this->cash += this->nextMissions[0]->calculateProfit(this->ticketPrice);
        cout << "MISSION " << this->nextMissions[0]->getName() << " SUCCESSFUL!" << endl;
        Astronaut *iter;
        Mission *temp;
        temp = this->nextMissions[0];
        for (int i = 0; i < temp->getASize(); i++)
        {
            iter = temp->getCrew()[i];
            iter->completeMission();
            cout << "Astronaut " << iter->getName() << " " << iter->getSurname() << " successfully completed " << iter->getNumMissions() << " missions." << endl;
        }
        this->countNext--;
        Mission **tempo = new Mission *[this->countNext];
        for (int i = 0; i < countNext; i++)
        {
            tempo[i] = this->nextMissions[i + 1];
        }
        this->nextMissions = tempo;

        if (this->compeletedMissions == NULL)
        {
            this->compeletedMissions = new Mission *[1];
            this->compeletedMissions[0] = temp;
            this->countComplete++;
        }
        else
        {
            Mission **trav = new Mission *[countComplete + 1];
            for (int i = 0; i < countComplete; i++)
            {
                trav[i] = this->compeletedMissions[i];
            }
            trav[countComplete] = temp;
            this->compeletedMissions = trav;
            this->countComplete++;
        }
    }
    else
    {
        this->cash += this->nextMissions[0]->calculateProfit(this->ticketPrice);
        cout << "MISSION " << this->nextMissions[0]->getName() << " FAILED!" << endl;
        cout << "Agency reschedules the mission." << endl;
    }
    return;
}

ostream &operator<<(ostream &output, Agency &obj)
{
    output << "Agency name: " << obj.name << ", Total cash: " << obj.cash << ", Ticket Price: " << obj.ticketPrice << endl;
    output << "Next Missions:" << endl;
    if (obj.getCountNext() == 0)
    {
        output << "No missions available." << endl;
    }
    else
    {
        Mission **iter = obj.nextMissions;
        for (int i = 0; i < obj.getCountNext(); i++)
        {
            output << "Mission number: " << iter[i]->getMissionNumber() << " Mission name: " << iter[i]->getName() << " Cost: " << iter[i]->getCost() << endl;
        }
    }
    output << "Completed Missions:" << endl;
    if (obj.compeletedMissions == NULL)
    {
        output << "No missions completed before." << endl;
    }
    else
    {
        Mission **iter = obj.compeletedMissions;
        for (int i = 0; i < obj.getCountComplete(); i++)
        {
            output << "Mission number: " << iter[i]->getMissionNumber() << " Mission name: " << iter[i]->getName() << " Cost: " << iter[i]->getCost() << endl;
        }
    }
    return output;
}

Agency::~Agency()
{
    for (int i = 0; i < countNext; i++)
    {
        if (this->nextMissions[i] != NULL)
        {
            delete this->nextMissions[i];
        }
    }
    for (int i = 0; i < countComplete; i++)
    {
        if (this->compeletedMissions[i] != NULL)
        {
            delete this->compeletedMissions[i];
        }
    }
}