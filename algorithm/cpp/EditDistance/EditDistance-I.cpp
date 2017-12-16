// Number     : 72 
// Title      : Edit Distance
// Source     : https://leetcode.com/problems/edit-distance/description/
// Tags       : String
// Difficulty : Hard
// Author     : William
// Date       : 2017-12-16


/**********************************************************************************
*
* Given two words word1 and word2, find the minimum number of steps required to
* convert word1 to word2. (each operation is counted as 1 step.)
*
* You have the following 3 operations permitted on a word:
*
*   a) Insert a character
*   b) Delete a character
*   c) Replace a character
*
**********************************************************************************/

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int
minDistance(string word1, string word2)
{
    int m = word1.size();
    int n = word2.size();

    // define state dp[m][n] to be the minimum number of operations 
    // to convert word1[0..m - 1] to word2[0..n - 1]
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (auto i = 1; i <= m; i++) dp[i][0] = i;
    for (auto j = 1; j <= n; j++) dp[0][j] = j;
    for (auto i = 1; i <= m; i++)
    {
        for (auto j = 1; j <= n; j++)
        {
            if (word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min(dp[i - 1][j - 1] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j] + 1));
        }
    }
    return dp[m][n];
}


int main()
{
    string word1 = "abb", word2 = "abccb";
    int steps = minDistance(word1, word2);
    cout << word1 << ", " << word2 << " : " << steps << endl;
    return 0;
}