#include <iostream>
#include <string>
using namespace std;

class player
{
private:
    int score;
    int health;

public:
    // setter
    void set_score_and_health(int s, int h)
    {
        score = s;
        health = h;
    }
    // getter
    string get_score_and_health()
    {
        return ("Score is : " + to_string(score) + "  Health is : " + to_string(health));
    }
};

int main()
{
    player dashing;
    dashing.set_score_and_health(100, 90);
    cout << dashing.get_score_and_health();
}