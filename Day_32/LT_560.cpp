class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int count = 0;
        int sum = 0;   

        for (int ele : nums) 
        {
            sum += ele;

            if (sum == k) 
                count++;

            if (m.find(sum - k) != m.end()) 
                count += m[sum - k];
                
            m[sum]++;
        }
        return count;
    }
};