// Number     : 43 
// Title      : Multiply Strings
// Source     : https://leetcode.com/problems/multiply-strings/description/
// Tags       : String
// Difficulty : Medium
// Author     : William
// Date       : 2017-12-14


/**********************************************************************************
*
* Given two non-negative integers num1 and num2 represented as strings, return the product
* of num1 and num2.
*
* Note:
*
* The length of both num1 and num2 is < 110.
* Both num1 and num2 contains only digits 0-9.
* Both num1 and num2 does not contain any leading zero.
* You must not use any built-in BigInteger library or convert the inputs to integer directly.
*
**********************************************************************************/

#include <string>
#include <iostream>

using namespace std;

string
multiply(string num1, string num2)
{
    string res(num1.size() + num2.size(), '0');

    for (int i = num1.size() - 1; i >= 0; --i)
    {
        auto carry = 0;
        for (int j = num2.size() - 1; j >= 0; --j)
        {
            // (history value) + (mulitply value) + (carry value)
            const auto temp = (res[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;

            res[i + j + 1] = temp % 10 + '0';
            carry = temp / 10;
        }
        // carry value to the last circulation need to be added.
        res[i] += carry;
    }
    // find result which not contains '0'
    const auto start_pos = res.find_first_not_of("0");
    if (start_pos != string::npos)
    {
        res = res.substr(start_pos);
        return res;
    }
    return "0";
}

int main()
{
    const string s1 = "1";
    const string s2 = "1";

    cout << multiply(s1, s2) << endl;
    return 0;
}