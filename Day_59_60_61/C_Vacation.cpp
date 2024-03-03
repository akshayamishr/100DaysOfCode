#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of day : ";
    cin >> n;

    int a, b, c;
    cin >> a >> b >> c;

    vector<vector<int>> dp(n, vector<int>(3, -1));

    dp[0][0] = a; // 0th col is for a
    dp[0][1] = b; // 1st col is for b
    dp[0][2] = c; // 2nd col is for c

    for (int i = 1; i < n; i++)
    {
        cin >> a >> b >> c;

        // f(i,a) = ai + max(f(i-1,b), f(i-1,c))
        dp[i][0] = a + max(dp[i - 1][1], dp[i - 1][2]);
        // f(i,b) = ai + max(f(i-1,a), f(i-1,c))
        dp[i][1] = b + max(dp[i - 1][0], dp[i - 1][2]);
        // f(i,c) = ai + max(f(i-1,a), f(i-1,b))
        dp[i][2] = c + max(dp[i - 1][0], dp[i - 1][1]);
    }

    cout << max(dp[n - 1][0], (max(dp[n - 1][1], dp[n - 1][2])));
}