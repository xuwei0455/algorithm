// Number     : 56 
// Title      : Merge Intervals
// Source     : https://leetcode.com/problems/merge-intervals/description/
// Tags       : Sort
// Difficulty : Medium
// Author     : William
// Date       : 2017-12-06


/**********************************************************************************
*
* Given a collection of intervals, merge all overlapping intervals.
*
* For example,
* Given [1,3],[2,6],[8,10],[15,18],
* return [1,6],[8,10],[15,18].
*
*
**********************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};


bool
compare(const Interval& lhs, const Interval& rhs)
{
    return (lhs.start == rhs.start) ? lhs.end < rhs.end : lhs.start < rhs.start;
}


vector<Interval>
merge(vector<Interval>& intervals)
{
    vector<Interval> result;
    if (intervals.size() <= 0) return result;

    // sort the intervals. NB: using the customized comparing function
    sort(intervals.begin(), intervals.end(), compare);
    for (unsigned i = 0; i < intervals.size(); i++)
    {
        const auto size = result.size();
        // if the current interval is overlapped with the previous interval.
        // merge the intervals.
        if (size > 0 && intervals[i].start <= result[size - 1].end)
            result[size - 1].end = max(result[size - 1].end, intervals[i].end);
        else
            result.push_back(intervals[i]);
    }
    return result;
}


int main(int argc, char**argv)
{
    const Interval i1(1, 4);
    const Interval i2(0, 4);
    //const Interval i3(8, 10);
    //const Interval i4(15, 18);
    vector<Interval> intervals;
    intervals.push_back(i1);
    intervals.push_back(i2);
    //intervals.push_back(i3);
    //intervals.push_back(i4);

    auto r = merge(intervals);

    for (auto i = 0; i < r.size(); i++) {
        cout << "[ " << r[i].start << ", " << r[i].end << " ] ";
    }
    cout << endl;

    return 0;
}