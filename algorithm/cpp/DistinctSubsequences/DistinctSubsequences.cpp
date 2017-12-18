// Number     : 115 
// Title      : Distinct Subsequences
// Source     : https://leetcode.com/problems/restore-ip-addresses/description/
// Tags       : String
// Difficulty : Hard
// Author     : William
// Date       : 2017-12-18


/**********************************************************************************
*
* Given a string S and a string T, count the number of distinct subsequences of S which equals T.
*
* A subsequence of a string is a new string which is formed from the original string by
* deleting some (can be none) of the characters without disturbing the relative positions of
* the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
*
* Here is an example:
*
*   S = "rabbbit", T = "rabbit"
*   Return 3.
*
**********************************************************************************/

#include <string>
#include <iostream>
#include <vector>

using namespace std;


// Calculation
// 1. xxxxxa ~ xxxxxb
//   the last character is not match, means we need to delete the new last character 'a'.
//   so it's means f[i-1][j]
// 2. xxxxxa ~ xxxxxa
//   the last character is match, if we not use last character, f[i-1][j-1]
//   if not, means we add all possibility before, f[i-1][j-1]
int
numDistinct(string s, string t)
{
    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));

    for (auto i = 0; i < s.size() + 1; i++)
    {
        for (auto j = 0; j < t.size() + 1; j++)
        {
            if (j == 0)
                dp[i][j] = 1;
            else if (i == 0)
                dp[i][j] = 0;
            else
            {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[s.size()][t.size()];
}


int main()
{
    const string s = "rabbbit";
    const string t = "rabbit";
    cout << "S=\"" << s << "\"  T=\"" << t << "\"" << endl;
    cout << "numDistinct = " << numDistinct(s, t) << endl;
    return 0;
}