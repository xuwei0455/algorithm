// Number     : 524 
// Title      : Longest Word in Dictionary through Deleting
// Source     : https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/description/
// Tags       : Sort
// Difficulty : Medium
// Author     : William
// Date       : 2017-12-11


/**********************************************************************************
*
* Given a string and a string dictionary, find the longest string in the dictionary
* that can be formed by deleting some characters of the given string. If there are
* more than one possible results, return the *longest word with the smallest
* lexicographical order. If there is no possible result, return the empty string.
*
* Example 1:
* Input:
* s = "abpcplea", d = ["ale","apple","monkey","plea"]
*
* Output:
* "apple"
* Example 2:
* Input:
* s = "abpcplea", d = ["a","b","c"]
*
* Output:
* "a"
*
* Note:
*   1.All the strings in the input will only contain lower-case letters.
*   2.The size of the dictionary won't exceed 1,000.
*   3.The length of all the strings in the input won't exceed 1,000.
*
**********************************************************************************/


#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


bool
compare(const string s1, const string s2)
{
    return (s1.size() == s2.size()) ? s1 < s2 : s1.size() > s2.size();
}


string
findLongestWord(string s, vector<string>& d)
{
    sort(d.begin(), d.end(), compare);

    for (auto word : d)
    {
        auto i = 0;
        for (auto c : s)
        {
            if (c == word[i]) i++;
        }
        if (i == word.size()) return word;
    }
    return "";
}

int main()
{
    const string s = "abpcplea";
    vector<string> d = { "ale","apple", "monkey","plea" };
    const auto res = findLongestWord(s, d);
    cout << res << endl;
    return 0;
}
