/********************************************************************************** 
題目：
https://leetcode.com/problems/plus-one/description/
Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.
You may assume the integer does not contain any leading zero, except the number 0 itself.
Example 1:
Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:
Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
**********************************************************************************
想法：
用carry紀錄進位
用vector.insert(aa.begin(), value);插在前面位置
**********************************************************************************/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
 public:
  vector<int> plusOne(vector<int>& digits) {
    vector<int> r;
    if (digits.size() == 0) {
      return {1};
    }
    int carry = 1;
    for (int i = (int)digits.size() - 1; i >= 0; --i) {
      r.insert(r.begin(), (digits[i] + carry) % 10);
      carry = (digits[i] + carry) / 10;
    }
    if (carry != 0) {
      r.insert(r.begin(), carry);
    }

    return r;
  }
};

int main() {
  Solution s;
  vector<int> input_1{1, 2, 3};
  vector<int> result_1 = s.plusOne(input_1);
  for (int i = 0; i < result_1.size(); ++i) {
    cout << result_1[i] << " ";
  }
  cout << endl;
  // Output: [1,2,4]
  // Explanation: The array represents the integer 123.

  vector<int> input_2{4, 3, 2, 1};
  vector<int> result_2 = s.plusOne(input_2);
  for (int i = 0; i < result_2.size(); ++i) {
    cout << result_2[i] << " ";
  }
  cout << endl;
  // Output: [4,3,2,2]
  // Explanation: The array represents the integer 4321.
  return 0;
}
