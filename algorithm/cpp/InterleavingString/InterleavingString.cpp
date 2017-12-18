// Number     : 97 
// Title      : Interleaving String
// Source     : https://leetcode.com/problems/interleaving-string/description/
// Tags       : String
// Difficulty : Hard
// Author     : William
// Date       : 2017-12-18


/**********************************************************************************
*
* Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
*
* For example,
* Given:
* s1 = "aabcc",
* s2 = "dbbca",
*
* When s3 = "aadbbcbcac", return true.
* When s3 = "aadbbbaccc", return false.
*
**********************************************************************************/

#include <string>
#include <iostream>
#include <vector>

using namespace std;

/*
Considering:
    s1 = a1, a2 ........a(i-1), ai
    s2 = b1, b2, .......b(j-1), bj
    s3 = c1, c3, .......c(i+j-1), c(i+j)

Defined
    match[i][j]  means   s1[0..i] and s2[0..j] is matched S3[0..i+j]

    So, if ai == c(i+j), then match[i][j] = match[i-1][j], which means
    
    s1 = a1, a2 ........a(i-1)
    s2 = b1, b2, .......b(j-1), bj
    s3 = c1, c3, .......c(i+j-1)
    
    Same, if bj = c(i+j), then match[i][j] = match[i][j-1];
Formula:
    Match[i][j] =
        (s3[i+j-1] == s1[i]) && match[i-1][j] ||
        (s3[i+j-1] == s2[j]) && match[i][j-1]

Initialization:
    i=0 && j=0, match[0][0] = true;
    
    i=0,   s3[j] == s2[j], match[0][j] |= match[0][j-1]
    s3[j] != s2[j], match[0][j] = false;
    
    j=0,   s3[i] == s1[i], match[i][0] |= match[i-1][0]
    s3[i] != s1[i], Match[i][0] = false;
*/
bool
isInterleave(string s1, string s2, string s3)
{
    if (s1.size() + s2.size() != s3.size()) return false;

    vector<vector<bool>> table(s1.size() + 1, vector<bool>(s2.size() + 1, false));

    for (auto i = 0; i < s1.size() + 1; i++)
    {
        for (auto j = 0; j < s2.size() + 1; j++)
        {
            if (i == 0 && j == 0) { table[i][j] = true; }
            else if (i == 0) { table[i][j] = table[i][j - 1] && (s2[j - 1] == s3[i + j - 1]); }
            else if (j == 0) { table[i][j] = table[i - 1][j] && (s1[i - 1] == s3[i + j - 1]); }
            else
                table[i][j] = (table[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (table[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
        }
    }
    return table[s1.size()][s2.size()];
}

int main()
{
    const string s1 = "aabcc";
    const string s2 = "dbbca";
    const string s3 = "aabccdbbca";
    const auto result = isInterleave(s1, s2, s3);

    cout << result << endl;
    return 0;
}