#include <iostream>
#include <string>
#include <math.h>
#include <limits.h>

using namespace std;

class Solution {
 public:
  int divide(int dividend, int divisor) {
    unsigned int udividend = std::abs(dividend);
    unsigned int udivisor = std::abs(divisor);
    if (udividend < udivisor || udividend == 0) {
      return 0;
    }

    int sign = 1;
    if ((dividend < 0 && divisor >= 0) || (dividend >= 0 && divisor < 0)) {
      sign = -1;
    }
    unsigned int ures = divide(udividend, udivisor);

    int res = 0;
    if (ures > INT_MAX) {
      res = (sign == 1) ? INT_MAX : INT_MIN;
    } else {
      res = sign * (int)ures;
    }
    return res;
  }

  unsigned int divide(unsigned int udividend, unsigned int udivisor) {
    if (udividend < udivisor) {
      return 0;
    }
    unsigned int sum = udivisor;
    unsigned int res = 1;
    while (udividend >= (sum + sum)) {
      if (sum >= INT_MAX) {
        break;
      }
      sum += sum;
      res += res;
    }
    return res + divide(udividend - sum, udivisor);
  }
};

int main() {
  Solution s;
  cout << s.divide(10, 3) << endl;  // Output: 3
  cout << s.divide(7, -3) << endl;  // Output: -2

  cout << "0/2=" << s.divide(0, 2) << endl;
  cout << "10/2=" << s.divide(10, 2) << endl;
  cout << "10/3=" << s.divide(10, 3) << endl;
  cout << "10/5=" << s.divide(10, 5) << endl;
  cout << "10/7=" << s.divide(10, 7) << endl;
  cout << "10/10=" << s.divide(10, 10) << endl;
  cout << "10/11=" << s.divide(10, 11) << endl;
  cout << "-1/1=" << s.divide(1, -1) << endl;
  cout << "1/-1=" << s.divide(1, -1) << endl;
  cout << "-1/-1=" << s.divide(-1, -1) << endl;
  cout << "2147483647/1=" << s.divide(2147483647, 1) << endl;
  cout << "-2147483647/1=" << s.divide(-2147483647, 1) << endl;
  cout << "2147483647/-1=" << s.divide(2147483647, -1) << endl;
  cout << "-2147483647/-1=" << s.divide(-2147483647, -1) << endl;
  cout << "2147483647/2=" << s.divide(2147483647, 2) << endl;
  cout << "2147483647/10=" << s.divide(2147483647, 10) << endl;
  cout << "-2147483648/1=" << s.divide(-2147483648, 1) << endl;
  cout << "-2147483648/-1=" << s.divide(-2147483648, -1) << endl;
  int a = -2147483648;
  cout << "-2147483648/-2147483648=" << s.divide(a, a) << endl;
  return 0;
}
