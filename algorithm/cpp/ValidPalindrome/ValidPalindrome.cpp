// Number     : 125 
// Title      : Valid Palindrome
// Source     : https://leetcode.com/problems/valid-palindrome/description/
// Tags       : String
// Difficulty : Easy
// Author     : William
// Date       : 2017-12-18


/**********************************************************************************
*
* Given a string, determine if it is a palindrome, considering only alphanumeric characters 
* and ignoring cases.
* 
* For example,
* "A man, a plan, a canal: Panama" is a palindrome.
* "race a car" is not a palindrome.
* 
* Note:
* Have you consider that the string might be empty? This is a good question to ask during an interview.
* 
* For the purpose of this problem, we define empty string as valid palindrome.
*
**********************************************************************************/

#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool
isPalindrome(string s)
{
    auto i = 0;
    int j = s.size() - 1;

    // it's better to no use equals with
    while (i < j)
    {
        if (!isalnum(s[i])) i++;
        else if (!isalnum(s[j])) j--;
        else
            if (tolower(s[i++]) != tolower(s[j--])) return false;
    }
    return true;
}


int main()
{
    const string s = "aa";

    cout << isPalindrome(s) << endl;
    return 0;
}