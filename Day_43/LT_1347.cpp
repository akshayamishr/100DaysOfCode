class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int>m;
        int n = s.size();
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            m[s[i]]++;
        }
        for(int i = 0; i < n; i++)
        {
            if(m.find(t[i]) != m.end()) 
            {
                m[t[i]]--;
                if(m[t[i]] == 0) m.erase(t[i]);
            }
            else
                ans++;
        }
        return ans;
    }
};
