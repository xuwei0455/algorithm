// Number     : 242
// Title      : Valid Anagram
// Source     : https://leetcode.com/problems/valid-anagram/description/
// Tags       : Sort
// Difficulty : Easy
// Author     : William
// Date       : 2017-12-11


/**********************************************************************************
*
* Given two strings s and t, write a function to determine if t is an anagram of s.
* 
* For example,
* s = "anagram", t = "nagaram", return true.
* s = "rat", t = "car", return false.
* 
* Note:
* You may assume the string contains only lowercase alphabets.
* 
* Follow up:
* What if the inputs contain unicode characters? How would you adapt your solution to such case?
*
**********************************************************************************/

# include<string>
# include<iostream>
# include<unordered_map>

using namespace std;

bool isAnagram(string s, string t) {

    unordered_map<char, int> data;
    for (auto c: s)
    {
        data[c]++;
    }

    for (auto c: t)
    {
        data[c]--;
    }

    for(const auto i: data)
    {
        if (i.second != 0)
        {
            return false;
        }
    }
    return true;
}


int main()
{
    const string s = "anagram";
    const string t = "nagaram";
    const auto res = isAnagram(s, t);
    cout << res << endl;
    return 0;
}