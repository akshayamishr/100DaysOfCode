// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/description/
// Minimum Remove to Make Valid Parentheses
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        for (int i = 0; i < s.length(); i++) {
            if(s[i] == '('){
                st.push(i);
            }else if(s[i] == ')'){
                if(!st.empty()) st.pop();
                else{
                    s.erase(i, 1);
                    i--;
                }
            }
        }
        while (!st.empty()) {
            int pos = st.top();
            st.pop();
            s.erase(pos,1);
        }
        return s;
    }
};