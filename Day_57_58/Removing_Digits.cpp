
// Given a number n make it zero by subtracting the digits of that number recursivly
// for n = 27    answer is 5
//  27->20->18->10->9->0

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int>dp;

int steps(int n, vector<int> &dp)
{
    // base cases
    if (n == 0)
        return 0;
    if (n <= 9)
        return 1;
    if (dp[n] != -1)
        return dp[n];

    // main logic
    int m = n;
    dp[n] = INT_MAX;
    while (m)
    {
        if (m % 10 != 0)
        {
            dp[n] = min(dp[n], steps((n - m % 10), dp));
        }
        m /= 10;
    }

    return dp[n] = dp[n] + 1;
}

int main()
{
    int n;
    cout << "Enter a number : ";
    cin >> n;

    dp.resize(n + 1, -1);

    int ans = steps(n, dp);

    cout << ans;
}