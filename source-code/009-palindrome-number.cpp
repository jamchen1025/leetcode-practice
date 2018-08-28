/**********************************************************************************
題目：
https://leetcode.com/problems/palindrome-number/description/
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
Example 1:
Input: 121
Output: true
Example 2:
Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:
Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
**********************************************************************************
想法：
判斷是否是小於0，是的話直接回傳false
如果不是的話就進行轉換，
方法是用whlie還有%做數字轉換，從個位數*10累加起來，看兩者數字有沒有一樣
**********************************************************************************/
#include <iostream>
#include <string>
#include <limits.h>

using namespace std;

class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0) {
      return false;
    }

    int origin = x;
    int reverse = 0;
    int n;
    while (x != 0) {
      n = x % 10;
      reverse = reverse * 10 + n;
      x /= 10;
    }
    return (origin == reverse);
  }
};

int main() {
  Solution s;
  cout << s.isPalindrome(121) << endl; // Output: true

  cout << s.isPalindrome(-121) << endl; // Output: false
  // Explanation: From left to right, it reads -121. From right to left, it
  // becomes 121-. Therefore it is not a palindrome.

  cout << s.isPalindrome(10) << endl; // Output: false
  // Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

  return 0;
}
