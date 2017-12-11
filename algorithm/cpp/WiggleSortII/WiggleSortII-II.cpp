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


#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


//
// After checked the discussion of Leetcode, I found there is a really brilliant idea
// which used a tricky idea - virtual index.
// 
// Please refer to the following link to see the full details:
// https://discuss.leetcode.com/topic/32929/o-n-o-1-after-median-virtual-indexing

void 
wiggleSort(vector<int>& nums) {
    const int n = nums.size();

    // Find a median.
    const auto midptr = nums.begin() + n / 2;
    nth_element(nums.begin(), midptr, nums.end());
    const auto mid = *midptr;

    // Index-rewiring.
    #define A(i) nums[(1+2*(i)) % (n|1)]

    // 3-way-partition-to-wiggly in O(n) time with O(1) space.
    auto i = 0, j = 0, k = n - 1;
    while (j <= k) {
        if (A(j) > mid)
            swap(A(i++), A(j++));
        else if (A(j) < mid)
            swap(A(j), A(k--));
        else
            j++;
    }
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
