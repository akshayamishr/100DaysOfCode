class Solution {
public:

    void helper(TreeNode* root)
    {
        if(root == NULL) return;

        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = temp;
        
        helper(root->left);
        helper(root->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        helper(root);
        return root;
    }
};