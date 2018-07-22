#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  string convert(string s, int numRows) {
    if (numRows <= 1 || s.size() <= numRows) {
      return s;
    }

    vector<string> string_buffer(numRows);  // vector size.
    int current_row = 0;
    int next_step = 1;
    for (int i = 0; i < s.size(); ++i) {
      if (current_row == 0) {
        next_step = 1;
      }
      if (current_row == numRows - 1) {
        next_step = -1;
      }

      string_buffer[current_row] += s[i];
      current_row += next_step;
    }

    string result;
    for (int i = 0; i < numRows; ++i) {
      result += string_buffer[i];
    }
    return result;
  }
};

int main() {
  Solution s;
  cout << s.convert("PAYPALISHIRING", 3) << endl; // Output: "PAHNAPLSIIGYIR"
  cout << s.convert("PAYPALISHIRING", 4) << endl; // Output: "PINALSIGYAHRPI"
  cout << s.convert("ABC", 1) << endl; // Output: "PINALSIGYAHRPI"
  return 0;
}
