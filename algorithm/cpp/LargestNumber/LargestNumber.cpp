// Number     : 179
// Title      : Largest Number
// Source     : https://leetcode.com/problems/largest-number/description/
// Tags       : Sort
// Difficulty : Medium
// Author     : William
// Date       : 2017-12-11


/**********************************************************************************
*
* Given a list of non negative integers, arrange them such that they form the largest number.
* 
* For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
* 
* Note: The result may be very large, so you need to return a string instead of an integer.
* 
* Credits:
* Special thanks to @ts for adding this problem and creating all test cases.
*
**********************************************************************************/

# include <iostream>
# include <vector>
# include <string>
# include <algorithm>

using namespace std;

bool
compare(const string s1, const string s2)
{
    return s1 + s2 > s2 + s1;
}


string 
largestNumber(vector<int>& nums) {
    vector<string> str_v;
    for(auto i: nums)
    {
        str_v.push_back(to_string(i));
    }

    sort(str_v.begin(), str_v.end(), compare);

    //special case: start with zero (e.g. [0, 0])
    if (str_v[0] == "0") return "0";

    string result;
    for(const auto s: str_v)
    {
        result += s;
    }
    return result;
}



int main()
{
    vector<int> a = { 3, 30, 34, 5, 9 };
    const auto s = largestNumber(a);
    cout << s << endl;
    return 0;
}