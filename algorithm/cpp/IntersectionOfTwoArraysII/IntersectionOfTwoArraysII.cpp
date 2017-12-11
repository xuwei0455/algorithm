// Number     : 350 
// Title      : Intersection of Two Arrays II
// Source     : https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
// Tags       : Sort
// Difficulty : Easy
// Author     : William
// Date       : 2017-12-11


/**********************************************************************************
*
* Given two arrays, write a function to compute their intersection.
* 
* Example:
* Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].
* 
* Note:
* Each element in the result should appear as many times as it shows in both arrays.
* The result can be in any order.
* Follow up:
* What if the given array is already sorted? How would you optimize your algorithm?
* What if nums1's size is small compared to nums2's size? Which algorithm is better?
* What if elements of nums2 are stored on disk, and the memory is limited such that 
* you cannot load all elements into the memory at once?
*
**********************************************************************************/


#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int>
intersect(vector<int>& nums1, vector<int>& nums2) {

    unordered_map<int, int> m;
    vector<int> res;

    for (auto i: nums1)
    {
        m[i]++;
    }

    for (auto i: nums2)
    {
        if(--m[i] >= 0)
        {
            res.push_back(i);
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
    vector<int> nums1 = { };
    vector<int> nums2 = { 1 };
    auto res = intersect(nums1, nums2);
    printArray(res);
    return 0;
}
