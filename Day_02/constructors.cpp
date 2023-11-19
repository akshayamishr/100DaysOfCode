#include <iostream>
#include <string>
using namespace std;

class Team
{
public:
    class Batters
    {
    public:
        int left_handers;
        int right_handers;

        // Constructor
        Batters(int left, int right)
        {
            left_handers = left;
            right_handers = right;
        }
    };

    class Bowlers
    {
    public:
        int spinners;
        int seamers;

        // Constructor
        Bowlers(int spin, int seam)
        {
            spinners = spin;
            seamers = seam;
        }
    };

    string name;
    Batters batters;
    Bowlers bowlers;
    int all_rounders;
    // Contructers (initialisation list)
    Team(string std, Batters batters_obj, Bowlers bowlers_obj, int all_rounders) : name(std), batters(batters_obj), bowlers(bowlers_obj), all_rounders(all_rounders) {}
};

int main()
{
    Team::Batters i_batters(4, 2);
    Team::Bowlers i_bowlers(3, 0);
    Team cricketTeam("India", i_batters, i_bowlers, 1);

    cout << "Team name : " << cricketTeam.name << endl;
    cout << "  Batters -> " << endl;
    cout << "   Lefthanders : " << cricketTeam.batters.left_handers << "  Righthanders : " << cricketTeam.batters.right_handers << endl;
    cout << "  Bowlers -> " << endl;
    cout << "   Spinners : " << cricketTeam.bowlers.spinners << "  Seamers : " << cricketTeam.bowlers.seamers << endl;
    cout << "  All Rounders -> " << cricketTeam.all_rounders << endl;
}