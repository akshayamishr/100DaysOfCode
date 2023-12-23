class Solution {
public:
    int maxScore(string s) {
        int one = 0, zero = 0;
        if(s[0] == '0') zero++;
        for(int i = 1; i < s.length (); i++)
        {
            if(s[i] == '1') one++;
        }
        int score = one + zero;
        for(int i = 1; i < s.length ()-1; i++)
        {
            if(s[i] == '0')  zero++;
            else   one--;
            score = max(score,one+zero);
        }
        return score;
    }
};