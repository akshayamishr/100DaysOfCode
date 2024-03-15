// https://leetcode.com/problems/count-elements-with-maximum-frequency/description/
// Count Elements With Maximum Frequency

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        
        unordered_map<int,int> mp;
        int max_freq = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
            max_freq = max(max_freq,mp[nums[i]]);
        }

        int temp = 0; // temp is the number of elements having max frequency

        for(auto ele : mp)
        {
            if(ele.second == max_freq)
                temp++;
        }

        return max_freq * temp;
    }
};