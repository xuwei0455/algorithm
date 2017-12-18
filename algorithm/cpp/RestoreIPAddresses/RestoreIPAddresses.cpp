// Number     : 93 
// Title      : Restore IP Addresses
// Source     : https://leetcode.com/problems/restore-ip-addresses/description/
// Tags       : String
// Difficulty : Medium
// Author     : William
// Date       : 2017-12-18


/**********************************************************************************
*
* Given a string containing only digits, restore it by returning all possible valid
* IP address combinations.
*
* For example:
* Given "25525511135",
*
* return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*
**********************************************************************************/

#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool
isValid(string s)
{
    if (atoi(s.c_str()) > 255 || s[0] == '0' && s.size() > 1)
        return false;
    return true;
}


vector<string>
restoreIpAddresses(string s)
{
    vector<string> res;
    int len = s.size();

    for (int i = 1; i < 4 && i < len - 2; i++)
    {
        for (int j = i + 1; j < i + 4 && j < len - 1; j++)
        {
            for (int k = j + 1; k < j + 4 && k < len; k++)
            {
                if (len - k > 3)
                    continue;
                string a = s.substr(0, i);
                string b = s.substr(i, j - i);
                string c = s.substr(j, k - j);
                string d = s.substr(k, len - k);

                if (isValid(a) && isValid(b) && isValid(c) && isValid(d))
                    res.push_back(a + '.' + b + '.' + c + '.' + d);
            }
        }
    }
    return res;
}

int main()
{
    const string s = "25525511135";
    auto result = restoreIpAddresses(s);

    cout << s << endl;
    for (auto i = 0; i < result.size(); i++) {
        cout << '\t' << result[i] << endl;
    }
    return 0;
}