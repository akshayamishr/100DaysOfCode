//https://leetcode.com/problems/unique-paths/
class Solution {
    fun uniquePaths(m: Int, n: Int): Int {
        var dp : Array<Array<Int>> = Array(m) { Array<Int>(n) { 1 } }
        var i : Int = 0;
        var j : Int = 0;
        while(i<m){
            j = 0
            while(j<n)
            {
                if(i != 0 && j != 0)
                    dp[i][j] = dp[i-1][j] + dp[i][j-1]
                j++
            }
            i++
        }
        return dp[m-1][n-1]
    }
}