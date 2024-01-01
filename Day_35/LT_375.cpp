class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int, vector<int>, greater<int>> min_pq;
        int n = matrix.size();
        for(int i = 0; i < min(n,k); i++)
        {
            for(int j = 0; j < n; j++) min_pq.push(matrix[i][j]);
        }
        int ans;
        while(k != 0)
        {
            ans = min_pq.top();
            min_pq.pop();
            k--;
        }
        return ans;
    }
};