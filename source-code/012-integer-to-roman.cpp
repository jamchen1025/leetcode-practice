#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  string intToRoman(int num) {
    string symbols[] = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                       "XL", "X",  "IX", "V",  "IV", "I"};
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string result = "";

    int i = 0;
    while (num > 0) {
      if (num < values[i]) {
        ++i;
        continue;
      }
      num -= values[i];
      result += symbols[i];
    }
    return result;
  }
};

int main() {
  Solution s;
  cout << s.intToRoman(3) << endl;   // Output: "III"
  cout << s.intToRoman(4) << endl;   // Output: "IV"
  cout << s.intToRoman(9) << endl;   // Output: "IX"
  cout << s.intToRoman(58) << endl;  // Output: "LVIII"
  // Explanation: L = 50, V = 5 and III = 3.
  cout << s.intToRoman(1994) << endl;  // Output: "MCMXCIV"
  // Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
  return 0;
}
