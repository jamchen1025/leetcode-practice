#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  int romanToInt(string s) {
    string symbols[] = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                        "XL", "X",  "IX", "V",  "IV", "I"};
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    int result = 0;
    int s_idx = 0;
    int symbol_idx = 0;
    while (s_idx < s.size()) {
      bool match = true;
      int i = 0;
      string symbol = symbols[symbol_idx];
      while (i < symbol.size()) {
        if (s[s_idx + i] != symbol[i]) {
          match = false;
          break;
        }
        ++i;
      }
      if (match == false) {
        ++symbol_idx;
      } else {
        s_idx += symbol.size();
        result += values[symbol_idx];
      }
    }
    return result;
  }
};

int main() {
  Solution s;
  cout << s.romanToInt("III") << endl;    // Output: 3
  cout << s.romanToInt("IV") << endl;     // Output: 4
  cout << s.romanToInt("IX") << endl;     // Output: 9
  cout << s.romanToInt("LVIII") << endl;  // Output: 58
  // Explanation: L = 50, V = 5 and III = 3.
  cout << s.romanToInt("MCMXCIV") << endl;  // Output: 1994
  // Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
  return 0;
}
