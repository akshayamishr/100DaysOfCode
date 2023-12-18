class Solution {
public:

    void noOfPaths(TreeNode *root,long long sum ,int &count)
    {
        if(root == NULL) return;
        if(sum == (long long)root->val)
        {
            count++;
        }
        noOfPaths(root->left,sum-(long long)(root->val),count);
        noOfPaths(root->right,sum-(long long)(root->val),count);
    }

    int pathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return 0;
        int count = 0;
        noOfPaths(root,(long long)targetSum,count);
        count += (pathSum(root->left,targetSum) + pathSum(root->right,targetSum));
        return count;
    }
};