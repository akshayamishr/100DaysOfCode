class Solution {
public:
    int max_val(TreeNode *root)
    {
        if (root == NULL)
            return INT_MIN;
        return max(root->val, max(max_val(root->left), max_val(root->right)));
    }

    int min_val(TreeNode *root)
    {
        return root ? min(root->val, min(min_val(root->left), min_val(root->right))) : INT_MAX;
    }
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        if((root->left) && root->val <= max_val(root->left)) return false;
        else if((root->right) && root->val >= min_val(root->right)) return false;
        return (isValidBST(root->left) && isValidBST(root->right));
    }
};