#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> m;
    int max_len = 0;
    int last_repeat_index = -1;
    for (int i = 0; i < s.size(); ++i) {
      if (m.find(s[i]) != m.end()) {
        if (last_repeat_index < m[s[i]]) {
          last_repeat_index = m[s[i]];
        }
      }
      if (i - last_repeat_index > max_len) {
        max_len = i - last_repeat_index;
      }
      m[s[i]] = i;
    }
    return max_len;
  }
};

int main() {
  Solution s;
  int r1 = s.lengthOfLongestSubstring("abcabcbb"); // answer is "abc", length is 3.
  int r2 = s.lengthOfLongestSubstring("bbbbb"); // answer is "b", length is 1.
  int r3 = s.lengthOfLongestSubstring("pwwkew"); // answer is "wke", length is 3.
  cout << "r1: " << r1 << endl;
  cout << "r2: " << r2 << endl;
  cout << "r3: " << r3 << endl;
  return 0;
}
