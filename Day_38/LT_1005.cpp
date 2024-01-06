class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
            pq.push(nums[i]);
        }
        while(k && pq.top() != 0)
        {
            int temp = pq.top();
            pq.pop();
            sum -= (2*temp);
            pq.push(-1 * temp);
            k--;
        }
        return sum;
    }
};