/**********************************************************************************
題目：
https://leetcode.com/problems/zigzag-conversion/description/
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows 
ike this: (you may want to display this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows
string convert(string s, int numRows);
Example 1:
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
**********************************************************************************
想法：
準備numRows個string
依照zigzag的順序push進去後結合起來
**********************************************************************************/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  string convert(string s, int numRows) {
    const int s_len = (int)s.size();
    if (s_len <= numRows || numRows <= 1) {
      return s;
    }

    vector<string> string_buffer(numRows);
    int current = 0;
    int step = 1;
    for (int i = 0; i < s_len; ++i) {
      if (current == 0) {
        step = 1;
      }
      if (current == numRows - 1) {
        step = -1;
      }
      string_buffer[current] += s[i];
      current += step;
    }
    string result = "";
    for (int i = 0; i < numRows; ++i) {
      result = result + string_buffer[i];
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
