// Number     : 17 
// Title      : Letter Combinations of a Phone Number
// Source     : https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
// Tags       : String
// Difficulty : Medium
// Author     : William
// Date       : 2017-12-13


/**********************************************************************************
*
* Given a digit string, return all possible letter combinations that the number could represent.
*
* A mapping of digit to letters (just like on the telephone buttons) is given below.
*
* Input:Digit string "23"
* Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*
* Note:
* Although the above answer is in lexicographical order, your answer could be in any order you want.
*
*
**********************************************************************************/

#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<string>
cartesian(vector<string>& v1, string& str)
{
    vector<string> res;
    if (v1.size() == 0)
    {
        for (auto s : str) res.push_back(string(1, s));
        return res;
    }

    for (const auto s1 : v1)
    {
        for (const auto s2 : str)
        {
            res.push_back(s1 + s2);
        }
    }
    return res;
}



vector<string>
letterCombinations(string digits) {
    string char_map[10] = { "0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    vector<string> result;
    for (auto c : digits)
    {
        const auto idx = c - '0';
        result = cartesian(result, char_map[idx]);
    }
    return result;
}


void
printVector(vector<string> vs)
{
    cout << "{";
    for (auto i = 0; i < vs.size(); i++)
    {
        cout << vs[i];
        if (i < vs.size() - 1) cout << ", ";
    }
    cout << "}" << endl;;
}


int main()
{
    string s = "23";
    vector<string> ss = letterCombinations(s);
    printVector(ss);
    return 0;
}