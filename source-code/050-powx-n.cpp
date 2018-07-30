#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  double myPow(double x, int n) {
    if (n == 0) {
      return 1;
    }
    double temp = myPow(x, n / 2);
    if ((n % 2) == 0) {
      return temp * temp;
    } else {
      if (n > 0)
        return x * temp * temp;
      else
        return (temp * temp) / x;
    }
  }
};

int main() {
  Solution s;
  cout << s.myPow(2.00000, 10) << endl;  // Output: 1024.00000
  cout << s.myPow(2.10000, 3) << endl;   // Output: 9.26100
  cout << s.myPow(2.00000, -2) << endl;  // Output: 0.25000
  // Explanation: 2^-2 = 1/2^2 = 1/4 = 0.25

  return 0;
}
