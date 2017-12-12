// Number     : 10 
// Title      : Regular Expression Matching
// Source     : https://leetcode.com/problems/regular-expression-matching/description/
// Tags       : String
// Difficulty : Hard
// Author     : William
// Date       : 2017-12-12


/**********************************************************************************
*
* '.' Matches any single character.
* '*' Matches zero or more of the preceding element.
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
* isMatch("aa", "a*") ¡ú true
* isMatch("aa", ".*") ¡ú true
* isMatch("ab", ".*") ¡ú true
* isMatch("aab", "c*a*b") ¡ú true
*
**********************************************************************************/

#include <string>
#include <iostream>
#include <vector>

using namespace std;


// method to dive into sub mission
// 1. if '*' is in pattern, consider that character before '*' is occur zero or more,
//    so, if zero, we can search the sub pattern; if more, we can judge the first character
//    and then judge the rest string.
// 2. if not '*', we just judge the first character and rest string with rest patter.
bool
isMatch(string s, string p) {
    // handle pattern is empty
    if (p.empty()) return s.empty();

    if (p[1] == '*')
    {
        if (isMatch(s, p.substr(2)))
            return true;
        return (!s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p));
    }
    else
    {
        return !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p.substr(1));
    }
}


int main()
{
    const string s = "aab";
    const string p = "c*a*b";
    cout << isMatch(s, p) << endl;
    return 0;
}