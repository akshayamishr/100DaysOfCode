// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/
// Maximum Nesting Depth of the Parentheses
class Solution {
public:
    int maxDepth(string s) {
        int ans = 0, final_ans = 0;

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(') ans++;
            if(s[i] == ')') ans--;
            final_ans = max(ans,final_ans);
        }

        return final_ans;
    }
};