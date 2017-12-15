// Number     : 49 
// Title      : Group Anagrams
// Source     : https://leetcode.com/problems/group-anagrams/description/
// Tags       : String
// Difficulty : Medium
// Author     : William
// Date       : 2017-12-15


/**********************************************************************************
*
* Given an array of strings, group anagrams together.
*
* For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
* Return:
*   [
*       ["ate", "eat","tea"],
*       ["nat","tan"],
*       ["bat"]
*   ]
* Note: All inputs will be in lower-case.
*
**********************************************************************************/

#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


string
countSort(string& s)
{
    int counter[26] = { 0 };
    for (auto c : s)
    {
        counter[c - 'a']++;
    }

    string res;
    for (auto i = 0; i < 26; i++)
    {
        for (auto n = 0; n < counter[i]; n++)
        {
            res += (i + 'a');
        }
    }
    return res;
}


vector<vector<string>>
groupAnagrams(vector<string>& strs)
{
    unordered_map<string, vector<string>> group;
    for (auto s : strs)
    {
        const auto idx = countSort(s);
        group[idx].push_back(s);
    }

    vector<vector<string>> res;
    for (const auto i : group)
    {
        res.push_back(i.second);
    }
    return res;
}


void
printResult(vector<vector<string>>& res)
{
    cout << "[" << endl;
    for (auto v : res)
    {
        cout << '\t' << "[";
        for (const auto s : v)
        {
            cout << '"' << s << '"' << ',';
        }
        cout << "]" << endl;
    }
    cout << "]" << endl;
}


int main()
{
    vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
    auto res = groupAnagrams(strs);
    printResult(res);
    return 0;
}