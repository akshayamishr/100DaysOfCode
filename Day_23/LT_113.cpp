class Solution {
public:

    void helper(TreeNode* root,vector<vector<int>> &ans,vector<int> temp,int &targetSum,int sum)
    {
        if(root == NULL) return;
        temp.push_back(root->val);
        sum += root->val;
        if(root->left == NULL && root->right == NULL) // leaf node condition
        {
            if(sum == targetSum) 
                ans.push_back(temp);
            return;
        }
        helper(root->left,ans,temp,targetSum,sum);
        helper(root->right,ans,temp,targetSum,sum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(root,ans,temp,targetSum,0);
        return ans;
    }
};