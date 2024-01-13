#include <iostream>
#include <vector>
using namespace std;

int fibo(int n, vector<int> &dp)
{
    // base case
    if (n == 0 || n == 1)
        return n;

    // condition to prevent excess recursive calls
    if (dp[n] == -1)
        dp[n] = fibo(n - 1, dp) + fibo(n - 2, dp);

    return dp[n];
}

int main()
{
    int n;
    cout << "Enter the number : ";
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << fibo(n, dp);
}