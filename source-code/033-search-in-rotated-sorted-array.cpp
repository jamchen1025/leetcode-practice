#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  int search(vector<int>& nums, int target) {
    if (nums.size() == 0) {
      return -1;
    }

    int low = 0;
    int high = (int)nums.size() - 1;
    int mid;
    int sort_low = low;
    int sort_high = high;
    while (low <= high) {
      mid = low + (high - low) / 2;
      if (nums[low] <= nums[mid]) {
        sort_low = low;
        sort_high = mid;
        low = mid + 1;
        high = high;
      } else {
        sort_low = mid + 1;
        sort_high = high;
        low = low;
        high = mid;
      }

      if (target == nums[sort_low]) {
        return sort_low;
      } else if (target == nums[sort_high]) {
        return sort_high;
      } else if (nums[sort_low] <= target && target <= nums[sort_high]) {
        break;
      }
    }

    low = sort_low;
    high = sort_high;
    while (low <= high) {
      mid = low + (high - low) / 2;
      if (target == nums[mid]) {
        return mid;
      } else if (target < nums[mid]) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    return -1;
  }
};

int main() {
  Solution s;
  vector<int> input_1{4, 5, 6, 7, 0, 1, 2};
  cout << s.search(input_1, 0) << endl;  // Output: 4

  vector<int> input_2{4, 5, 6, 7, 0, 1, 2};
  cout << s.search(input_2, 7) << endl;  // Output: -1

  vector<int> input_3{1};
  cout << s.search(input_3, 1) << endl;  // Output: 0

  vector<int> input_4{1, 3};
  cout << s.search(input_4, 3) << endl;  // Output: 1

  vector<int> input_5{5, 1, 2, 3, 4};
  cout << s.search(input_5, 4) << endl;  // Output: 4

  return 0;
}
