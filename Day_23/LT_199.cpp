class Solution {
public:

    int levels(TreeNode *root)
    {
        if(root == NULL) return 0;
        return 1 + max(levels(root->left),levels(root->right));
    }
    void preorder(TreeNode *root, vector<int> &ans, int curr_level)
    {
        if (root == NULL)
            return;
        ans[curr_level] = root->val;
        preorder(root->left, ans, curr_level+1);
        preorder(root->right, ans, curr_level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans(levels(root),0);
        preorder(root,ans,0);
        return ans;
    }
};