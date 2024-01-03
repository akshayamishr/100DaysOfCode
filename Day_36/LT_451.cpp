class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>m;
        for(int i = 0; i < s.size(); i++)
            m[s[i]]++;
        
        priority_queue<pair<int,char>>pq;
        for(auto it : m)
            pq.push({it.second,it.first});
        
        string ans = "";
        while(!pq.empty())
        {
            pair<int,char> temp = pq.top();
            pq.pop();
            for(int i = 0; i < temp.first; i++)
                ans += temp.second;
        }
        return ans;
    }
};