#include <iostream>
using namespace std;
class player
{
private:
    int health;
    int score;
    bool alive;
    int age;

public:
    // setters
    void setter(int health, int score, int age, bool alive)
    {
        this->health = health;
        this->score = score;
        this->age = age;
        this->alive = alive;
    }
    // getters
    int get_health()
    {
        return health;
    }
    int get_age()
    {
        return age;
    }
    int get_score()
    {
        return score;
    }
    bool get_alive()
    {
        return alive;
    }
};

player m(player a, player b)
{
    if (a.get_score() > b.get_score())
        return a;
    return b;
}

int main()
{
    // static memory allocation
    player A, B;
    A.setter(100, 90, 20, 1);
    B.setter(90, 100, 19, 1);

    player C = m(A, B);
    cout << "Winner's score is : " << C.get_score() << endl;

    // dynamic memory allocation
    player *Dynamic_player = new player;
    Dynamic_player->setter(100,100,20,1);
    cout << "Dynamic Player's score is : " << Dynamic_player->get_score();
}