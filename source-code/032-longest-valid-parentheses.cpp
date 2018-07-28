#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
 public:
  int longestValidParentheses(string s) {
    int max_len = 0;
    int start = -1;
    stack<int> st;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(') {
        st.push(i);
      } else {
        if (st.empty() == true) {
          start = i;
        } else {
          st.pop();
          int len;
          if (st.size() == 0) {
            len = i - start;
          } else {
            len = i - st.top();
          }
          if (len > max_len) {
            max_len = len;
          }
        }
      }
    }
    return max_len;
  }
};

int main() {
  Solution s;
  cout << s.longestValidParentheses("(()") << endl;     // Output: 2
  cout << s.longestValidParentheses(")()())") << endl;  // Output: 4
  cout << s.longestValidParentheses("())()") << endl;   // Output: 2
  cout << s.longestValidParentheses("()(()") << endl;   // Output: 2

  return 0;
}
