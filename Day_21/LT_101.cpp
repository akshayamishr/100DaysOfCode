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

    bool areSame(TreeNode* p, TreeNode* q)
    {
        if(p == NULL && q == NULL) return true;
        if(p == NULL || q ==NULL) return false;
        if(p->val != q->val) return false;
        return (areSame(p->left,q->left) && areSame(p->right,q->right));
    }

    void invert(TreeNode* root)
    {
        if(root == NULL) return;
        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = temp;
        invert(root->left);
        invert(root->right);
    }

    bool isSymmetric(TreeNode* root) {
        invert(root->left);
        return areSame(root->left,root->right);
    }
};
