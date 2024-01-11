class Solution {
public:

    int ans=0;
    void solve(TreeNode* root,int mini,int maxi){
        if(!root)
        return ;
        maxi = max(maxi,root->val);
        mini = min(mini,root->val);
        ans = max(ans,maxi-mini);
        solve(root->left,mini,maxi);
        solve(root->right,mini,maxi);
        
    }
    int maxAncestorDiff(TreeNode* root) {
        int mini , maxi ;
        mini = maxi = root->val;
        solve(root,mini,maxi);
        return ans;
    }
};