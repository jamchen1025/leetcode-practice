/********************************************************************************** 
題目：
https://leetcode.com/problems/sqrtx/description/
Implement int sqrt(int x).
Compute and return the square root of x, 
where x is guaranteed to be a non-negative integer.
Since the return type is an integer, 
the decimal digits are truncated and only the integer part of 
the result is returned.
Example 1:
Input: 4
Output: 2
Example 2:
Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since 
             the decimal part is truncated, 2 is returned.
**********************************************************************************
想法：
從1開始做i*i
**********************************************************************************/
#include <iostream>
#include <string>
using namespace std;

class Solution {
 public:
  int mySqrt(int x) {
    if (x <= 0) {
      return 0;
    }
    int low = 1;
    int high = x;
    while (low <= high) {
      long mid = low + (high - low) / 2;
      if (x == mid * mid) {
        return (int)mid;
      } else if (x < mid * mid) {
        high = (int)mid - 1;
      } else {
        low = (int)mid + 1;
      }
    }
    return (high * high < x) ? high : low;
  }
};

int main() {
  Solution s;
  cout << s.mySqrt(4) << endl;
  cout << s.mySqrt(2147483647) << endl;

  return 0;
}

