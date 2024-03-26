// Find the Duplicate Number
// https://leetcode.com/problems/find-the-duplicate-number/description/?envType=daily-question&envId=2024-03-24

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
            if(mp[nums[i]] == 2) return nums[i];
        }
        return -1;
    }
};