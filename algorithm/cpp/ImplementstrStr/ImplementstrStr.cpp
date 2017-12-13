// Number     : 28 
// Title      : Implement strStr()
// Source     : https://leetcode.com/problems/implement-strstr/description/
// Tags       : String
// Difficulty : Easy
// Author     : William
// Date       : 2017-12-13


/**********************************************************************************
*
* Implement strStr().
*
* Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*
* Example 1:
*   Input: haystack = "hello", needle = "ll"
*   Output: 2
*
* Example 2:
*   Input: haystack = "aaaaa", needle = "bba"
*   Output: -1
*
**********************************************************************************/

#include <string>
#include <iostream>
#include <vector>

using namespace std;

int
strStr(string haystack, string needle) 
{
    if (needle == "") return 0;
    for (auto i = 0; i < haystack.size(); i++)
    {
        if (haystack[i] == needle[0])
        {
            if (haystack.substr(i, needle.size()) == needle) return i;
        }
    }
    return -1;
}

int main()
{
    const string s = "hello";
    const string needle = "ll";
    cout << strStr(s, needle) << endl;
    return 0;
}