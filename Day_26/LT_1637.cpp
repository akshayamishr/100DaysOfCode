class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int n = points.size();

        vector<int> v(points.size(),0);
        for(int i = 0 ; i < n; i++)
        {
            v[i] = points[i][0];
        }
        sort(v.begin(),v.end());

        int area = 0;
        for(int i = 0; i < n - 1; i++)
        {
            area = max(area,(v[i+1]-v[i]));
        }
        return area;
    }
};