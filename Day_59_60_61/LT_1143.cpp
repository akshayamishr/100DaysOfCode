//  https://leetcode.com/problems/longest-common-subsequence/
class Solution {
public:

    vector<vector<int>>dp;

    int helper(string &s1, string &s2, int i, int j)
    {
        if(i >= s1.size()) return 0;
        if(j >= s2.size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]) return dp[i][j] = 1 + helper(s1,s2,i+1,j+1);
        
        else{
            return dp[i][j] = max(helper(s1,s2,i+1,j),helper(s1,s2,i,j+1));
        }
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        dp.clear();
        dp.resize(n+5,vector<int>(m+5,-1));
        return helper(text1,text2,0,0);
    }
};