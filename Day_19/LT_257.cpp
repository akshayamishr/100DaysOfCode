class Solution {
public:

    void helper(TreeNode* root,vector<string> &v,string str)
    {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) // leaf node condition
        {
            str += to_string(root->val); 
            v.push_back(str);
            return;
        }
        str += to_string(root->val) + "->";
        helper(root->left,v,str);
        helper(root->right,v,str);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>v;
        string str = "";
        helper(root,v,str);
        return v;
    }
};