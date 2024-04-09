// https://leetcode.com/problems/length-of-last-word/description/
// Length of Last Word
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();

        int i = n-1;
        string ans = "";

        while(i >= 0){
            if(s[i] == ' ' && ans.size() > 0) break;
            if(s[i] != ' ') ans += s[i];
            i--;
        }

        cout << ans;

        return ans.size();
    }
};