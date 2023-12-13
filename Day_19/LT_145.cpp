class Solution {
public:

    vector<int> helper(TreeNode* root,vector<int>& v)
    {
        if(root == NULL) return v;
        helper(root->left,v);
        helper(root->right,v);
        v.push_back(root->val);
        return v;
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        helper(root,v);
        return v;
    }
};