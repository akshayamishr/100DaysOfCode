class Solution {
public:

    vector<int> helper(TreeNode* root,vector<int>& v)
    {
        if(root == NULL) return v;
        helper(root->left,v);
        v.push_back(root->val);
        helper(root->right,v);
        return v;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        helper(root,v);
        return v;
    }
};