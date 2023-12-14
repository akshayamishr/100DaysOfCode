class Solution {
public:

    void level_order(TreeNode *root, int count, int level, vector<int> &temp)
    {
        if (root == NULL)
            return;
        count++; // count++ is level of root
        if (count == level)
        {
            temp.push_back(root->val);
            return;
        }
        level_order(root->left, count, level, temp);
        level_order(root->right, count, level, temp);
    }

    int level(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        return 1 + max(level(root->left), level(root->right));
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        int n = level(root);
        for (int i = 1; i <= n; i++)
        {
            vector<int> temp;
            level_order(root, 0, i, temp);
            ans.push_back(temp);
        }
        return ans;
    }
};