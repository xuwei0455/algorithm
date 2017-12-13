// Number     : 20 
// Title      : Valid Parentheses
// Source     : https://leetcode.com/problems/valid-parentheses/description/
// Tags       : String
// Difficulty : Easy
// Author     : William
// Date       : 2017-12-13


/**********************************************************************************
*
* Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
* determine if the input string is valid.
*
* The brackets must close in the correct order, "()" and "()[]{}" are all valid
* but "(]" and "([)]" are not.
*
**********************************************************************************/

#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool
isValid(string s)
{
    string left = "([{";
    string right = ")]}";
    vector<int> cur_type;
    int state[3] = { 0 };

    for (auto c : s)
    {
        const auto left_pos = left.find(c);
        if (left_pos != string::npos)
        {
            cur_type.push_back(left_pos);
            state[left_pos] += 1; continue;
        }

        const auto right_pos = right.find(c);
        if (right_pos != string::npos)
        {
            if (cur_type.size() == 0 || cur_type.back() != right_pos) return false;
            cur_type.pop_back();
            state[right_pos] -= 1; continue;
        }

        // a close parenthese without open;
        auto cur_pos = 0;
        for (auto i : state) { cur_pos += i; }
        if (cur_pos < 0) return false;
    }

    for (auto i : state)
    {
        if (i != 0) return false;
    }
    return true;
}

int main()
{
    string s = "([])";
    cout << isValid(s) << endl;
    return 0;
}