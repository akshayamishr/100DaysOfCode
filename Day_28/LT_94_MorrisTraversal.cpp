class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // Morris Traversal
        vector<int> v;
        TreeNode* curr = root;
        TreeNode* pred = NULL;
        while(curr)
        {
            if(curr->left)
            {
                pred = curr->left;
                while(pred->right && pred->right != curr) pred = pred->right;  // pred is now the predecessor of curr
                if(pred->right == NULL)  // linking pred and curr
                {
                    pred->right = curr;
                    curr = curr->left;
                }
                else if(pred->right == curr)  // This implies that curr has the smallest val // unlinking pred and curr
                {
                    pred->right =  NULL;
                    v.push_back(curr->val);
                    curr = curr->right;
                }
            }
            else    // This implies that curr has the smallest val
            {
                v.push_back(curr->val);
                curr = curr->right;
            }
        }
        return v;
    }
};