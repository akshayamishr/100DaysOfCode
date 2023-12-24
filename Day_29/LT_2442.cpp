class Solution {
public:

    int reverse(int n)
    {
        int rev = 0;
        while(n > 0)
        {
            rev *= 10;
            rev += n % 10;
            n /= 10;
        }
        return rev;
    }

    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        for(int i = 0; i < n; i++)
        {
            s.insert(nums[i]);
            s.insert(reverse(nums[i]));
        }
        return s.size();
    }
};