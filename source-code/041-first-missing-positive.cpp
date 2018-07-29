#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  int firstMissingPositive(vector<int>& nums) {
    int len = (int)nums.size();
    if (len == 0) {
      return 1;
    }

    for (int i = 0; i < len; ++i) {
      while (0 < nums[i] && nums[i] <= len && nums[nums[i] - 1] != nums[i]) {
        swap(nums[i], nums[nums[i] - 1]);
      }
    }

    for (int i = 0; i < len; ++i) {
      if (i + 1 != nums[i]) {
        return i + 1;
      }
    }
    return len + 1;
  }
};

int main() {
  Solution s;
  vector<int> input_1{1, 2, 0};
  cout << s.firstMissingPositive(input_1) << endl;  // Output: 3

  vector<int> input_2{3, 4, -1, 1};
  cout << s.firstMissingPositive(input_2) << endl;  // Output: 2

  vector<int> input_3{7, 8, 9, 11, 12};
  cout << s.firstMissingPositive(input_3) << endl;  // Output: 1

  vector<int> input_4{1, 2, 3};
  cout << s.firstMissingPositive(input_4) << endl;  // Output: 4

  vector<int> input_5{2, 1};
  cout << s.firstMissingPositive(input_5) << endl;  // Output: 3

  vector<int> input_6{-1, 4, 2, 1, 9, 10};
  cout << s.firstMissingPositive(input_6) << endl;  // Output: 3

  return 0;
}
