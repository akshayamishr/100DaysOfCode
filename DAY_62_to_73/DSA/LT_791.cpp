//https://leetcode.com/problems/custom-sort-string/description/
//Custom Sort String
class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int>mp;
        for(int i = 0; i < s.size(); i++)
            mp[s[i]]++;
        
        string ans = "";

        for(int i = 0; i < order.size(); i++){
            if(mp.find(order[i]) != mp.end()){
                while(mp[order[i]] > 0){
                    ans += order[i];
                    mp[order[i]]--;
                }
            }
        }

        for(auto temp : mp){
            while(temp.second > 0){
                ans += temp.first;
                temp.second--;
            }
        }

        return ans;
    }
};