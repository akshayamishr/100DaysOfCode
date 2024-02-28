// https://leetcode.com/problems/coin-change/
// LT_322



class Solution {
public:

    int helper(vector<int>& coins, int amount, vector<int>& dp) {
        // Base case
        if (amount == 0)
            return 0;
        
        // memoization
        if (dp[amount] != -2)
            return dp[amount];
        
        int temp = INT_MAX;
        
        for (int i = 0; i < coins.size(); i++) {
            if(amount < coins[i]) continue;
            int tempAns = helper(coins, amount - coins[i], dp);
            if (tempAns != INT_MAX && tempAns != -1) {
                int ans = 1 + tempAns;
                temp = min(ans, temp);
            }
        }
        if(temp == INT_MAX) return dp[amount]=-1;
        return dp[amount] = temp;
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int>dp(amount+5,-2);
        int ans= helper(coins,amount,dp);
        return ans;
    }
};
