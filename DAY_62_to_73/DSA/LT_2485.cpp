// https://leetcode.com/problems/find-the-pivot-integer/description/
// Find the Pivot Integer
class Solution {
public:
    int pivotInteger(int n) {
        if(n == 1) return 1;
        int sum = n * (n+1)/ 2;
        int tempSum = 1;
        for(int i = 2; i <= n; i++)
        {
            tempSum += i;
            
            if(tempSum == sum - tempSum + i) return i;
        }

        return -1;
    }
};