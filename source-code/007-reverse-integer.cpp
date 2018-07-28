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
  cout << s.reverse(0) << endl;     // Output: 0
  return 0;
}
