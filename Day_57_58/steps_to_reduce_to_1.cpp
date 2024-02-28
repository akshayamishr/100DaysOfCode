// You are given a number n. You can perform following operations on ->
//  1. minus 1 from n  (n = n - 1)
// 2. divide n by 2 (n = n/2)
// 3. divide n by 3 (n = n/3)
// return the minimum number of the operations to ruduce the number n to 1

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int f(int n, vector<int> &dp)
{
    // base case
    if (n == 1)
        return 0;
    if (n == 2 || n == 3)
        return 1;

    if (dp[n - 1] != -1)
        return dp[n - 1];

    int x = f(n - 1, dp);
    int y = (n % 2 == 0 ? f(n / 2, dp) : INT_MAX);
    int z = (n % 3 == 0 ? f(n / 3, dp) : INT_MAX);

    return dp[n - 1] = (1 + min(x, min(y, z)));
}

int main()
{
    int n;
    cout << "Enter the number : ";
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << "Minimum steps to reduce " << n << " to 1 : " << f(n, dp);
    return 0;
}