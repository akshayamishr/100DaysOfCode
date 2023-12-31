class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>maxq(stones.begin(),stones.end());
        while(maxq.size() > 1)
        {
            int a = maxq.top();   // max element
            maxq.pop();
            int b = maxq.top();   //  second max element
            maxq.pop();
            int ans = a - b;
            if(ans != 0)maxq.push(ans);
        }
        if(maxq.size() == 0) return 0;
        return maxq.top();
    }
};