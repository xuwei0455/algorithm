// Number     : 5 
// Title      : Longest Palindromic Substring
// Source     : https://leetcode.com/problems/longest-palindromic-substring/description/
// Tags       : String
// Difficulty : Medium
// Author     : William
// Date       : 2017-12-11


/**********************************************************************************
*
* Given a string s, find the longest palindromic substring in s. You may assume that
* the maximum length of s is 1000.
*
* Example:
*   Input: "babad"
*   Output: "bab"
*
* Note: "aba" is also a valid answer.
* Example:
*   Input: "cbbd"
*   Output: "bb"
*
**********************************************************************************/

#include <string>
#include <iostream>
#include <vector>

using namespace std;

string
findPalindrome(const string& s, int left, int right)
{
    while (left >= 0 && right <= s.size() - 1 && s[left] == s[right])
    {
        left--;
        right++;
    }
    return s.substr(left + 1, right - left - 1);
}


// This is the common solution.
string
longestPalindrome(string s)
{
    int n = s.size();
    if (n <= 1) return s;

    string temp_str;
    string longest;

    for (auto i = 0; i < n - 1; i++) {
        temp_str = findPalindrome(s, i, i);
        if (temp_str.size() > longest.size())
            longest = temp_str;
        temp_str = findPalindrome(s, i, i + 1);
        if (temp_str.size() > longest.size())
            longest = temp_str;
    }
    return longest;
}

int main()
{
    const string s = "cbbd";
    cout << longestPalindrome(s) << endl;
    return 0;
}