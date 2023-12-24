class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int>s;
        for(int i = 0; i < nums.size(); i++)
        {
            s.insert(nums[i]);
            string temp = to_string(nums[i]);
            reverse(temp.begin(),temp.end());
            s.insert(stoi(temp));
        }
        return s.size();
    }
};