class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == NULL) return;
        TreeNode* curr = root;
        while (curr) {
            if (curr->left) {
                // Find predecessor
                TreeNode* pred = curr->left;
                while(pred->right) pred = pred->right;
                // Save root's right subtree
                TreeNode* tempRight = curr->right;
                // 
                pred->right = tempRight;
                // 
                curr->right = curr->left;
                curr = curr->left;
            }
            else curr = curr->right;
        }
        TreeNode* temp = root;
        while(temp->right)
        {
            temp->left = NULL;
            temp = temp->right;
        }
    }
};