class Solution {
public:
    void inorder(TreeNode* root,vector<int> &in)
    {
        if(root == NULL) return;
        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);
    }

    TreeNode* balanced_tree(vector<int>& in,int lo,int hi)
    {
        if(lo>hi) return NULL;
        int mid = lo+(hi-lo)/2;
        TreeNode* temp = new TreeNode(in[mid]);
        temp->left = balanced_tree(in,lo,mid-1);
        temp->right = balanced_tree(in,mid+1,hi);
        return temp; 
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> in;
        inorder(root,in);
        return balanced_tree(in,0,in.size()-1);;
    }
};