// Number     : 8 
// Title      : String to Integer (atoi)
// Source     : https://leetcode.com/problems/string-to-integer-atoi/description/
// Tags       : String
// Difficulty : Medium
// Author     : William
// Date       : 2017-12-12


/**********************************************************************************
*
* Implement atoi to convert a string to an integer.
*
* Hint: Carefully consider all possible input cases. If you want a challenge, please
* do not see below and ask yourself what are the possible input cases.
*
* Notes: It is intended for this problem to be specified vaguely (ie, no given input specs).
* You are responsible to gather all the input requirements up front.
*
* Update (2015-02-10):
* The signature of the C++ function had been updated. If you still see your function
* signature accepts a const char * argument, please click the reload button  to reset
* your code definition.
*
**********************************************************************************/

#include <string>
#include <iostream>
#include <vector>

using namespace std;

// Some type of cases need to be handle:
// 1. whitespace
// 2. sign of the number
// 3. overflow
// 4. invalid char

int
myAtoi(string str) {
    int i = 0;
    int sign = 1;
    int result = 0;
    // ignore all whilespace front of string
    while (str[i] == ' ') i++;
    // catch the sign of the number
    if (str[i] == '-' || str[i] == '+')
        sign = str[i++] == '-' ? -1 : 1;
    // ignore the invalid input
    while (str[i] >= '0' && str[i] <= '9')
    {
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && str[i] - '0' > 7)) {
            if (sign == 1) return INT_MAX;
            else return INT_MIN;
        }
        result = result * 10 + (str[i++] - '0');
    }
    return sign * result;
}


int main()
{
    const string s = "9223372036854775809";
    cout << myAtoi(s) << endl;
    return 0;
}