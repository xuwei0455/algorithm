// Number     : 126 
// Title      : Word Ladder II
// Source     : https://leetcode.com/problems/word-ladder-ii/description/
// Tags       : String
// Difficulty : Hard
// Author     : William
// Date       : 2017-12-18


/**********************************************************************************
*
* Given two words (beginWord and endWord), and a dictionary's word list, find all shortest
* transformation sequence(s) from beginWord to endWord, such that:
*
* Only one letter can be changed at a time
* Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
*
* For example,
*
* Given:
*   beginWord = "hit"
*   endWord = "cog"
*   wordList = ["hot","dot","dog","lot","log","cog"]
*
* Return
*   [
*       ["hit","hot","dot","dog","cog"],
*       ["hit","hot","lot","log","cog"]
*   ]
*
* Note:
*   Return an empty list if there is no such transformation sequence.
*   All words have the same length.
*   All words contain only lowercase alphabetic characters.
*   You may assume no duplicates in the word list.
*   You may assume beginWord and endWord are non-empty and are not the same.
*
**********************************************************************************/

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <set>

using namespace std;
// Solution
//
//      1) Using BSF algorithm build a tree like below
//      2) Using DSF to parse the tree to the transformation path.
//
// For example:
//
//     start = "hit"
//     end = "cog"
//     dict = ["hot","dot","dog","lot","log","dit","hig", "dig"]
//
//                      +-----+
//        +-------------+ hit +--------------+
//        |             +--+--+              |
//        |                |                 |
//     +--v--+          +--v--+           +--v--+
//     | dit |    +-----+ hot +---+       | hig |
//     +--+--+    |     +-----+   |       +--+--+
//        |       |               |          |
//        |    +--v--+         +--v--+    +--v--+
//        +----> dot |         | lot |    | dig |
//             +--+--+         +--+--+    +--+--+
//                |               |          |
//             +--v--+         +--v--+       |
//        +----> dog |         | log |       |
//        |    +--+--+         +--+--+       |
//        |       |               |          |
//        |       |    +--v--+    |          |
//        |       +--->| cog |<-- +          |
//        |            +-----+               |
//        |                                  |
//        |                                  |
//        +----------------------------------+
map<string, unordered_set<string>>&
buildTree(string& start, string& end, vector<string> &dict)
{
    static map<string, unordered_set<string>> parents;
    parents.clear();

    unordered_set<string> words(dict.begin(), dict.end());

    unordered_set<string> previous_level;
    unordered_set<string> current_level;
    unordered_set<string> new_level;
    unordered_set<string> temp;

    current_level.insert(start);
    auto reach_end = false;
    while (!reach_end)
    {
        new_level.clear();
        for (auto it = current_level.begin(); it != current_level.end(); ++it) {
            for (auto i = 0; i < it->size(); i++) {
                string new_word = *it;
                for (auto c = 'a'; c <= 'z'; c++) {
                    new_word[i] = c;
                    if (words.count(new_word) == 0 || current_level.count(new_word) > 0 || previous_level.count(new_word) > 0) {
                        continue;
                    }

                    if (new_word == end) {
                        reach_end = true;
                        parents[*it].insert(end);
                        continue;
                    }
                    new_level.insert(new_word);
                    //parents[newWord].insert(*it);
                    parents[*it].insert(new_word);
                }
            }
        }
        if (new_level.empty()) break;

        temp = previous_level;
        previous_level = current_level;
        current_level = new_level;
        new_level = temp;
    }


    if (!reach_end) {
        parents.clear();
    }
    return parents;
}


void
generatePath(const string start, const string end,
    map<string, unordered_set<string>>& parents,
    vector<string>& path,
    vector<vector<string>>& ladders)
{
    if (start == end)
    {
        ladders.push_back(path);
        return;
    }

    for (auto it = parents[start].begin(); it != parents[start].end(); ++it)
    {
        path.push_back(*it);
        generatePath(*it, end, parents, path, ladders);
        path.pop_back();
    }
}


vector<vector<string>>
findLadders(string start, string end, vector<string>& dict)
{
    vector<vector<string>> ladders;

    map<string, unordered_set<string>>& parents = buildTree(start, end, dict);
    if (parents.size() <= 0)
        return ladders;

    vector<string> path;
    path.push_back(start);
    generatePath(start, end, parents, path, ladders);
    return ladders;
}


void
printLadders(vector<vector<string>>& ladders)
{
    int j;
    for (auto i = 0; i < ladders.size(); i++) {
        for (j = 0; j < ladders[i].size() - 1; j++) {
            cout << ladders[i][j] << " -> ";
        }
        cout << ladders[i][j] << endl;
    }
}

int main()
{
    const string start = "hit";
    const string end = "cog";
    vector<string> dict({ "hot", "dot", "dog", "lot", "log", "cog" });

    auto ladders = findLadders(start, end, dict);
    printLadders(ladders);
    return 0;
}