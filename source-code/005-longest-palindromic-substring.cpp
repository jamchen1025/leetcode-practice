/**********************************************************************************
題目：
https://leetcode.com/problems/longest-palindromic-substring/description/
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
Example 1:
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:
Input: "cbbd"
Output: "bb"
**********************************************************************************
想法：
for迴圈從頭開始尋找
回文有分aba和abba兩種，所以找回文時要分別找這兩種的長度，
紀錄最長的回傳
* 記得在findPalindrome裡面比完大小回傳就好了...
**********************************************************************************/
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
