/********************************************************************************** 
題目：
https://leetcode.com/problems/two-sum/description/
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
Example:
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
**********************************************************************************
想法：
利用map，查看是否有target - nums[i]的值出現過
如果沒有就把{nums[i], i}存到map中
**********************************************************************************/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> m;
    for (int i = 0; i < nums.size(); ++i) {
      if (m.find(target - nums[i]) != m.end()) {
        return {m[target - nums[i]], i};
      }
      m[nums[i]] = i;
    }
  }
};

int main() {
  vector<int> inputs{2, 7, 11, 15};
  Solution s;
  vector<int> r = s.twoSum(inputs, 9);
  for (int i = 0; i < r.size(); ++i) cout << r.at(i) << " ";
  cout << "\n";
  return 0;
}
