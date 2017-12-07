// Number     : 57 
// Title      : Insert Interval
// Source     : https://leetcode.com/problems/insert-interval/description/
// Difficulty : Hard
// Author     : William
// Date       : 2017-12-07


/**********************************************************************************
*
*
* Given a set of non - overlapping intervals, insert a new interval into the intervals(merge if necessary).
*
* You may assume that the intervals were initially sorted according to their start times.
*
* Example 1:
* Given intervals[1, 3], [6, 9], insert and merge[2, 5] in as[1, 5], [6, 9].
*
* Example 2 :
*     Given[1, 2], [3, 5], [6, 7], [8, 10], [12, 16], insert and merge[4, 9] in as[1, 2], [3, 10], [12, 16].
*
*     This is because the new interval[4, 9] overlaps with[3, 5], [6, 7], [8, 10].
*
**********************************************************************************/

# include <vector>
# include <algorithm>
# include <iostream>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};


vector<Interval>
insert(vector<Interval>& intervals, Interval newInterval)
{
    vector<Interval> result;

    if (intervals.size() == 0) { intervals.push_back(newInterval); return intervals; }

    auto i = intervals.begin();
    for (; i != intervals.end(); ++i)
    {
        // rest intervals will not overlap with newInterval
        if ((*i).start > newInterval.end)
            break;
        // *i not overlap
        else if ((*i).end < newInterval.start)
            result.push_back((*i));
        else
        {
            // expand newInterval cause of overlap
            newInterval.start = min((*i).start, newInterval.start);
            newInterval.end = max((*i).end, newInterval.end);
        }
    }

    // push back expanded newInterval or not overlaped.
    result.push_back(newInterval);
    // push back rest intervals.
    for (; i != intervals.end(); ++i)
    {
        result.push_back((*i));
    }

    return result;
}

int main(int argc, char**argv)
{
    const Interval i1(1, 2);
    const Interval i2(3, 5);
    const Interval i3(6, 7);
    const Interval i4(8, 10);
    const Interval i5(12, 16);
    vector<Interval> intervals;
    intervals.push_back(i1);
    intervals.push_back(i2);
    intervals.push_back(i3);
    intervals.push_back(i4);
    intervals.push_back(i5);

    const Interval n(4, 9);
    auto r = insert(intervals, n);

    for (auto i = 0; i < r.size(); i++) {
        cout << "[ " << r[i].start << ", " << r[i].end << " ] ";
    }
    cout << endl;

    return 0;
}