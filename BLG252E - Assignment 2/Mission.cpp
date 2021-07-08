//  Name:   Ö. Malik Kalembaşı
//  ID  :   150180112

#include <cstdlib>
#include "Mission.h"

using namespace std;

void Mission::operator+=(Passenger *psg)
{
    if (psg->getTicket())
    {
        if (this->p == 0)
        {
            this->passenger = new Passenger *[1];
            this->passenger[0] = psg;
            this->p++;
            return;
        }
        Passenger **temp = new Passenger *[this->p + 1];
        for (int i = 0; i < this->p; i++)
        {
            temp[i] = this->passenger[i];
        }

        temp[p] = psg;

        this->passenger = temp;
        this->p++;
    }
    else
    {
        cout << "Passenger " << psg->getName() << " " << psg->getSurname() << " does not have a valid ticket!" << endl;
    }
}

void Mission::operator+=(Astronaut *ast)
{
    if (this->a == 0)
    {
        this->crew = new Astronaut *[1];
        this->crew[0] = ast;
        this->a++;
        return;
    }
    Astronaut **temp = new Astronaut *[this->a + 1];
    for (int i = 0; i < this->a; i++)
    {
        temp[i] = this->crew[i];
    }
    temp[a] = ast;
    this->crew = temp;
    this->a++;
}

bool Mission::executeMission()
{
    int random = rand() & 100;
    if (random > this->faultProbability)
    {
        this->completed = true;
    }
    return this->completed;
}

int Mission::calculateProfit(int price)
{
    if (this->completed)
    {
        return this->p * price - this->cost;
    }
    return -1 * this->cost;
}
