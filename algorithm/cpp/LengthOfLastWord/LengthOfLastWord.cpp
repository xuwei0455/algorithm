// Number     : 58 
// Title      : Length of Last Word
// Source     : https://leetcode.com/problems/length-of-last-word/description/
// Tags       : String
// Difficulty : Easy
// Author     : William
// Date       : 2017-12-15


/**********************************************************************************
*
* Given a string s consists of upper/lower-case alphabets and empty space characters ' ', 
* return the length of last word in the string.
* 
* If the last word does not exist, return 0.
* 
* Note: A word is defined as a character sequence consists of non-space characters only.
* 
* Example:
*   Input: "Hello World"
*   Output: 5
*
**********************************************************************************/

#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


int 
lengthOfLastWord(string s) 
{
    int length = 0;
    for (int i = s.size() - 1; i >= 0 ; i--)
    {
        if (s[i] != ' ') { length++; }
        if (s[i] == ' ' && length != 0) { return length; }
    }
    return length;
}


int main()
{
    const string s = "Hello World";
    cout << lengthOfLastWord(s) << endl;
    return 0;
}