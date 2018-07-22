#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    if (digits.size() <= 0) {
      return {};
    }

    // check if digits has no digit str
    for (int i = 0; i < digits.size(); ++i) {
      if (!isdigit(digits[i])) {
        return {};
      }
    }

    string phone_str[10] = {" ",   "",    "abc",  "def", "ghi",
                            "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> result;
    result.push_back("");
    for (int i = 0; i < digits.size(); ++i) {
      int num = digits[i] - '0';
      vector<string> added;
      for (int j = 0; j < result.size(); j++) {
        for (int k = 0; k < phone_str[num].size(); ++k) {
          added.push_back(result[j] + phone_str[num][k]);
        }
      }
      result = added;
    }
    return result;
  }
};

int main() {
  Solution s;
  vector<string> result = s.letterCombinations("23");
  // Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
  for (int i = 0; i < result.size(); ++i) {
    cout << result[i] << ".\n";
  }
  return 0;
}
