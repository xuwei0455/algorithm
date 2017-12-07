// Number     : 75 
// Title      : Sort Colors
// Source     : https://leetcode.com/problems/sort-colors/description/
// Tags       : Sort
// Difficulty : Medium
// Author     : William
// Date       : 2017-12-07


/**********************************************************************************
*
* Given an array with n objects colored red, white or blue, sort them so that objects of the
* same color are adjacent, with the colors in the order red, white and blue.
*
* Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
*
* Note:
* You are not suppose to use the library's sort function for this problem.
*
* Follow up:
*  > A rather straight forward solution is a two-pass algorithm using counting sort.
*  > First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array
*    with total number of 0's, then 1's and followed by 2's.
*  > Could you come up with an one-pass algorithm using only constant space?
*
**********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

void
swap(int* a, int* b)
{
    const auto t = *a;
    *a = *b;
    *b = t;
}

void
PrintArray(const vector<int>& a, const int n) {
    for (auto i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void
sortColors(vector<int>& nums) {
    auto start = 0;
    int end = nums.size() - 1;
    for (auto i = 0; i <= end; i++)
    {
        if (nums[i] == 0)
        {
            swap(&nums[i], &nums[start]);
            ++start;
        }
        else if (nums[i] == 2)
        {
            swap(&nums[i], &nums[end]);
            --end;  
            --i;  // may swap out 0, this need be swaped again
        }
        else;
    }
}

int main(const int argc, char** argv)
{
    auto n = 7;
    if (argc > 1)
        n = atoi(argv[1]);

    srand(time(nullptr));

    auto a = new vector<int>;
    for (auto i = 0; i < n; i++) {
        a->push_back(rand() % 3);
    }

    PrintArray(*a, n);
    sortColors(*a);
    PrintArray(*a, n);

    delete a;
}
