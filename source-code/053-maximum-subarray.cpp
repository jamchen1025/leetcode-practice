#include <iostream>
#include <vector>
#include <string>
#include <limits.h>

using namespace std;

class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    vector<int> dp(nums.size());
    dp[0] = nums[0];
    int result = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
      dp[i] = nums[i] + (dp[i - 1] < 0 ? 0 : dp[i - 1]);
      result = max(result, dp[i]);
    }
    return result;
  }
};

int main() {
  Solution s;
  vector<int> input_1{-2, 1, -3, 4, -1, 2, 1, -5, 4};
  cout << s.maxSubArray(input_1) << endl;  // Output: 6
  // Explanation: [4,-1,2,1] has the largest sum = 6.
  vector<int> input_2{-1, -2, -3, -4};
  cout << s.maxSubArray(input_2) << endl;  // Output: -1
  vector<int> input_3{-1, -2, -3, 0};
  cout << s.maxSubArray(input_3) << endl;  // Output: 0
  return 0;
}
