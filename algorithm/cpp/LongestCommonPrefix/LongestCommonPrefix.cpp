// Number     : 14 
// Title      : Longest Common Prefix
// Source     : https://leetcode.com/problems/longest-common-prefix/description/
// Tags       : String
// Difficulty : Easy
// Author     : William
// Date       : 2017-12-13


/**********************************************************************************
*
* Write a function to find the longest common prefix string amongst an array of strings.
*
**********************************************************************************/

#include <string>
#include <iostream>
#include <vector>

using namespace std;

string
longestCommonPrefix(vector<string>& strs) {
    if ((strs.size() == 0) || (strs[0].size() == 0)) return "";

    string result;
    for (auto i = 0; i < strs[0].size(); i++)
    {
        char prefix = strs[0][i];
        for (auto j = 0; j < strs.size(); j++)
        {
            if (strs[j][i] != prefix) { prefix = '\0'; break; };
        }
        if (prefix == '\0') break;

        result += prefix;
    }
    return result;
}

int main()
{
    vector<string> v = { "text", "test" };
    cout << longestCommonPrefix(v) << endl;
    return 0;
}