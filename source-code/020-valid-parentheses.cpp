#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
 public:
  bool isValid(string s) {
    std::stack<char> st;
    for (int i = 0; i < s.size(); ++i) {
      char c = s[i];
      if (c == '(' || c == '{' || c == '[') {
        st.push(c);
      } else if (c == ')' || c == '}' || c == ']') {
        if (st.empty() == true) return false;
        char top_c = st.top();
        if ((top_c == '(' && c == ')') || (top_c == '{' && c == '}') ||
            (top_c == '[' && c == ']')) {
          st.pop();
        } else {
          return false;
        }
      } else {
        return false;
      }
    }
    return st.empty();
  }
};

int main() {
  Solution s;
  cout << s.isValid("()") << endl;      // Output: true
  cout << s.isValid("()[]{}") << endl;  // Output: true
  cout << s.isValid("(]") << endl;      // Output: false
  cout << s.isValid("([)]") << endl;    // Output: false
  cout << s.isValid("{[]}") << endl;    // Output: true

  return 0;
}
