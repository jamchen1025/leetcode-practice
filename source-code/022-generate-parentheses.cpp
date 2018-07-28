#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    if (n <= 0) {
      return {};
    }
    vector<string> result;
    string s;
    generator(result, n, n, s);
    return result;
  }

  void generator(vector<string>& result, int rest_l, int rest_r, string s) {
    if (rest_l > rest_r) {
      return;
    }
    if (rest_l == 0 && rest_r == 0) {
      result.push_back(s);
      return;
    }
    if (rest_l > 0) {
      generator(result, rest_l - 1, rest_r, s + '(');
    }
    if (rest_r > 0) {
      generator(result, rest_l, rest_r - 1, s + ')');
    }
  }
};

int main() {
  Solution s;
  vector<string> result = s.generateParenthesis(3);
  for (int i = 0; i < result.size(); ++i) {
    cout << result[i] << endl;
  }
  // [
  //     "((()))",
  //     "(()())",
  //     "(())()",
  //     "()(())",
  //     "()()()"
  // ]
  return 0;
}
