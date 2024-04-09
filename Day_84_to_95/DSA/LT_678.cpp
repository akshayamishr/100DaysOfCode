// https://leetcode.com/problems/valid-parenthesis-string/description/?envType=daily-question&envId=2024-04-07
// Valid Parenthesis String
class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        stack<int>lp,st;

        for(int i = 0; i < n; i++){
            if(s[i] == '(') 
                lp.push(i);

            else if(s[i] == '*') 
               st.push(i);

            else{
                if(lp.size() > 0) lp.pop();
                else if(st.size() > 0) st.pop();
                else return false;
            }
        }

        while(lp.size() > 0 && st.size() > 0){

            if(lp.top() < st.top()){
                st.pop();
                lp.pop();
            }
            else return false;
        }

        if(lp.size() > 0) return false;

        return true;
    }
};