// https://leetcode.com/problems/subarray-product-less-than-k/
//  Subarray Product Less Than K


class Solution {
public:
  int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int n = nums.size();
    
    int i = 0, j = 0;
    int product = 1, ans = 0;
    
    if(k <= 1) return 0;

    while (j < n) {
      product *= nums[j];

      while (product >= k) product /= nums[i++];

      ans += 1 + (j - i);
      j++;
    }

    return ans;
  }
};