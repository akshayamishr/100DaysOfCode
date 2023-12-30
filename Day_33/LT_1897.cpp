class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char,int>char_count;
        for(string str : words)
        {
            for(char x : str)
                char_count[x]++;
        }
        int n = words.size();
        for(auto temp : char_count)
        {
            if(temp.second % n != 0) return false;
        }
        return true;
    }
};
