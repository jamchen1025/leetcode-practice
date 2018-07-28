#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  int strStr(string haystack, string needle) {
    if (needle.size() == 0) {
      return 0;
    }
    if (haystack.size() == 0 || haystack.size() < needle.size()) {
      return -1;
    }
    for (int i = 0; i < haystack.size(); ++i) {
      if (haystack[i] == needle[0]) {
        int h = i + 1;
        int n = 1;
        while (h < haystack.size() && n < needle.size() &&
               haystack[h] == needle[n]) {
          ++h;
          ++n;
        }
        if (n == needle.size()) {
          return i;
        }
      }
    }
    return -1;
  }
};

int main() {
  Solution s;
  cout << s.strStr("hello", "ll") << endl;   // Output: 2
  cout << s.strStr("aaaaa", "bba") << endl;  // Output: -1
  return 0;
}
