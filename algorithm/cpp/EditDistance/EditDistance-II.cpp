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
    const int m = word1.size();
    const int n = word2.size();

    vector<int> cur(m + 1, 0);

    for (auto i = 1; i <= m; i++) cur[i] = i;
    /*
    *      +-----+  +--------+
    *      | pre |  | cur[i] |
    *      +-----+  +--------+
    *      +------+ +------+
    *      | temp | | next |
    *      +------+ +------+
    */
    for (auto j = 1; j <= n; j++)
    {
        auto pre = cur[0];
        cur[0] = j;
        for (auto i = 1; i <= m; i++)
        {
            const auto temp = cur[i];
            if (word1[i - 1] == word2[j - 1])
                cur[i] = pre;
            else
                cur[i] = min(pre + 1, min(temp + 1, cur[i - 1] + 1));
            pre = temp;
        }
    }
    return cur[m];
}


int main()
{
    const string word1 = "a";
    const string word2 = "a";
    const auto steps = minDistance(word1, word2);
    cout << word1 << ", " << word2 << " : " << steps << endl;
    return 0;
}