// Number     : 274
// Title      : H-Index
// Source     : https://leetcode.com/problems/h-index/description/
// Tags       : Sort
// Difficulty : Medium
// Author     : William
// Date       : 2017-12-11


/**********************************************************************************
*
* Given an array of citations (each citation is a non-negative integer) of a researcher,
* write a function to compute the researcher's h-index.
*
* According to the definition of h-index on Wikipedia: "A scientist has index h if h of
* his/her N papers have at least h citations each, and the other N − h papers have no more
* than h citations each."
*
* For example, given citations = [3, 0, 6, 1, 5], which means the researcher has 5 papers
* in total and each of them had received 3, 0, 6, 1, 5 citations respectively. Since the
* researcher has 3 papers with at  *least 3 citations each and the remaining two with no more
* than 3 citations each, his h-index is 3.
*
* Note: If there are several possible values for h, the maximum one is taken as the h-index.
*
* Credits:
* Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*
**********************************************************************************/

# include<vector>
# include<iostream>
# include<algorithm>

using namespace std;


/*
* Solutions
* =========
*
* A simple solution would be to sort the vector and then run through it starting with
* the last element. At every step we need to check whether this element is not less than
* the remaining number of elements bigger than it(including itself) and all the values of
* the other elements smaller than it are not more than that number. The h_index is this
* number of elements bigger than it(including itself).
*
* Time Complexity: O(N log N)
* Space Complexity: O(1)
*
*/
int
hIndex(vector<int>& citations) {

    sort(citations.begin(), citations.end());

    auto h_index = 0;
    const int n = citations.size();
    for (auto i = 0; i < n; i++) {
        if (citations[i] >= n - i) {
            return n - i;
        }
    }
    return 0;
}


int main()
{
    vector<int> a = { 3, 0, 6, 1, 5 };
    const auto h_index = hIndex(a);
    cout << h_index << endl;
    return 0;
}
