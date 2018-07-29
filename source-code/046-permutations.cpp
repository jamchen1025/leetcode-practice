#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  vector<vector<int>> permute(vector<int>& nums) {
    if (nums.size() == 0) {
      return {};
    }
    vector<vector<int>> result;
    vector<int> list;
    helper(result, list, nums);
    return result;
  }

  void helper(vector<vector<int>>& result, vector<int> list, vector<int> nums) {
    if (list.size() == nums.size()) {
      result.push_back(list);
      return;
    }
    for (int i = 0; i < nums.size(); ++i) {
      bool has_value = false;
      for (int j = 0; j < list.size(); ++j) {
        if (list[j] == nums[i]) {
          has_value = true;
        }
      }
      if (has_value == true) {
        continue;
      }
      list.push_back(nums[i]);
      helper(result, list, nums);
      list.pop_back();
    }
  }
};

int main() {
  Solution s;
  vector<int> input_1{1, 2, 3};
  vector<vector<int>> result_1 = s.permute(input_1);
  for (int i = 0; i < result_1.size(); ++i) {
    for (int j = 0; j < result_1[i].size(); ++j) {
      cout << result_1[i][j] << " ";
    }
    cout << endl;
  }
  // Output:
  // [
  //  [1,2,3],
  //  [1,3,2],
  //  [2,1,3],
  //  [2,3,1],
  //  [3,1,2],
  //  [3,2,1]
  // ]
  return 0;
}
