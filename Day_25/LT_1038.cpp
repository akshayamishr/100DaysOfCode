class Solution {
public:

    void rev_inorder(TreeNode* root,int &sum)
    {
        if(root == NULL) return;
        rev_inorder(root->right,sum);
        root->val += sum;
        sum = root->val;
        rev_inorder(root->left,sum); 
    }

    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        rev_inorder(root,sum);
        return root;
    }
};