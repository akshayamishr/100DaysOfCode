class Solution {
public:

    void insertIntoBST(TreeNode* root, int val) {
        if(root == NULL)
           root =  new TreeNode(val);
        else if(root->val > val)
        {
            if(root->left == NULL)
                root->left = new TreeNode(val);
            else insertIntoBST(root->left,val);
        }
        else      //root->val < val
        {
            if(root->right == NULL)
                root->right = new TreeNode(val);
            else insertIntoBST(root->right,val);
        }
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        TreeNode* root = new TreeNode(preorder[0]);
        for(int i = 1; i < n; i++)
        {
            insertIntoBST(root,preorder[i]);
        }
        return root;
    }
};