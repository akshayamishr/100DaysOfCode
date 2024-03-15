// https://leetcode.com/problems/minimum-common-value/
//Minimum Common Value

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        unordered_map<int,int>mp;

        for(int i = 0; i < n; i++)
        {
            mp[nums1[i]]++;
        }

        for(int i = 0; i < m; i++)
        {
            if(mp.find(nums2[i]) != mp.end())
                return nums2[i];
        }

        return -1;
    }
};