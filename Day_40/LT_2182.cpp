class Solution {
public:
    string repeatLimitedString(string s, int l) {
        int n = s.size();
        string ans = "";

        unordered_map<char,int>m;
        for(int i = 0; i < n; i++)
            m[s[i]]++;

        priority_queue<pair<char,int>>pq;
        for(auto it : m)
            pq.push({it.first,it.second});

        while(!pq.empty())
        {
            auto temp = pq.top();
            pq.pop();
            int len = min(temp.second,l);
            for(int i = 0; i < len; i++)
            {
                ans.push_back(temp.first);
            }

            pair<char,int>temp2;
            if(temp.second > l)
            {
                if(!pq.empty())
                {
                    temp2 = pq.top();
                    pq.pop();
                    ans.push_back(temp2.first);
                }
                else return ans;
            }
            if(temp.second > l) pq.push({temp.first, temp.second - l});
            if(temp2.second > 1) pq.push({temp2.first, temp2.second - 1});
        }

        return ans;
    }
};
