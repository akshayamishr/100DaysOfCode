// Diameter of Binary Tree
// https://leetcode.com/problems/diameter-of-binary-tree/
class Solution {
public:
    int levels(TreeNode* root)
    {
        if(root == NULL) return 0;
        return 1 + max(levels(root->left) , levels(root->right));
    }

    void recursion(TreeNode* root,int &maxDia)
    {
        if(root == NULL) return;
        int dia = levels(root->left) + levels(root->right);
        maxDia = max(maxDia,dia);
        recursion(root->left,maxDia);
        recursion(root->right,maxDia); 
    }

    int diameterOfBinaryTree(TreeNode* root) 
    {
        int maxDia = 0;
        recursion(root,maxDia);
        return maxDia;
    }
};