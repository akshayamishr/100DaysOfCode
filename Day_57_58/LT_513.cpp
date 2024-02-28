//  Find Bottom Left Tree Value
// https://leetcode.com/problems/find-bottom-left-tree-value/

#define pp pair<int,int>
class Compare {
public:
    bool operator()(pp below, pp above)
    {
        if (below.second < above.second) {
            return true;
        } 
        return false;
    }
};
class Solution {
public:
    priority_queue<pp, vector<pp>, Compare> pq;
    void helper(TreeNode* root,int n)
    {
        if(root == NULL) return;
        if(!root->left && !root->right) 
        {
            pq.push({root->val,n});
            return;
        }

        if(root->left)
            helper(root->left,n+1);

        if(root->right)
            helper(root->right,n+1);
    }

    int findBottomLeftValue(TreeNode* root) {
        helper(root,0);
        return pq.top().first;
    }
};