// Number     : 38 
// Title      : Count and Say
// Source     : https://leetcode.com/problems/count-and-say/description/
// Tags       : String
// Difficulty : Easy
// Author     : William
// Date       : 2017-12-14


/**********************************************************************************
*
* The count-and-say sequence is the sequence of integers with the first five terms as following:
*   1.     1
*   2.     11
*   3.     21
*   4.     1211
*   5.     111221
*
* 1 is read off as "one 1" or 11.
* 11 is read off as "two 1s" or 21.
* 21 is read off as "one 2, then one 1" or 1211.
* Given an integer n, generate the nth term of the count-and-say sequence.
*
* Note: Each term of the sequence of integers will be represented as a string.
*
* Example 1:
*   Input: 1
*   Output: "1"
*
* Example 2:
*   Input: 4
*   Output: "1211"
*
**********************************************************************************/

#include <string>
#include <iostream>

using namespace std;


void
generate(string& s)
{
    string res;

    auto cur = s[0];
    auto count = 1;
    for (auto i = 1; i < s.size(); i++)
    {
        if (s[i] != cur)
        {
            res += (to_string(count) + cur);
            // reset state
            cur = s[i];
            count = 1;
        }
        else count++;
    }
    res += (to_string(count) + cur);
    s = res;
}


string
countAndSay(int n)
{
    string s = "1";
    while (--n > 0)
    {
        generate(s);
    }
    return s;
}

int main()
{
    const int i = 6;
    cout << countAndSay(i) << endl;
    return 0;
}