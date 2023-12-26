class Solution {
public:

    int rev(int n)
    {
        int r = 0;
        while(n > 0)
        {
            r *= 10;
            r += n % 10;
            n /= 10;
        }
        return r;
    }

    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>m;
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            int temp = nums[i] - rev(nums[i]);
            if(m.find(temp) != m.end())  
            {
                ans %= 1000000007;
                ans += m[temp];
            }
            m[temp]++;
        }
        return ans % 1000000007;
    }
};
