#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> empty{-1, -1};
    if (nums.size() == 0) {
      return empty;
    }
    int first = findFirst(nums, target);
    if (first == -1) {
      return empty;
    }
    int last = findLast(nums, target);

    vector<int> result{first, last};
    return result;
  }

  int findFirst(vector<int>& nums, int target) {
    int l = 0;
    int r = (int)nums.size() - 1;
    while (l + 1 < r) {
      int m = l + (r - l) / 2;
      if (target <= nums[m]) {
        r = m;
      } else {
        l = m;
      }
    }
    if (target == nums[l]) return l;
    if (target == nums[r]) return r;
    return -1;
  }

  int findLast(vector<int>& nums, int target) {
    int l = 0;
    int r = (int)nums.size() - 1;
    while (l + 1 < r) {
      int m = l + (r - l) / 2;
      if (target < nums[m]) {
        r = m;
      } else {
        l = m;
      }
    }

    if (target == nums[r]) return r;
    if (target == nums[l]) return l;
    return -1;
  }
};

int main() {
  Solution s;
  vector<int> input_1{5, 7, 7, 8, 8, 10};
  vector<int> result_1 = s.searchRange(input_1, 8);
  for (int i = 0; i < result_1.size(); ++i) {
    cout << result_1[i] << " ";
  }
  cout << endl;
  // Output: [3,4]

  vector<int> input_2{5, 7, 7, 8, 8, 10};
  vector<int> result_2 = s.searchRange(input_1, 6);
  for (int i = 0; i < result_2.size(); ++i) {
    cout << result_2[i] << " ";
  }
  cout << endl;
  // Output: [-1,-1]

  return 0;
}
