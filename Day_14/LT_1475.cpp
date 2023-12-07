class Solution
{
public:
    vector<int> finalPrices(vector<int> &prices)
    {
        int n = prices.size();
        stack<int> st;
        vector<int> ans(n);
        ans[n - 1] = prices[n - 1];
        st.push(prices[n - 1]);
        for (int i = n - 2; i >= 0; i--)
        {
            while (st.size() && prices[i] < st.top())
                st.pop();
            ans[i] = (st.size()) ? (prices[i] - (st.top())) : (prices[i]);
            st.push(prices[i]);
        }
        return ans;
    }
};