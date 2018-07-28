#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    if (nums.size() == 0) {
      return 0;
    }

    int l = 0;
    int r = (int)nums.size() - 1;
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (target == nums[m]) {
        return m;
      } else if (target < nums[m]) {
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    return l;
  }
};

int main() {
  Solution s;
  vector<int> input_1{1, 3, 5, 6};
  cout << s.searchInsert(input_1, 5) << endl;  // Output: 2

  vector<int> input_2{1, 3, 5, 6};
  cout << s.searchInsert(input_2, 2) << endl;  // Output: 1

  vector<int> input_3{1, 3, 5, 6};
  cout << s.searchInsert(input_3, 7) << endl;  // Output: 4

  vector<int> input_4{1, 3, 5, 6};
  cout << s.searchInsert(input_4, 0) << endl;  // Output: 0

  return 0;
}
