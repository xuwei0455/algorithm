// Number     : 349 
// Title      : Intersection of Two Arrays
// Source     : https://leetcode.com/problems/intersection-of-two-arrays/description/
// Tags       : Sort
// Difficulty : Easy
// Author     : William
// Date       : 2017-12-11


/**********************************************************************************
*
* Given two arrays, write a function to compute their intersection.
* 
* Example:
* Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
* 
* Note:
* Each element in the result must be unique.
* The result can be in any order.
* 
*
**********************************************************************************/


#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

vector<int> 
intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> m(nums1.begin(), nums1.end());

    vector<int> res;
    for (auto i: nums2)
    {
        if (m.count(i))
        {
            res.push_back(i);
            m.erase(i);
        }
    }
    return res;
}

void
printArray(vector<int>& nums)
{
    for (auto i : nums)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> nums1 = { 1, 3, 4, 5, 2, 6, 7, 8, 9 };
    vector<int> nums2 = { 1, 3 };
    auto res = intersection(nums1, nums2);
    printArray(res);
    return 0;
}
