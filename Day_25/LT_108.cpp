class Solution {
public:
    TreeNode* binary_constructor(vector<int> &nums,int lo,int hi)
    {
        if(lo > hi) return NULL;
        int mid = lo + (hi-lo)/2;
        TreeNode* temp = new TreeNode(nums[mid]);
        temp->left = binary_constructor(nums,lo,mid-1);
        temp->right = binary_constructor(nums,mid+1,hi);
        return temp;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return binary_constructor(nums,0,nums.size()-1);
    }
};