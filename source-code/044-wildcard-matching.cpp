#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  bool isMatch(string s, string p) {
    int s_len = (int)s.size();
    int p_len = (int)p.size();
    vector<vector<bool>> dp;
    for (int i = 0; i < (s_len + 1); ++i) {
      vector<bool> temp;
      for (int j = 0; j < (p_len + 1); ++j) {
        temp.push_back(false);
      }
      dp.push_back(temp);
    }

    // dp 初始化
    // 初始化第0格，p空字串只能匹配空字串，初始化第0列，其他都是false
    dp[0][0] = true;
    // 初始化第0行，如果p含有*，則該值(dp[0][j])一定和前前一個的值dp[0][j -
    // 2]相同
    for (int j = 1; j < (p_len + 1); ++j) {
      // 注意因為初始化空字串的關係dp會比p多一格，dp[][j]會對應p[j - 1]
      dp[0][j] = ((j > 0) && (p[j - 1] == '*' && dp[0][j - 1] == true));
    }

    for (int i = 1; i < (s_len + 1); ++i) {
      for (int j = 1; j < (p_len + 1); ++j) {
        if (p[j - 1] == '*') {
          dp[i][j] = (dp[i - 1][j] || dp[i][j - 1]);
        } else {
          // 否則就只有當前字符匹配，才能傳遞dp的true值
          dp[i][j] =
              ((p[j - 1] == '?' || (s[i - 1] == p[j - 1])) && dp[i - 1][j - 1]);
        }
      }
    }

    return dp[s_len][p_len];
  }
};

int main() {
  Solution s;
  cout << s.isMatch("aa", "a") << endl;
  // Output: false
  // Explanation: "a" does not match the entire string "aa".
  cout << s.isMatch("aa", "*") << endl;
  // Output: true
  // Explanation: '*' matches any sequence.
  cout << s.isMatch("cb", "?a") << endl;
  // Output: false
  // Explanation: '?' matches 'c', but the second letter is 'a', which does not
  // match 'b'.
  cout << s.isMatch("adceb", "*a*b") << endl;
  // Output: true
  // Explanation: The first '*' matches the empty sequence, while the second '*'
  // matches the substring "dce".
  cout << s.isMatch("acdcb", "a*c?b") << endl;
  // Output: false
  cout << s.isMatch("abefcdgiescdfimde", "ab*cd?i*de") << endl;
  // Output: true
  return 0;
}
