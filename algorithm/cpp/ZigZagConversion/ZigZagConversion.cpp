// Number     : 6 
// Title      : ZigZag Conversion
// Source     : https://leetcode.com/problems/zigzag-conversion/description/
// Tags       : String
// Difficulty : Medium
// Author     : William
// Date       : 2017-12-12


/**********************************************************************************
*
* The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows
* like this: (you may want to display this pattern in a fixed font for better legibility)
*
* P   A   H   N
* A P L S I I G
* Y   I   R
* And then read line by line: "PAHNAPLSIIGYIR"
* Write the code that will take a string and make this conversion given a number of rows:
*
* string convert(string text, int nRows);
* convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*
**********************************************************************************/

#include <string>
#include <iostream>
#include <vector>

using namespace std;

string
convert(string s, int numRows) {
    if (numRows == 1 || s.size() < numRows) return s;
    vector<string> m(numRows);

    int row = 0;
    int step = 1;
    for (auto i = 0; i < s.size(); i++)
    {
        m[row] += s[i];
        if (row == numRows - 1) step = -1;
        if (row == 0) step = 1;
        row += step;
    }

    string result;
    for (auto i = 0; i < numRows; i++)
    {
        result += m[i];
    }
    return result;
}

int main()
{
    const string s = "abc";
    cout << convert(s, 1) << endl;
    return 0;
}