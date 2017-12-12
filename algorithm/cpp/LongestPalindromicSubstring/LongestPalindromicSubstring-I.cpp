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
#include <algorithm>

using namespace std;

bool
is_palindrome(const string& s)
{
    auto temp = s;
    reverse(temp.begin(), temp.end());
    return s == temp;
}

string
longestPalindrome(string s)
{
    int start = 0;
    int max_length = 1;

    for (int i = 0; i < s.size(); i++)
    {
        if ((i - max_length >= 1) && is_palindrome(s.substr(i - max_length - 1, max_length + 2)))
        {
            start = i - max_length - 1;
            max_length += 2;
            continue;
        }
        if ((i - max_length >= 0) && is_palindrome(s.substr(i - max_length, max_length + 1)))
        {
            start = i - max_length;
            max_length += 1;
        }
    }
    return s.substr(start, max_length);
}

int main()
{
    const string s = "cbbd";
    cout << longestPalindrome(s) << endl;
    return 0;
}