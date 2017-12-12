// Number     : 13 
// Title      : Roman to Integer
// Source     : https://leetcode.com/problems/roman-to-integer/description/
// Tags       : String
// Difficulty : Easy
// Author     : William
// Date       : 2017-12-12


/**********************************************************************************
*
* Given a roman numeral, convert it to an integer.
*
* Input is guaranteed to be within the range from 1 to 3999.
*
**********************************************************************************/

#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;


//M = ["", "M", "MM", "MMM"]
//C = ["", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"]
//X = ["", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"]
//I = ["", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"]
int
romanToInt(string s) {
    unordered_map<char, int> m = { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };

    int result = 0;
    for (auto i = 1; i < s.size(); i++)
    {
        if (m[s[i]] > m[s[i - 1]])
        {
            result -= m[s[i - 1]];
        }
        else
        {
            result += m[s[i - 1]];
        }
    }
    result += m[s[s.size() - 1]];
    return result;
}

int main()
{
    const string s = "CXXII";
    cout << romanToInt(s) << endl;
    return 0;
}