/********************************************************************************** 
題目：
https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
Given a string, find the length of the longest substring without repeating characters.
Examples:
Given "abcabcbb", the answer is "abc", which the length is 3.
Given "bbbbb", the answer is "b", with the length of 1.
Given "pwwkew", the answer is "wke", with the length of 3.
Note that the answer must be a substring,
"pwke" is a subsequence and not a substring.
**********************************************************************************
想法：
利用map記錄字元是否有出現過
利用last_idx保留目前左邊"已重複"字元的位置，預設為-1
如果遇到重複字元，就把last_idx更新到最右邊的"已重複"字元的位置
**********************************************************************************/
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int last_idx = -1;
    int max_len = 0;
    map<char, int> m;
    for (int i = 0; i < s.size(); ++i) {
      if (m.find(s[i]) != m.end()) {
        last_idx = max(last_idx, m[s[i]]);
      }
      m[s[i]] = i;
      if (max_len < i - last_idx) {
        max_len = i - last_idx;
      }
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
