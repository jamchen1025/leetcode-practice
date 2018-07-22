#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    string result = "";
    if (strs.size() <= 0) {
      return result;
    }
    int index = 0;
    for (int i = 0; i < strs[0].size(); ++i) {
      bool match = true;
      for (int j = 1; j < strs.size(); j++) {
        if (strs[0][index] != strs[j][index]) {
          match = false;
          break;
        }
      }

      if (match == true) {
        ++index;
      } else {
        return strs[0].substr(0, index);
      }
    }
    return strs[0].substr(0, index);
  }
};

int main() {
  Solution s;
  vector<string> input_1{"flower", "flow", "flight"};
  cout << s.longestCommonPrefix(input_1) << endl;  // Output: "fl"
  vector<string> input_2{"flower", "flower33", "flower11"};
  cout << s.longestCommonPrefix(input_2) << endl;  // Output: "flower"
  vector<string> input_3{"dog", "racecar", "car"};
  cout << s.longestCommonPrefix(input_3) << endl;  // Output: ""
  return 0;
}
