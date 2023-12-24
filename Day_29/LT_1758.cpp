class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        int count = 0;
        bool flag = true;
        if (s[0] == '0') flag = false;
        for(int i = 1; i < n; i++)
        {
            if(flag && s[i] == '1') 
            {
                count++;
                flag = false;
            }
            else if(!flag && s[i] == '0')
            {
                count++;
                flag = true;
            }
            else if(s[i] == '1') flag = true;
            else flag = false;
        }
        if(count > n/2) return n-count;
        return count;
    }
};