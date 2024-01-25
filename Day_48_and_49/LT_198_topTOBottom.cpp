class Solution {
public:
    int helper(vector<int>&nums,int i, vector<int>&dp)
    {
        int n = nums.size();
        if(i == n - 1) 
            dp[i] = nums[i];

        else if(i == n - 2)
            dp[i] = max(nums[i],nums[i+1]);

        else if(dp[i] == -1)
        {
            dp[i] = max(helper(nums,i+1,dp),(helper(nums,i+2,dp) + nums[i]));
        }
        return dp[i];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        //dp.resize(n, -1);
        int profit = helper(nums,0,dp);
        return profit;
    }
};