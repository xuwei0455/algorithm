// Number     : 22 
// Title      : Generate Parentheses
// Source     : https://leetcode.com/problems/generate-parentheses/description/
// Tags       : String
// Difficulty : Medium
// Author     : William
// Date       : 2017-12-13


/**********************************************************************************
*
* Given n pairs of parentheses, write a function to generate all combinations of
* well-formed parentheses.
*
* For example, given n = 3, a solution set is:
*
* "((()))", "(()())", "(())()", "()(())", "()()()"
*
**********************************************************************************/

#include <string>
#include <iostream>
#include <vector>

using namespace std;


void
generate(vector<string>& v, string str, const int n, const int m)
{
    if (n == 0 && m == 0) { v.push_back(str); }

    if (n > 0) { generate(v, str + "{", n - 1, m + 1);}
    if (m > 0) { generate(v, str + "}", n, m - 1); }
}


vector<string>
generateParenthesis(const int n)
{
    vector<string> res;
    generate(res, "", n, 0);
    return res;
}


void
printResult(vector<string>& result)
{
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
}

int main()
{
    const int n = 4;
    auto result = generateParenthesis(n);
    printResult(result);
    return 0;
}