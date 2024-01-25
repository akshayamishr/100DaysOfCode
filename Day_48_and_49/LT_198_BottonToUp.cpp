class Solution {
public:

    int helper2(vector<int>nums)
    {
        int n = nums.size();
        vector<int> dp2(n,-1);
        // base cases
        if(n==1) return nums[n-1];
        if(n==2) return max(nums[n-1],nums[n-2]);
        // bottom up solution
        dp2[n-1] = nums[n-1];
        dp2[n-2] = max(nums[n-1],nums[n-2]);
        for(int i = n-3; i >= 0; i--)
        {
            dp2[i] = max(dp2[i+1],dp2[i+2]+nums[i]);
        }
        return dp2[0];
    }

    int rob(vector<int>& nums) {
        return helper2(nums);
    }
};