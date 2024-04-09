// Best Time to Buy and Sell Stock IV
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/
class Solution {
public:

    int dp[1005][105][2];

    int helper(vector<int>& prices, int i, int k, bool flag){
        // base case
        if(i >= prices.size()) return 0;

        // memoization
        if(dp[i][k][flag] != -1) return dp[i][k][flag];

        // if we don't want to buy the stock on current day

        int ans = helper(prices,i+1,k,flag);
        // if we want to buy the stock on day i
        if(k > 0 && flag == false)
            ans = max(ans,helper(prices,i+1,k,true) - prices[i]);
            
        // if we want to sell the stock on day i
        if(flag == true)
            ans = max(ans,helper(prices,i+1,k-1,false)+prices[i]);

        return dp[i][k][flag] = ans;
    }

    int maxProfit(int k, vector<int>& prices) {
        // memset will initialise the array as --->
        //                  memset(name of array, initial value, size of the array)
        memset(dp,-1,sizeof(dp));

        return helper(prices,0,k,false);
    }
};