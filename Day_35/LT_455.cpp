class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int count= 0; //  number of childern getting cookies
        int i = 0;  // greed array pointer  
        int j = 0;  // cookie size array pointer
        while(i<g.size() && j<s.size()){
            if(g[i]<=s[j]){  // agar size of cookie >= greed ---> cookie de do
                count++;
                i++;j++;
            }
            else j++;        // agar size of cookie is < greed ----> cookie array me age jao
        }
        return count;
    }
};