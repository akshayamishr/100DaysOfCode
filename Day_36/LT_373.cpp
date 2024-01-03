# define pp pair<int,pair<int,int>>
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
       priority_queue<pp, vector<pp>, greater<pp>> pq;
        for (int i = 0; i < nums1.size(); i++) 
            pq.push({nums1[i] + nums2[0], {i, 0}});
        vector<vector<int>> ans;

        while (k-- && !pq.empty()) {
            auto t = pq.top();
            pq.pop();

            int i = t.second.first;
            int j = t.second.second;

            ans.push_back({nums1[i], nums2[j]});

            if (j + 1 < nums2.size()) {
                pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});
            }
        }
        return ans;
    }
};