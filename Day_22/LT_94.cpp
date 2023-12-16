class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<TreeNode *> st;
        TreeNode *temp = root;
        while(temp || !st.empty())
        {
            if(temp)
            {
                st.push(temp);
                temp = temp->left;
            }
            else
            {
                TreeNode *temp2 = st.top();
                st.pop();
                v.push_back(temp2->val);
                temp = temp2->right;
            }
        }
        return v;
    }
};