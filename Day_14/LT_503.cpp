class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for (int i = 0; i < 2 * n; i++)
        {
            int idx = i % n;
            while (st.size() && nums[idx] > nums[st.top()])
            {
                ans[st.top()] = nums[idx];
                st.pop();
            }
            st.push(idx);
        }
        return ans;
    }
};