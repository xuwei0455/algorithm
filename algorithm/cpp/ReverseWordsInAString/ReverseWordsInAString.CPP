// Number     : 151 
// Title      : Reverse Words in a String
// Source     : https://leetcode.com/problems/reverse-words-in-a-string/description/
// Tags       : String
// Difficulty : Medium
// Author     : William
// Date       : 2017-12-19


/**********************************************************************************
*
* Given an input string, reverse the string word by word.
* 
* For example,
*   Given s = "the sky is blue",
*   return "blue is sky the".
* 
* Update (2015-02-12):
* For C programmers: Try to solve it in-place in O(1) space.
* 
* Clarification:
* 
* What constitutes a word?
*   A sequence of non-space characters constitutes a word.
* Could the input string contain leading or trailing spaces?
*   Yes. However, your reversed string should not contain leading or trailing spaces.
* How about multiple spaces between two words?
*   Reduce them to a single space in the reversed string.
*
**********************************************************************************/

#include <string>
#include <iostream>

using namespace std;  

void 
reverseWords(string &s) 
{
    reverse(s.begin(), s.end());
    
    auto store_index = 0;
    for (auto i = 0; i < s.size(); i++) {
        if (s[i] != ' ') 
        {
            if (store_index != 0) s[store_index++] = ' ';
            auto j = i;
            while (j < s.size() && s[j] != ' ') { s[store_index++] = s[j++]; }
            reverse(s.begin() + store_index - (j - i), s.begin() + store_index);
            i = j;
        }
    }
    s.erase(s.begin() + store_index, s.end());
}


int main()
{
    string s = "the sky is blue";
    reverseWords(s);
    cout << s << endl;
    return 0;
}