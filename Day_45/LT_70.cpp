class Solution {
public:

    int helper(int n, vector<long long>&v)
    {
        if(n < 0) return 0;
        if(n == 1 || n == 2) return n;
        if(v[n] == -1)
          v[n] = (helper(n-1,v) + helper(n-2,v));
        return v[n];
    }

    int climbStairs(int n) {
        vector<long long>v(n+1,-1);
        return (helper(n,v));
    }
};
