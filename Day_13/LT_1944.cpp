class Solution
{
public:
    vector<int> canSeePersonsCount(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> ans(n, 1);
        stack<int> st;
        ans[n - 1] = 0;
        st.push(heights[n - 1]);
        for (int i = n - 2; i >= 0; i--)
        {
            int count = 0;
            while (st.size() && heights[i] > st.top())
            {
                st.pop();
                count++;
            }
            ans[i] = (st.size()) ? count + 1 : count;
            st.push(heights[i]);
        }
        return ans;
    }
};