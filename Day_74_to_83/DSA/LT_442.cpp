// Find All Duplicates in an Array
// https://leetcode.com/problems/find-all-duplicates-in-an-array/description/?envType=daily-question&envId=2024-03-25

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<bool>flags(n+5,true);
        vector<int>ans;
        for(int i = 0; i < n; i++)
        {
            if(flags[nums[i]])
                flags[nums[i]] = false;

            else{
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};