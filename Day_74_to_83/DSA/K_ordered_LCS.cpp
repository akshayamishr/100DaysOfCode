#include <iostream>
#include <vector>
using namespace std;

//long long dp[2050][2050][8];
vector<vector<vector<long long> > > dp(
        2005, vector<vector<long long> >(2005, vector<long long>(8,-1)));

long long longestCommonSubsequence(string &s1, string &s2, int i, int j, int k)
{
    if (i >= s1.size())
        return 0;
    if (j >= s2.size())
        return 0;

    if (dp[i][j][k] != -1)
        return dp[i][j][k];

    if (s1[i] == s2[j])
        return dp[i][j][k] = 1 + helper(s1, s2, i + 1, j + 1, k);

    else
    {
        long long temp = max(helper(s1, s2, i + 1, j, k), helper(s1, s2, i, j + 1, k));

        if (k > 0)
            return dp[i][j][k] = max(1 + helper(s1, s2, i + 1, j + 1, k - 1), temp);

        return dp[i][j][k] = temp;
    }
}


int main()
{
    // int k;
    // cin >> k;
    // string str1, str2;
    // cin >> str1 >> str2;
    string str1 = "12345";
    string str2 = "53142";
    cout << longestCommonSubsequence(str1, str2, 0, 0, 1);
}