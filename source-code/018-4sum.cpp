#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    if (nums.size() <= 3) {
      return {};
    }

    sort(nums.begin(), nums.end());

    vector<vector<int>> result;
    for (int i = 0; i < nums.size() - 3; ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      for (int j = i + 1; j < nums.size() - 2; ++j) {
        if (j > i + 1 && nums[j] == nums[j - 1]) {
          continue;
        }
        int l = j + 1;
        int r = (int)nums.size() - 1;
        while (l < r) {
          int sum = nums[i] + nums[j] + nums[l] + nums[r];
          if (sum == target) {
            result.push_back({nums[i], nums[j], nums[l], nums[r]});
            while (l < r && nums[l] == nums[l + 1]) {
              ++l;
            }
            while (l < r && nums[r] == nums[r - 1]) {
              --r;
            }
            ++l;
            --r;
          } else if (sum < target) {
            ++l;
          } else {
            --r;
          }
        }
      }
    }

    return result;
  }
};

int main() {
  Solution s;
  vector<int> input_1{1, 0, -1, 0, -2, 2};
  vector<vector<int>> result = s.fourSum(input_1, 0);
  for (int i = 0; i < result.size(); ++i) {
    for (int j = 0; j < result[i].size(); ++j) {
      cout << result[i][j] << " ";
    }
    cout << endl;
  }
  // Output:
  // [
  //  [-1,  0, 0, 1],
  //  [-2, -1, 1, 2],
  //  [-2,  0, 0, 2]
  // ]
  return 0;
}
