//https://leetcode.com/problems/furthest-building-you-can-reach/
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        int brickCount = 0;
        int i = 0;
        for(;i < heights.size() - 1; i++)
        {
            if(heights[i] >= heights[i+1]) continue;
            int diff = heights[i +1] - heights[i];
            if(diff <= bricks - brickCount)
            {
                brickCount += diff;
                pq.push(diff);
            }
            else if(ladders > 0)
            {
                if(!pq.empty() && pq.top() > diff)
                {
                    int temp = pq.top();
                    pq.pop();
                    brickCount -= temp - diff;
                    pq.push(diff);
                }
                ladders--;
            }
            else break;
        }
        return i;
    }
};