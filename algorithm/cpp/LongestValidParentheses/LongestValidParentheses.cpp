// Number     : 32 
// Title      : Longest Valid Parentheses
// Source     : https://leetcode.com/problems/longest-valid-parentheses/description/
// Tags       : String
// Difficulty : Hard
// Author     : William
// Date       : 2017-12-14


/**********************************************************************************
*
* Given a string containing just the characters '(' and ')', find the length of the
* longest valid (well-formed) parentheses substring.
*
* For "(()", the longest valid parentheses substring is "()", which has length = 2.
*
* Another example is ")()())", where the longest valid parentheses substring is "()()",
* which has length = 4.
*
**********************************************************************************/

#include <string>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int
longestValidParentheses(string s)
{
    auto max_length = 0;
    stack<int> st;
    st.push(-1);

    for (auto i = 0; i < s.size(); i++)
    {
        const auto t = st.top();
        // pop only when get the close parenthese and match the open
        if (t != -1 && s[i] == ')' && s[t] == '(')
        {
            st.pop();
            max_length = max(max_length, i - st.top());
        }
        else
        {
            st.push(i);
        }
    }
    return max_length;
}


int main()
{
    string s = ")(()(()(((())(((((()((";

    cout << longestValidParentheses(s) << endl;
    return 0;
}