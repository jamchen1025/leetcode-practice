#include <iostream>
#include <string>
#include <limits.h>

using namespace std;

class Solution {
 public:
  int myAtoi(string str) {
    if (str.size() == 0) {
      return 0;
    }

    int index = 0;
    for (; isspace(str[index]); ++index)
      ;

    bool sign = true;
    if (str[index] == '+' || str[index] == '-') {
      sign = (str[index] == '+') ? true : false;
      index++;
    }

    int result = 0;
    int num;
    for (; isdigit(str[index]); ++index) {
      num = str[index] - '0';

      if (sign == true) {
        if (result > (INT_MAX - num) / 10) {
          return INT_MAX;
        }
      } else {
        if (-result < (INT_MIN + num) / 10) {
          return INT_MIN;
        }
      }

      result = result * 10 + num;
    }

    return (sign == true) ? result : -result;
  }
};

int main() {
  Solution s;

  cout << s.myAtoi("42") << endl; // Output: 42

  cout << s.myAtoi("   -42") << endl; // Output: -42
  // Explanation: The first non-whitespace character is '-', which is the minus
  // sign. Then take as many numerical digits as possible, which gets 42.

  cout << s.myAtoi("4193 with words") << endl; // Output: 4193
  // Explanation: Conversion stops at digit '3' as the next character is not a
  // numerical digit.

  cout << s.myAtoi("words and 987") << endl; // Output: 0
  // Explanation: The first non-whitespace character is 'w', which is not a
  // numerical digit or a +/- sign. Therefore no valid conversion could be
  // performed.

  cout << s.myAtoi("-91283472332") << endl; // Output: -2147483648
  // Explanation: The number "-91283472332" is out of the range of a 32-bit
  // signed integer. Thefore INT_MIN is returned.
  return 0;
}
