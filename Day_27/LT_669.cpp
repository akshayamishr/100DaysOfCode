class Solution {
public:

    void trimmer(TreeNode* root,int hi,int lo)
    {
        if(!root) return ;
        while(root->left)
        {
            if(root->left->val < lo) root->left = root->left->right;
            else if(root->left->val > hi) root->left = root->left->left;
            else break;
        }
        while(root->right)
        {
            if(root->right->val > hi) root->right = root->right->left;
            else if(root->right->val < lo) root->right = root->right->right;
            else break;
        }
        trimmer(root->left,hi,lo);
        trimmer(root->right,hi,lo);
    }

    TreeNode* trimBST(TreeNode* root, int low, int high) {
        TreeNode* dummy = new TreeNode(INT_MAX);
        dummy->left = root;
        trimmer(dummy,high,low);
        return dummy->left;
    }
};