// Number     : 3 
// Title      : Longest Substring Without Repeating Characters
// Source     : https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
// Tags       : String
// Difficulty : Medium
// Author     : William
// Date       : 2017-12-11


/**********************************************************************************
*
* Given a string, find the length of the longest substring without repeating characters.
*
* Examples:
*
* Given "abcabcbb", the answer is "abc", which the length is 3.
*
* Given "bbbbb", the answer is "b", with the length of 1.
*
* Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be
* a substring, "pwke" is a subsequence and not a substring.
*
**********************************************************************************/

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int
lengthOfLongestSubstring(string s) {
    vector<int> dict(256, -1);

    auto max_length = 0, start = -1;
    for (auto i = 0; i < s.size(); i++)
    {
        if (dict[s[i]] > start)
            start = dict[s[i]];
        dict[s[i]] = i;
        max_length = max(max_length, i - start);
    }
    return max_length;
}


int main()
{
    const string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}