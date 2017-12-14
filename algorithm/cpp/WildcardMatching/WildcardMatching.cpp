// Number     : 44 
// Title      : Wildcard Matching*
// Source     : https://leetcode.com/problems/wildcard-matching/description/
// Tags       : String
// Difficulty : Hard
// Author     : William
// Date       : 2017-12-14


/**********************************************************************************
*
* '?' Matches any single character.
* '*' Matches any sequence of characters (including the empty sequence).
*
* The matching should cover the entire input string (not partial).
*
* The function prototype should be:
* bool isMatch(const char *s, const char *p)
*
* Some examples:
* isMatch("aa","a") ¡ú false
* isMatch("aa","aa") ¡ú true
* isMatch("aaa","aa") ¡ú false
* isMatch("aa", "*") ¡ú true
* isMatch("aa", "a*") ¡ú true
* isMatch("ab", "?*") ¡ú true
* isMatch("aab", "c*a*b") ¡ú false
*
**********************************************************************************/

#include <string>
#include <iostream>

using namespace std;

bool
isMatch(string s, string p)
{
    auto si = 0;
    auto pi = 0;

    auto star = -1;
    auto match = 0;
    while (si < s.size())
    {
        //advancing both pointers when (both characters match) or ('?' found in pattern)
        //note that *p will not advance beyond its length 
        if (pi < p.size() && (s[si] == p[pi] || '?' == p[pi])) { si++; pi++; continue; }

        // * found in pattern, track index of *, only advancing pattern pointer 
        if (pi < p.size() && '*' == p[pi]) { star = pi++; match = si; continue; }

        //current characters didn't match, last pattern pointer was *, current pattern pointer is not *
        //only advancing pattern pointer
        if (star != -1) { pi = star + 1; si = ++match; continue; }

        //current pattern pointer is not star, last patter pointer was not *
        //characters do not match
        return false;
    }

    //check for remaining characters in pattern
    while (pi < p.size())
    {
        if (!(p[pi++] == '*')) return false;
    }
    return true;
}


int main()
{
    const string s1 = "aaaa";
    const string s2 = "*aaa";

    cout << isMatch(s1, s2) << endl;
    return 0;
}