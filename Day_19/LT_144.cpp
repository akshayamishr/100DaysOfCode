class Solution {
public:

    vector<int> helper(TreeNode* root,vector<int>& v)
    {
        if(root == NULL) return v;
        v.push_back(root->val);
        helper(root->left,v);
        helper(root->right,v);
        return v;
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        helper(root,v);
        return v;
    }
};