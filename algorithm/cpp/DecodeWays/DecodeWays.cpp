// Number     : 91 
// Title      : Decode Ways
// Source     : https://leetcode.com/problems/decode-ways/description/
// Tags       : String
// Difficulty : Medium
// Author     : William
// Date       : 2017-12-16


/**********************************************************************************
*
* A message containing letters from A-Z is being encoded to numbers using the following mapping:
*
* 'A' -> 1
* 'B' -> 2
* ...
* 'Z' -> 26
* Given an encoded message containing digits, determine the total number of ways to decode it.
*
* For example,
* Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
*
* The number of ways decoding "12" is 2.
*
**********************************************************************************/

#include <string>
#include <vector>
#include <iostream>

using namespace std;


bool
validDecode(const string& s)
{
    if (s[0] == '1' && (s[1] >= '0' && s[1] <= '9')) return true;
    if (s[0] == '2' && (s[1] >= '0' && s[1] <= '6')) return true;
    return false;
}

int
numDecodings(string s)
{
    int n = s.size();
    if (n == 0) return 0;

    vector<int> dp(n + 1, 0);

    // means when the string is empty, there is only one answer.
    dp[n] = 1;
    // if this character is not 0, there will be an answer, or there will be no answer
    dp[n - 1] = (s[n - 1] == '0') ? 0 : 1;
    for (auto i = n - 2; i >= 0; i--)
    {
        // string begin with 0 has no answer
        if (s[i] == '0') continue;
        // "12"+"3xxxx" or "1"+"23xxxx" which is exactly memo[n]=memo[n-1]+memo[n-2]
        dp[i] = (validDecode(s.substr(i, 2))) ? dp[i + 1] + dp[i + 2] : dp[i + 1];
    }
    return dp[0];
}


int main()
{
    const string s = "10";
    cout << numDecodings(s) << endl;
    return 0;
}