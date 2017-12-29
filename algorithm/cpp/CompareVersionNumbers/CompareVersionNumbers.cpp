// Number     : 165 
// Title      : Compare Version Numbers
// Source     : https://leetcode.com/problems/compare-version-numbers/description/
// Tags       : String
// Difficulty : Medium
// Author     : William
// Date       : 2017-12-29


/**********************************************************************************
*
* Compare two version numbers version1 and version2.
* If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
*
* You may assume that the version strings are non-empty and contain only digits and the . character.
* The . character does not represent a decimal point and is used to separate number sequences.
* For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth
* second-level revision of the second first-level revision.
*
* Here is an example of version numbers ordering:
*
* 0.1 < 1.1 < 1.2 < 13.37
* Credits:
* Special thanks to @ts for adding this problem and creating all test cases.
*
**********************************************************************************/

#include <string>
#include <iostream>
#include <vector>

using namespace std;


int
compareVersion(string version1, string version2)
{
    auto i = 0;
    auto j = 0;

    const int n1 = version1.size();
    const int n2 = version2.size();

    auto num1 = 0;
    auto num2 = 0;

    while (i < n1 || j < n2)
    {
        while (i < n1 && version1[i] != '.')
        {
            num1 = num1 * 10 + (version1[i] - '0');
            i++;
        }

        while (j < n2 && version2[j] != '.')
        {
            num2 = num2 * 10 + (version2[j] - '0');
            j++;
        }

        if (num1 > num2) return 1;
        if (num1 < num2) return -1;

        // reset num to avoid 'x' compare 'x.0'
        num1 = 0; num2 = 0;
        i++; j++;
    }
    return 0;
}

int main()
{

    string v1 = "1.1";
    string v2 = "1.10";
    cout << compareVersion(v1, v2) << endl;
    return 0;
}