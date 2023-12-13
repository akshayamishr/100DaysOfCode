class Solution {
public:

    bool is_exists(TreeNode* root, TreeNode* tar)
    {
        if(root == NULL) return false;
        if(root == tar) return true;
        return (is_exists(root->left,tar) || is_exists(root->right,tar));
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q) return root;
        else if(is_exists(root->left,p) && is_exists(root->right,q)) return root;
        else if(is_exists(root->right,p) && is_exists(root->left,q)) return root;
        else if(is_exists(root->left,p) && is_exists(root->left,q)) return(lowestCommonAncestor(root->left,p,q));
        else return(lowestCommonAncestor(root->right,p,q));
    }
};