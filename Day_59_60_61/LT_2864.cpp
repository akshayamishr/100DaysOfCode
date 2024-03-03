// https://leetcode.com/problems/maximum-odd-binary-number/
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones = 0;
        string ans = "1";
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '1')
                ones++;
            else
                ans = "0" + ans;
        }

        for(int i = 1; i < ones; i++)
            ans = "1" + ans;

        return ans;
    }
};