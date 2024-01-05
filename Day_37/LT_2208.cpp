class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double>pq;
        double sum = 0.0;
        for(int i = 0; i < nums.size(); i++)
        {
            pq.push((1.0)*(nums[i]));
            sum += nums[i];
        }
        double resum = sum;
        int count = 0;
        while(resum > (sum/2.0))
        {
            double temp = (pq.top()/2.0);
            pq.pop();
            pq.push(temp);
            resum -= temp;
            count++;
        }
        return count;
    }
};