/********************************************************************************** 
題目：
https://leetcode.com/problems/jump-game/description/
Given an array of non-negative integers,
you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.
Example 1:
Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:
Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum
             jump length is 0, which makes it impossible to reach the last index.
**********************************************************************************
想法：
**********************************************************************************/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  bool canJump(vector<int>& nums) {
    int max = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (max < i) {
        return false;
      }
      if (max < i + nums[i]) {
        max = i + nums[i];
      }
    }
    return true;
  }
};

int main() {
  Solution s;

  vector<int> input_1{{2, 3, 1, 1, 4}};
  cout << s.canJump(input_1) << endl;  // Output: true
  // Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

  vector<int> input_2{{3, 2, 1, 0, 4}};
  cout << s.canJump(input_2) << endl;  // Output: false
  // Explanation: You will always arrive at index 3 no matter what. Its maximum
  // jump length is 0, which makes it impossible to reach the last index.

  return 0;
}
