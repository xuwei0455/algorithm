// Number     : 71 
// Title      : Simplify Path
// Source     : https://leetcode.com/problems/simplify-path/description/
// Tags       : String
// Difficulty : Medium
// Author     : William
// Date       : 2017-12-16


/**********************************************************************************
*
* Given an absolute path for a file (Unix-style), simplify it.
*
* For example,
* path = "/home/", => "/home"
* path = "/a/./b/../../c/", => "/c"
*
* Corner Cases:
*   Did you consider the case where path = "/../"?
*   In this case, you should return "/".
*   Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
*   In this case, you should ignore redundant slashes and return "/home/foo".
*
*
**********************************************************************************/

#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

// it's much diffkerent to what do i think about this problem
// it's allow multi '.' in sub dir, so it's hard to use
// ciculation read each character to compelte this.
string
simplifyPath(string path)
{
    string res, tmp;
    vector<string> stk;
    stringstream ss(path);
    while (getline(ss, tmp, '/'))
    {
        if (tmp == "." || tmp == "") { continue; }
        if (tmp == "..") { if (!stk.empty()) stk.pop_back(); }
        else stk.push_back(tmp);
    }
    for (const auto s : stk) { res += ("/" + s); }
    return res.empty() ? "/" : res;
}

int main()
{
    const string path("/...");
    cout << path << " : " << simplifyPath(path) << endl;
    return 0;
}