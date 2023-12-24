class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<char,int>m1;
        unordered_map<char,int>m2;
        for(int i = 0; i < s.length(); i++)
        {
            m1[s[i]]++;
            m2[t[i]]++;
        }
        for(auto ele : m1)
        {
            if(m2.find(ele.first) != m2.end())
            {
                int freq = m2[ele.first];
                if(ele.second != freq) return false;
            }
            else return false;
        }
        return true;
    }
};