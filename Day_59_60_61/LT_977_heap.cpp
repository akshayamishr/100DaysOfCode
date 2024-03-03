// https://leetcode.com/problems/squares-of-a-sorted-array/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        map<int,int> mp;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            mp[nums[i]*nums[i]]++;
        }
        vector<int>ans;
        int j = 0;
        for(auto i : mp)
        {
            int k = mp[i.first];
            while(k)
            {
                ans.push_back(i.first);
                k--;
            }
        }
        return ans;
    }
};