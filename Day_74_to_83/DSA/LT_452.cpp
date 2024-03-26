// Minimum Number of Arrows to Burst Balloons
// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/?envType=daily-question&envId=2024-03-18

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) return 0;

		std::sort(points.begin(), points.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
			return a[0] < b[0];
		});

		int arrows = 1;
		int end = points[0][1];

		for (int i = 1; i < points.size(); i++) {
			if (points[i][0] > end) { 
				arrows++;
				end = points[i][1];
			}
			else { 
				end = std::min(end, points[i][1]);
			}
		}

	    return arrows;
    }
};