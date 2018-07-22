#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  string longestPalindrome(string s) {
    const int len = (int)s.size();
    if (len == 0) return s;

    int max_len = 0;
    string result_str;
    for (int i = 0; i < len; ++i) {
      findPalindrome(s, i, i, max_len, result_str);
      findPalindrome(s, i, i + 1, max_len, result_str);
    }
    return result_str;
  }

  void findPalindrome(string s, int left, int right, int& max,
                      string& result_str) {
    while (0 <= left && right < s.size() && s[left] == s[right]) {
      --left;
      ++right;
    }
    if (max < right - left - 1) {
      max = right - left - 1;
      result_str = s.substr(left + 1, max);
    }
  }
};

int main() {
  Solution s;
  cout << s.longestPalindrome("babad") << endl; // Output: "bab"
  return 0;
}
