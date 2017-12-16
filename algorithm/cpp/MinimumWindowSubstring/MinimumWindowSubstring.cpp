// Number     : 76 
// Title      : Minimum Window Substring
// Source     : https://leetcode.com/problems/minimum-window-substring/description/
// Tags       : String
// Difficulty : Hard
// Author     : William
// Date       : 2017-12-16


/**********************************************************************************
*
* Given a string S and a string T, find the minimum window in S which will contain
* all the characters in T in complexity O(n).
*
* For example,
* S = "ADOBECODEBANC"
* T = "ABC"
* Minimum window is "BANC".
*
* Note:
* If there is no such window in S that covers all characters in T, return the empty string "".
*
* If there are multiple such windows, you are guaranteed that there will always be only one
* unique minimum window in S.
*
**********************************************************************************/

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string
minWindow(string s, string t)
{
    vector<int> map(128, 0);
    /* initialize the hash map here */
    for (auto c : t) map[c]++;
    // check whether the substring is valid
    auto counter = t.size();
    // two pointers, one point to tail and one  head
    auto begin = 0, end = 0;
    // the length of substring
    auto d = INT_MAX;

    auto head = 0;
    while (end < s.size())
    {
        // modify counter here
        if (map[s[end++]]-- > 0) counter--;
        // valid substring`
        while (counter == 0)
        {
            // update length of substring
            if (end - begin < d) { head = begin; d = end - head; };
            // make it invalid
            if (map[s[begin++]]++ == 0 /* escape first match character */) counter++;
        }
    }
    return d == INT_MAX ? "" : s.substr(head, d);
}


int main()
{
    string S = "ADOBECODEBANC";
    string T = "ABC";
    cout << "S = \"" << S << "\"  T=\"" << T << "\"" << endl;
    cout << minWindow(S, T) << endl;
    return 0;
}