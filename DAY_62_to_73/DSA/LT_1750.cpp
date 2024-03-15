// https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/description/
// Minimum Length of String After Deleting Similar Ends
class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        if(n <= 1 || s[0] != s[n-1]) return n;

        char temp = s[0];
        int i = 0, j = n-1;
        
        while(i < j && s[i] == s[j])
        {
            temp = s[i];
            while(temp == s[i] && i <= j) i++;
            while(temp == s[j] && j >= i) j--;
        }
        
        return (j-i)+1;
    }
};