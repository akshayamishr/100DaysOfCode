// https://leetcode.com/problems/even-odd-tree/description/
class Solution {
public:
    bool isEvenOddTree(TreeNode* root){
        // root node condition
        if(root->val % 2 == 0) 
            return false;

        // using queue for storing values and BFS traversal
        queue<pair<TreeNode*,int>>q;
        // TreeNode* and int-> depth
        if(root->left) q.push({root->left,1});
        if(root->right) q.push({root->right,1});


        // BFS traversal
        while(!q.empty()){

            auto temp = q.front();
            // if depth is even, values should be odd
            // if depth is odd, values should be even
            if((temp.second%2 == 0 && temp.first->val%2 == 0) || (temp.second%2 != 0 && temp.first->val%2 != 0))
                return false;

            // pushing temp ke childern if exists
            if(temp.first->left) q.push({temp.first->left,temp.second+1});
            if(temp.first->right) q.push({temp.first->right,temp.second+1});

            q.pop();

            // comparing former front with current front
            if(!q.empty())
            {
                // if depth is odd -> strictly decreasing order
                if(temp.second%2 != 0 && q.front().second == temp.second && q.front().first->val >= temp.first->val) 
                    return false;

                // if depth is even -> strictly increasing order
                if(temp.second%2 == 0 && q.front().second == temp.second && q.front().first->val <= temp.first->val) 
                    return false;    
            }
        }

        return true;
        
    }
};