// Nuber of Dice Rolls with Target Sum
// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/

#define mod 1000000007
class Solution {
public:

    int helper(int n, int k, int tar,vector<vector<int>>& dp)
    {
        // base cases
        if(n == 0 && tar == 0) return 1;
        if(n == 0) return 0;
        
        // memoization
        if(dp[n][tar] != -1) return dp[n][tar];

        // main logic
        int sum = 0;
        for(int i = 1; i <= k; i++)
        {
            if(tar < i) break;
            sum = (sum%mod + helper(n-1,k,tar-i,dp)%mod)%mod;
        }
        return dp[n][tar] = sum;
    }

    int numRollsToTarget(int n, int k, int tar) {
        vector<vector<int>>dp;
        dp.resize(33,vector<int>(tar+5,-1));
        return helper(n,k,tar,dp);
    }
};