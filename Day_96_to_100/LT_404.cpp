// Sum of Left Leaves
// https://leetcode.com/problems/sum-of-left-leaves/description/?envType=daily-question&envId=2024-04-14

class Solution {
public:

    int sum = 0;

    void helper(TreeNode* root, bool flag){
        if(!root->left && !root->right && flag){
            sum += root->val;
        }

        if(root->left) helper(root->left,true);
        if(root->right) helper(root->right,false);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        helper(root,false);
        return sum;
    }
};