// Number     : 67 
// Title      : Add Binary
// Source     : https://leetcode.com/problems/add-binary/description/
// Tags       : String
// Difficulty : Easy
// Author     : William
// Date       : 2017-12-15


/**********************************************************************************
*
* Given two binary strings, return their sum (also a binary string).
*
* For example,
* a = "11"
* b = "1"
* Return "100".
*
**********************************************************************************/

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Use the same method of multiply strings
string
addBinary(string a, string b)
{
    const auto max_len = max(a.size(), b.size());
    const auto res = new int[max_len + 1];

    if (a.size() == max_len) b.insert(0, max_len - b.size(), '0');
    else a.insert(0, max_len - a.size(), '0');

    auto carry = 0;
    for (int i = max_len - 1; i >= 0; i--)
    {
        // (carry) + (sum)
        const int temp = carry + (a[i] - '0') + (b[i] - '0');

        res[i + 1] = temp % 2;
        carry = temp / 2;
    }
    res[0] = carry;

    string s;
    for (auto i = 0; i < max(a.size(), b.size()) + 1; i++)
    {
        s += (res[i] == 1) ? '1' : '0';
    }
    delete[] res;

    const auto start_pos = s.find_first_not_of('0');
    if (start_pos != string::npos) return s.substr(start_pos);

    return "0";
}


int main()
{
    const string a = "0";
    const string b = "0";
    cout << addBinary(a, b) << endl;
    return 0;
}