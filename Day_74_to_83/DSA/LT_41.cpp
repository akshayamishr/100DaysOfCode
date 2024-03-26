// First Missing Positive
// https://leetcode.com/problems/first-missing-positive/description/?envType=daily-question&envId=2024-03-26

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n = nums.size();

        for(int i = 0; i < n; i++)
            mp[nums[i]]++;

        for(int i = 1; i <= n; i++)
        {
            if(mp.find(i) == mp.end()) return i;
        }

        return n+1;
    }
};