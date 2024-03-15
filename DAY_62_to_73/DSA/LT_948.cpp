// https://leetcode.com/problems/bag-of-tokens/
// Bag of Tokens
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        int n = tokens.size();
        if(n==0) return 0;

        sort(tokens.begin(),tokens.end());

        if(tokens[0] > power) return 0;

        int i = 0, j = n - 1;
        int s = 0;

        while(i < j)
        {
            if(tokens[i] <= power)
            {
                power -= tokens[i];
                i++;
                s++;
            }

            else if(s > 0)
            {
                s--;
                power += tokens[j];
                j--;
            }

            else return s;
        }
        
        if(i == j && tokens[i] <= power) s++;
        
        return s;
    }
};