class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n = matches.size();

        unordered_map<int,int>ml;  // map which will keep track of losers
        for(int i = 0; i < n; i++)
        {
            vector<int>temp = matches[i];
            ml[temp[1]]++;
        }

        vector<int>w;    
        vector<int>l;

        for(int i = 0; i < n; i++)
        {
            vector<int>temp = matches[i];
            if(ml.find(temp[0]) == ml.end()) {   // if temp[0] is not in map it is a winner with 0 lose
                w.push_back(temp[0]);
                ml[temp[0]] = 10;          // now push it in map so that, it won't be able to enter into l arr in the upcoming iterations (that's why it will have frequency of 10 to negate the second if condition)
            }
            if(ml[temp[1]] == 1) l.push_back(temp[1]);    // condition for 1 lose
        }

        sort(w.begin(),w.end());
        sort(l.begin(),l.end());

        vector<vector<int>> ans;
        ans.push_back(w);
        ans.push_back(l);

        return ans;
    }
};
