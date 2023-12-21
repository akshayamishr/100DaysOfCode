class Solution {
public:

    TreeNode* successor(TreeNode* root)
    {
        if(root->right == NULL) return NULL;
        TreeNode* temp = root->right;
        while(temp->left)
        {
            temp = temp->left;
        }
        return temp;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        else if(root->val == key)
        {
            // leaf node condition
            if(!root->left && !root->right) return NULL;
            // one child node condition
            if(!root->left || !root->right) 
            {
                if(root->right) return root->right;
                else return root->left;
            }
            // two child-nodes condition
            if(root->left && root->right)
            {
                TreeNode* succ = successor(root);
                root->val = succ->val;
                root->right = deleteNode(root->right,succ->val);
            }
        }
        else if(root->val > key)
        {
            root->left = deleteNode(root->left,key);
        }
        else root->right = deleteNode(root->right,key);
        return root;
    }
};