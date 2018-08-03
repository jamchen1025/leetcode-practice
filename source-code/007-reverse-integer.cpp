/**********************************************************************************
題目：
https://leetcode.com/problems/reverse-integer/description/
Given a 32-bit signed integer, reverse digits of an integer.
Example 1:
Input: 123
Output: 321
Example 2:
Input: -123
Output: -321
Example 3:
Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers 
within the 32-bit signed integer range: [−231,  231 − 1]. 
For the purpose of this problem, assume that your function returns 0 
when the reversed integer overflows.
**********************************************************************************
想法：
正常的mod和除法即可
注意要考慮怎麼知道sum超出範圍的情況
可以用unsign int 擴大範圍
**********************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <limits.h>

using namespace std;

class Solution {
 public:
  int reverse(int x) {
    bool sign = (x > 0);
    int result = 0;
    int num;
    while (x != 0) {
      num = x % 10;
      if (sign == true) {
        if (result > (INT_MAX - num) / 10) {
          return 0;
        }
      } else {
        if (result < (INT_MIN - num) / 10) {
          return 0;
        }
      }

      result = result * 10 + num;
      x = x / 10;
    }
    return result;
  }
};

int main() {
  Solution s;
  cout << s.reverse(123) << endl;   // Output: 321
  cout << s.reverse(-123) << endl;  // Output: -321
  cout << s.reverse(123) << endl;   // Output: 21
  cout << s.reverse(0) << endl;     // Output: 0
  cout << s.reverse(1534236469) << endl;      // Output: 0
  cout << s.reverse(-1534236469) << endl;     // Output: 0
  cout << s.reverse(-2147483648) << endl;     // Output: 0
  cout << s.reverse(1463847412) << endl;      // Output: 2147483641
    
  return 0;
}
