// https://leetcode.com/problems/squares-of-a-sorted-array/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = n - 1;
        vector<int>ans(nums.size());
        int k = j;
        while(i <= j)
        {
            long long left = (long long)(nums[i]) * (long long)(nums[i]);
            long long right = (long long)(nums[j]) * (long long)(nums[j]);

            if(left > right)
            {
                ans[k] = left;
                i++;
            }
            else
            {
                ans[k] = right;
                j--;
            }
            k--;
        }
        return ans;
    }
};