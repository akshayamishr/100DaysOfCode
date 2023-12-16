class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
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
            if(temp ->right) st.push(temp->right);
            if(temp->left) st.push(temp->left);
        }
        return v;
    }
};