class Solution
{
public:
    stack<int> st, sst;
    int size(ListNode *head)
    {
        int s = 0;
        ListNode *temp = head;
        while (temp)
        {
            s++;
            st.push(temp->val);
            temp = temp->next;
        }
        if (s != 0)
        {
            sst.push(st.top());
            st.pop();
        }
        return s;
    }

    vector<int> nextLargerNodes(ListNode *head)
    {
        int n = size(head);

        vector<int> ans(n, 0);
        for (int i = n - 2; i >= 0; i--)
        {
            while (sst.size() && st.top() >= sst.top())
                sst.pop();
            ans[i] = (sst.size()) ? sst.top() : 0;
            sst.push(st.top());
            st.pop();
        }
        return ans;
    }
};