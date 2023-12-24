class Solution {
public:
    /// using only one map
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        unordered_map<char, int> m1;
        for (int i = 0; i < s.length(); i++) {
            m1[s[i]]++;
        }
        for (auto ele : t) {
            if (m1.find(ele) != m1.end()) {
                m1[ele]--;
                if (m1[ele] == 0)
                    m1.erase(ele);
            } else
                return false;
        }
        return true;
    }
};