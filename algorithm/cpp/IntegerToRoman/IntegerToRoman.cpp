// Number     : 12 
// Title      : Integer to Roman
// Source     : https://leetcode.com/problems/integer-to-roman/description/
// Tags       : String
// Difficulty : Medium
// Author     : William
// Date       : 2017-12-12


/**********************************************************************************
*
* Given an integer, convert it to a roman numeral.
*
* Input is guaranteed to be within the range from 1 to 3999.
*
**********************************************************************************/

#include <string>
#include <iostream>
#include <vector>

using namespace std;


string
intToRoman(int num) {

    vector<string> M = { "", "M", "MM", "MMM" };
    vector<string> C = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
    vector<string> X = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
    vector<string> I = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
    return M[num / 1000] + C[num % 1000 / 100] + X[num % 100 / 10] + I[num % 10];
}

int main()
{
    const int n = 122;
    cout << intToRoman(n) << endl;
    return 0;
}