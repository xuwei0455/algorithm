// Number     : 30 
// Title      : Substring with Concatenation of All Words
// Source     : https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/
// Tags       : String
// Difficulty : Hard
// Author     : William
// Date       : 2017-12-13


/**********************************************************************************
*
* You are given a string, s, and a list of words, words, that are all of the same length.
* Find all starting indices of substring(s) in s that is a concatenation of each word in words
* exactly once and without any intervening characters.
*
* For example, given:
*   s: "barfoothefoobarman"
*   words: ["foo", "bar"]
*
* You should return the indices: [0,9].
* (order does not matter).
*
**********************************************************************************/

#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int>
findSubstring(string str, vector<string>& words)
{
    vector<int> indexes;
    // no words need to match
    if (words.size() == 0) return indexes;

    // travel all words
    unordered_map<string, int> counter;
    for (const auto w : words) counter[w]++;

    const int n = str.size();
    // words in array must occur only once
    const int num = words.size();
    const int len = words[0].size();

    // end condition is shorter than min length which can has substring
    for (auto i = 0; i < n - num * len + 1; i++)
    {
        unordered_map<string, int> seen;

        auto j = 0;
        for (; j < num; j++)
        {
            const auto word = str.substr(i + j * len, len);
            if (counter.find(word) != counter.end())
            {
                seen[word]++;
                if (seen[word] > counter[word]) break;
            }
            else break;
        }
        if (j == num)indexes.push_back(i);
    }
    return indexes;
}



int main()
{
    string s = "barfoobarfoothefoobarman";
    vector<string> l;
    l.push_back("foo");
    l.push_back("bar");
    l.push_back("foo");

    vector<int> indics = findSubstring(s, l);

    for (int i = 0; i < indics.size(); i++) {
        cout << indics[i] << " ";
    }
    cout << endl;

    return 0;
}