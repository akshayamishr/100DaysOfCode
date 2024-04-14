//  Largest Rectangle in Histogram
// https://leetcode.com/problems/largest-rectangle-in-histogram/description/

class Solution {
public:

    vector<int> nextSmallerElement(vector<int>& heights){
        int n = heights.size();

        stack<int> st;
        st.push(n - 1);

        vector<int> result(n, n);

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();

            if(!st.empty()) result[i] = st.top();

            st.push(i);
        }
        return result;
    }

    vector<int> previousSmallerElement(vector<int>& heights){
        int n = heights.size();

        stack<int>st;
        st.push(-1);

        vector<int>result(n,-1);

        for(int i = 0; i < n; i++){
            while(st.top() != -1 && heights[st.top()] >= heights[i]) st.pop();

            if(!st.empty()) result[i] = st.top();

            st.push(i);
        }

        return result;
    }


    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size();

        vector<int> n = nextSmallerElement(heights);
        vector<int> p  = previousSmallerElement(heights);

        int ans = 0, tempA = 0;

        for(int i = 0; i < size; i++){
            int temp = n[i] - p[i] - 1;

            tempA = heights[i] * temp;
            ans = max(ans,tempA);
        }

        return ans;
    }
};
