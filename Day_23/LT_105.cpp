class Solution {
public:

    TreeNode* construct(vector<int>& pre,int pre_lo,int pre_hi,vector<int>& in,int in_lo,int in_hi)
    {
        if(pre_lo > pre_hi) return NULL;
        TreeNode *root = new TreeNode(pre[pre_lo]);
        if(pre_lo == pre_hi) return root;
        // find the root->val in in
        int i = in_lo;
        while(i <= in_hi)
        {
            if(in[i]==pre[pre_lo]) break;
            i++;
        }
        int l_len = i - in_lo;
        int r_len = in_hi - i;
        root->left = construct(pre, pre_lo+1, pre_lo+l_len, in, in_lo, i-1);
        root->right = construct(pre, pre_lo+l_len+1, pre_hi, in, i+1, in_hi);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size(); 
        return construct(preorder,0,n-1,inorder,0,n-1);
    }
};