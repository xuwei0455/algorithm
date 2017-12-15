// Number     : 68 
// Title      : Text Justification
// Source     : https://leetcode.com/problems/text-justification/description/
// Tags       : String
// Difficulty : Hard
// Author     : William
// Date       : 2017-12-15


/**********************************************************************************
*
* Given an array of words and a length L, format the text such that each line has exactly
* L characters and is fully (left and right) justified.
*
* You should pack your words in a greedy approach; that is, pack as many words as you can
* in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.
*
* Extra spaces between words should be distributed as evenly as possible. If the number of spaces
* on a line do not divide evenly between words, the empty slots on the left will be assigned
* more spaces than the slots on the right.
*
* For the last line of text, it should be left justified and no extra space is inserted between words.
*
* For example,
* words: ["This", "is", "an", "example", "of", "text", "justification."]
* L: 16.
*
* Return the formatted lines as:
*   [
*       "This    is    an",
*       "example  of text",
*       "justification.  "
*   ]
*
* Note: Each word is guaranteed not to exceed L in length.
*
**********************************************************************************/

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// there's a unintelligible problem in leetcode
// it's wrong when i use '+=' to concat string
// but right for 'insert' method.
vector<string>
fullJustify(vector<string>& words, int maxWidth)
{
    vector<string> res;
    vector<string> temp;

    // return empty input
    if (maxWidth == 0) { res.push_back(""); return res; }

    auto len = 0;
    for (auto s : words)
    {
        if (len + s.length() > maxWidth)
        {
            // count words' length and remain white space's length
            auto total_len = 0;
            for (auto word : temp) { total_len += word.length(); }
            const auto ws_len = maxWidth - total_len;

            // calculate num of white space to insert
            const int ws_m = ws_len / max(((int)temp.size() - 1), 1);
            int ws_n = ws_len % max(((int)temp.size() - 1), 1);

            string temp_str;
            for (const auto word : temp)
            {
                temp_str += word;
                temp_str.insert(temp_str.end(), (ws_m + ((ws_n != 0) ? 1 : 0)), ' ');
                if (ws_n != 0) ws_n--;
            }
            res.push_back(temp_str.substr(0, maxWidth));

            len = 0;
            temp.clear();
        }
        temp.push_back(s);
        len += (s.length() + 1);
    }

    string last;
    for (const auto s : temp) { last += (s + string(" ", 1)); }
    last.insert(last.end(), (maxWidth > last.length() ? maxWidth - last.length() : 0), ' ');
    res.push_back(last.substr(0, maxWidth));
    return res;
}


void
printVector(vector<string> &words, bool newline = false)
{
    for (int i = 0; i < words.size(); i++)
    {
        cout << "\"" << words[i] << "\", ";
        if (newline) cout << endl;
    }
    cout << endl;
}


int main()
{
    vector<string> words = { "Listen","to","many,","speak","to","a","few." };
    const int length = 6;
    auto res = fullJustify(words, length);
    printVector(res);
    return 0;
}