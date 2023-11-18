#include <iostream>
using namespace std;
class player
{
public:
    int health;
    int score;
    void show()
    {
        cout << "Health is : " << health << "  " << "Score is : " << score << endl;
    }
};

int main()
{
    player dashing;
    dashing.health = 90;
    dashing.score = 100;
    dashing.show();

    player drake;
    drake.health = 100;
    drake.score = 90;
    drake.show();
}