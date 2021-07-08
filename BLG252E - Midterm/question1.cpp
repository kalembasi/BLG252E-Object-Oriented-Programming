
//  Name    :   Ömer Malik Kalembaşı
//  ID      :   150180112

#include <iostream>

using namespace std;

class Player
{
protected:
    string name;
    int score;

public:
    Player(string, int);
    void print() const;
    int operator+(Player &);
};

class ExpertPlayer : public Player
{
    string addSkill;

public:
    ExpertPlayer(string, int, string);
    void print();
};

Player::Player(string n, int s)
{
    cout << "constructor of player" << endl;
    this->name = n;
    this->score = s;
}
void Player::print() const
{
    cout << "Name: " << this->name << " score: " << this->score << endl;
}
int Player::operator+(Player &p)
{
    return this->score + p.score;
}

ExpertPlayer::ExpertPlayer(string name, int score, string addSkill) : Player(name, score)
{
    cout << "constructor of expert player" << endl;
    this->addSkill = addSkill;
}

void ExpertPlayer::print()
{
    cout << "Name: " << this->name << " score: " << this->score << endl;
    cout << "skill: " << this->addSkill << endl;
}
int main()
{
    ExpertPlayer e1 = ExpertPlayer("ExpertPlayer 1", 10, "time");
    ExpertPlayer e2 = ExpertPlayer("ExpertPlayer 2", 30, "space");
    const Player p1 = Player("player 1", 40);
    e1.print();
    e2.print();
    p1.print();
    int sum = e1 + e2;
    cout << sum << endl;

    return 0;
}
