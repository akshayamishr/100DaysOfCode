#include<iostream>
#include<vector>
#define mod 1000000007
using namespace std;

int helper(int n,vector<int>&dp)
{
    if(n == 0) return 1;
    if(dp[n] != -1) return dp[n];

    int tempAns = 0;
    for(int i = 1; i <= 6; i++)
    {
        if(n >= i)
            tempAns = (tempAns%mod + (helper(n-i,dp))%mod)%mod;
    }
    return dp[n] = tempAns;
}

int main()
{
    int n;
    cin >> n;
    vector<int>dp(n+5,-1);
    int ans = helper(n,dp);
    cout << ans;
    return 0;
}