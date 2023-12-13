class Solution {
public:
    void findIndices(vector<int>& arr,vector<int>& v) {
    int n = arr.size();
    int firstIndex = 0, secondIndex = -1;
    for (int i = 1; i < n; ++i) {
        if (arr[i] > arr[firstIndex]) {
            secondIndex = firstIndex;
            firstIndex = i;
        } else if (secondIndex == -1 || arr[i] > arr[secondIndex]) {
            secondIndex = i;
        }
    }
    v[0]=firstIndex;
    v[1]=secondIndex;
}
    int maxProduct(vector<int>& nums) {
        vector<int> v(2,0);
        findIndices(nums,v);
        return ((nums[v[0]]) - 1) * ((nums[v[1]] )- 1);
    }
};