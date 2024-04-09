// https://leetcode.com/problems/make-the-string-great/description/
// Make The String Great

class Solution {
public:
    string makeGood(string s) {
        int n = s.length();
        if(n < 2) return s;

        int i = 1;
        stack<int> st;
        st.push(s[0]);

        while(i < n){
            if(st.size() > 0){
                if(st.top() == s[i] + 32 || st.top() == s[i] - 32){
                    st.pop();
                    i += 1;
                } else{
                    st.push(s[i]);
                    i++;
                }
                
            } else{
                st.push(s[i]);
                i += 1;
            }
        }
        
        string ans = "";
        while(st.size() > 0){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};