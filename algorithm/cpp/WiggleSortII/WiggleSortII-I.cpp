// Number     : 324 
// Title      : Wiggle Sort II
// Source     : https://leetcode.com/problems/wiggle-sort-ii/description/
// Tags       : Sort
// Difficulty : Medium
// Author     : William
// Date       : 2017-12-11


/**********************************************************************************
*
* Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
*
* Example:
* (1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6].
* (2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].
*
* Note:
* You may assume all input has valid answer.
*
* Follow Up:
* Can you do it in O(n) time and/or in-place with O(1) extra space?
*
* Credits:
* Special thanks to @dietpepsi for adding this problem and creating all test cases.
*
**********************************************************************************/


//
// Solution - O(N*logN)
// --------------------
// 1) Sorting the array with descending order
//
// 2) Split the sorted array into two parts,
//    and insert the 2nd half array into the 1st half array
//
//    For example: [ 9 8 7 6 5  4 3 2 1 0  ]
//
//  
//        1st Large half:    . 9 . 8 . 7 . 6 . 5
//        2nd Small half:    4 . 3 . 2 . 1 . 0 .
//        ---------------------------------------
//                Result:    4 9 3 8 2 7 1 6 0 5
//
// Be careful if the length of array is odd number, 
// Such as: [5 4 3 2 1], 
// The 2nd half is [3 2 1] instead of [2 1]
// 

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void
wiggleSort(vector<int>& nums)
{
    sort(nums.begin(), nums.end(), [](int x, int y) {return x > y; });

    const int half = nums.size() / 2;
    for (auto i = 0; i < half; i++)
    {
        auto v = nums[i];
        nums.insert(nums.begin() + half + (2 * i) + 1, v);
    }

    nums = vector<int>(nums.begin() + half, nums.end());
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
    vector<int> nums = { 1, 3, 4, 5, 2, 6, 7, 8, 9 };
    wiggleSort(nums);
    printArray(nums);
    return 0;
}
