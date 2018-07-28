#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int len = (int)nums.size();
    if (len <= 1) {
      return len;
    }
    int index = 1;
    for (int i = 1; i < len; ++i) {
      if (nums[i] != nums[i - 1]) {
        if (i != index) {
          nums[index] = nums[i];
        }
        ++index;
      }
    }
    return index;
  }
};

int main() {
  Solution s;
  vector<int> input_1{1, 1, 2};
  int result_1 = s.removeDuplicates(input_1);
  // Output: 2: 1, 2, ...
  cout << result_1 << ": ";
  for (int i = 0; i < input_1.size(); i++) {
    cout << input_1[i] << " ";
  }
  cout << endl;

  vector<int> input_2{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  int result_2 = s.removeDuplicates(input_2);
  // Output: 5: 0, 1, 2, 3, 4, ...
  cout << result_2 << ": ";
  for (int i = 0; i < input_2.size(); i++) {
    cout << input_2[i] << " ";
  }
  cout << endl;
  return 0;
}
