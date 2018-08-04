/********************************************************************************** 
題目：
https://leetcode.com/problems/merge-intervals/description/
Given a collection of intervals, merge all overlapping intervals.
Example 1:
Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:
Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considerred overlapping.
**********************************************************************************
想法：
1. 判斷交集的方法：
    用一個result保存目前結果
    當有新的interval進來時就分別判斷start和end是否有跟result裡面的結果交集
    有的話就找最小的start和最大的end形成一個新的interval;
2. 考慮有交集應該怎麼插入，沒有交集應該怎麼插入

**********************************************************************************/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
 public:
  vector<Interval> merge(vector<Interval>& intervals) {
    if (intervals.size() <= 1) {
      return intervals;
    }

    vector<Interval> result;
    result.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); ++i) {
      Interval itv = intervals[i];

      // check start is in interval;
      int s_itv = -1;
      int e_itv = -1;
      for (int i = 0; i < result.size(); ++i) {
        if (isInterval(itv, result[i]) == true) {
          s_itv = i;
          break;
        }
      }
      for (int i = (int)result.size() - 1; i >= 0; --i) {
        if (isInterval(itv, result[i]) == true) {
          e_itv = i;
          break;
        }
      }

      if (s_itv != -1 || e_itv != -1) {
        int s_val =
            (s_itv != -1) ? min(result[s_itv].start, itv.start) : itv.start;
        int e_val = (e_itv != -1) ? max(result[e_itv].end, itv.end) : itv.end;

        int min_i = s_itv > 0 ? s_itv : 0;
        int max_i = e_itv > 0 ? e_itv : 0;
        vector<Interval> temp;
        temp.insert(temp.begin(), result.begin(), result.begin() + min_i);
        temp.push_back(Interval(s_val, e_val));
        temp.insert(temp.end(), result.begin() + max_i + 1, result.end());
        result = temp;
      } else {
        // find a position to insert interval
        int pos = 0;
        for (int j = 0; j < result.size(); ++j) {
          if (result[j].end < itv.start) {
            pos = j + 1;
          } else {
            break;
          }
        }
        result.insert(result.begin() + pos, itv);
      }
    }
    return result;
  }

  bool isInterval(Interval itv_1, Interval itv_2) {
    if (itv_1.start <= itv_2.start && itv_2.start <= itv_1.end) {
      return true;
    }
    if (itv_2.start <= itv_1.start && itv_1.start <= itv_2.end) {
      return true;
    }
    return false;
  }
};

int main() {
  Solution s;

  vector<Interval> input_1{Interval(1, 3), Interval(2, 6), Interval(8, 10),
                           Interval(15, 18)};
  vector<Interval> result_1 = s.merge(input_1);
  for (int i = 0; i < result_1.size(); ++i) {
    cout << result_1[i].start << " " << result_1[i].end << ", ";
  }
  cout << endl;
  // Output: [[1,6],[8,10],[15,18]]
  // Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into
  // [1,6].

  vector<Interval> input_2{Interval(1, 4), Interval(0, 4)};
  vector<Interval> result_2 = s.merge(input_2);
  for (int i = 0; i < result_2.size(); ++i) {
    cout << result_2[i].start << " " << result_2[i].end << ", ";
  }
  cout << endl;
  // Output: [[0,4]]

  vector<Interval> input_3{Interval(1, 4), Interval(0, 5)};
  vector<Interval> result_3 = s.merge(input_3);
  for (int i = 0; i < result_3.size(); ++i) {
    cout << result_3[i].start << " " << result_3[i].end << ", ";
  }
  cout << endl;
  // Output: [[0,5]]

  vector<Interval> input_4{Interval(1, 4), Interval(0, 1)};
  vector<Interval> result_4 = s.merge(input_4);
  for (int i = 0; i < result_4.size(); ++i) {
    cout << result_4[i].start << " " << result_4[i].end << ", ";
  }
  cout << endl;
  // Output: [[0,4]]

  vector<Interval> input_5{Interval(2, 3), Interval(4, 5), Interval(6, 7),
                           Interval(8, 9), Interval(1, 10)};
  vector<Interval> result_5 = s.merge(input_5);
  for (int i = 0; i < result_5.size(); ++i) {
    cout << result_5[i].start << " " << result_5[i].end << ", ";
  }
  cout << endl;
  // Output: [[1,10]]

  vector<Interval> input_6{Interval(2, 3), Interval(5, 5), Interval(2, 2),
                           Interval(3, 4), Interval(3, 4)};
  vector<Interval> result_6 = s.merge(input_6);
  for (int i = 0; i < result_6.size(); ++i) {
    cout << result_6[i].start << " " << result_6[i].end << ", ";
  }
  cout << endl;
  // Output: [[2,4],[5,5]]
  return 0;
}

