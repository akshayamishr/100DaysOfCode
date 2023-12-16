class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        if (root == NULL)
            return v;
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *temp = st.top();
            st.pop();
            v.push_back(temp->val);
            if (temp->left)
                st.push(temp->left);
            if (temp->right)
                st.push(temp->right);
        }
        reverse(v.begin(), v.end());
        return v;
    }
};