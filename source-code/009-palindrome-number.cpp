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
