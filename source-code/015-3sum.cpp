#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    if (nums.size() <= 2) {
      return result;
    }

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 2; ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      int l = i + 1;
      int r = (int)nums.size() - 1;
      while (l < r) {
        int sum = nums[i] + nums[l] + nums[r];
        if (sum == 0) {
          result.push_back({nums[i], nums[l], nums[r]});
          while (l < r && nums[l] == nums[l + 1]) {
            ++l;
          }
          while (l < r && nums[r] == nums[r - 1]) {
            --r;
          }
          ++l;
          --r;
        } else if (sum < 0) {
          ++l;
        } else {
          --r;
        }
      }
    }

    return result;
  }
};

int main() {
  Solution s;
  vector<int> input_1{-1, 0, 1, 2, -1, -4};
  vector<vector<int>> result = s.threeSum(input_1);
  for (int i = 0; i < result.size(); ++i) {
    for (int j = 0; j < result[i].size(); ++j) {
      cout << result[i][j] << " ";
    }
    cout << endl;
  }
  // Output:
  //  [
  //   [-1, 0, 1],
  //   [-1, -1, 2]
  //  ]
  return 0;
}
