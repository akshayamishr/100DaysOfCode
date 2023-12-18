/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    TreeNode* construct(vector<int>& in,int in_lo,int in_hi,vector<int>& post,int post_lo,int post_hi)
    {
        if(in_lo > in_hi) return NULL;
        TreeNode *root = new TreeNode(post[post_hi]);
        if(in_lo == in_hi) return root;
        // find the root->val in in
        int i = in_lo;
        while(i <= in_hi)
        {
            if(in[i]==post[post_hi]) break;
            i++;
        }
        int l_len = i - in_lo;
        int r_len = in_hi - i;
        root->left = construct(in, in_lo, i-1, post, post_lo, post_hi-r_len-1);
        root->right = construct(in, i+1, in_hi, post, post_hi-r_len, post_hi-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size(); 
        return construct(inorder,0,n-1,postorder,0,n-1);
    }
};