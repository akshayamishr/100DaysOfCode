class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true;
        if(p == NULL || q == NULL) return false;
        if(p->val == q->val)
        {
            bool a = isSameTree(p->left,q->left);
            if(a)
            {
                bool b = isSameTree(p->right,q->right);
                if(b) return true;
            }
        }
        return false;
    }
};