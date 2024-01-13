class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        int first = 0, second = 0;
        for(int i = 0; i < n; i++)
        {
            char ch = tolower(s[i]);
            if(i < n/2) 
            {
                if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                    first++;
            }
            else
            {
                if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                second++;
            }
        }
        return first == second;
    }
};
