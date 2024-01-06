#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cc(pair<int, int> &p1, pair<int, int> &p2)
{
    // first ---> value
    // second ---> weight
    float r1 = (p1.first * 1.0) / (p1.second * 1.0);
    float r2 = (p2.first * 1.0) / (p2.second * 1.0);
    return r1 > r2;
}

double fractionalKnapsack(vector<int> &value, vector<int> &weight, float W)
{
    // W -> maximum weight of knapsack
    int n = value.size();

    vector<pair<int, int>> ratio;
    for (int i = 0; i < n; i++)
    {
        ratio.push_back({value[i], weight[i]});
    }

    // sorting according to value/weight ratio
    sort(ratio.begin(), ratio.end(), cc);
    double profit = 0;

    for (int i = 0; i < n; i++)
    {
        if (W >= ratio[i].second)
        {
            profit += ratio[i].first;
            W -= ratio[i].second;
        }
        else // we have to take fractional part
        {
            profit += ((ratio[i].first * 1.0) / (ratio[i].second * 1.0)) * W;
            W = 0;
            break;
        }
    }

    return profit;
}

int main()
{
    vector<int> value = {60, 100, 120};
    vector<int> weight = {10, 20, 30};
    int W = 50;
    cout << "Maximum profit : " << fractionalKnapsack(value, weight, W);
}