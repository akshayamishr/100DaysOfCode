class Solution {
public:
    TreeNode* first = NULL;
    void find_first(TreeNode* root,int start)
    {
        if(root == NULL) return;
        if(root->val == start)
        {
            first = root;
            return;
        }
        find_first(root->left,start);
        find_first(root->right,start);
    }

    void markParents(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent)
    {
        if(root == NULL) return;
        if(root->left) parent[root->left] = root;
        if(root->right) parent[root->right] = root;
        markParents(root->left,parent);
        markParents(root->right,parent);
    }


    int amountOfTime(TreeNode* root, int start) {
        find_first(root,start);                          // finding start node
        unordered_map<TreeNode*,TreeNode*> parent;      //  <child,parent>
        markParents(root,parent);                      // marking parent nodes
        unordered_set<TreeNode*>isInfected;          // set of infected node
        isInfected.insert(first);
        // BFS wrt first node (start node)
        queue<pair<TreeNode*,int>>q;
        q.push({first,0});
        int maxLevel = 0;
        while(q.size()>0)
        {
            pair<TreeNode*,int>temp = q.front();
            int level = temp.second;
            TreeNode* node = temp.first;
            maxLevel = max(maxLevel,level);
            // infecting left child 
            if(node->left){
                if(isInfected.find(node->left) == isInfected.end())
                {
                    q.push({node->left,level+1});
                    isInfected.insert(node->left);
                }
            }
            // infecting right child
            if(node->right){
                if(isInfected.find(node->right) == isInfected.end())
                {
                    q.push({node->right,level+1});
                    isInfected.insert(node->right);
                }
            }
            // infecting parent
            if(parent.find(node) != parent.end()){
                if(isInfected.find(parent[node]) == isInfected.end())
                {
                    q.push({parent[node],level+1});
                    isInfected.insert(parent[node]);
                }
            }
            q.pop();
        }
        return maxLevel;
    }
};