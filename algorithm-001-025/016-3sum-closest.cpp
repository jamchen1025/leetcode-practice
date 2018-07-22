#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>

using namespace std;

class Solution {
 public:
  int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());

    int min_distance = INT_MAX;
    int result = 0;
    for (int i = 0; i < nums.size() - 2; ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      int l = i + 1;
      int r = (int)nums.size() - 1;
      while (l < r) {
        int sum = nums[i] + nums[l] + nums[r];
        int distance = sum - target;
        if (distance == 0) {
          return sum;
        } else {
          if (abs(distance) < min_distance) {
            min_distance = abs(distance);
            result = sum;
          }

          if (distance < 0) {
            while (l < r && nums[l] == nums[l + 1]) {
              ++l;
            }
            ++l;
          } else {
            while (l < r && nums[r] == nums[r - 1]) {
              --r;
            }
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
  vector<int> input_1{-1, 2, 1, -4};
  cout << s.threeSumClosest(input_1, 1) << endl;
  // Output:
  // The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
  return 0;
}
