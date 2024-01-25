class Solution {
public:

    // space optimized solution
    int helper3(vector<int>nums)
    {
        int n = nums.size();
        // base cases
        if(n==1) return nums[n-1];
        if(n==2) return max(nums[n-1],nums[n-2]);
        //bottom  up solution
        int a = nums[n-1];
        int b = max(nums[n-1],nums[n-2]);
        int c = nums[n-3];
        for(int i = n-3; i >= 0; i--)
        {
            c = max(a+nums[i],b);
            a = b;
            b = c;
        }
        return c;
    }

    int rob(vector<int>& nums) {
        return helper3(nums);
    }
};