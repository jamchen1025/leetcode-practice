#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  string countAndSay(int n) {
    if (n == 0) {
      return "";
    }

    string s = "1";

    if (n == 1) {
      return s;
    }
    for (int i = 2; i <= n; ++i) {
      int count = 1;
      string temp = "";
      int j;
      for (j = 0; j < s.size() - 1; ++j) {
        if (s[j] == s[j + 1]) {
          count++;
        } else {
          char c = '0' + count;
          temp = temp + c + s[j];
          count = 1;
        }
      }

      char c = '0' + count;
      temp = temp + c + s[j];
      s = temp;
    }
    return s;
  }
};

int main() {
  Solution s;
  cout << s.countAndSay(1) << endl;  // Output: "1"
  cout << s.countAndSay(4) << endl;  // Output: "1211"

  return 0;
}
