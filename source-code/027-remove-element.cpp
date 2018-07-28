#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    int pos = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != val) {
        nums[pos++] = nums[i];
      }
    }
    return pos;
  }
};

int main() {
  Solution s;
  vector<int> input_1{3, 2, 2, 3};
  int result_1 = s.removeElement(input_1, 3);
  // Output: 2: 2, 2, ...
  cout << result_1 << ": ";
  for (int i = 0; i < input_1.size(); i++) {
    cout << input_1[i] << " ";
  }
  cout << endl;

  vector<int> input_2{0, 1, 2, 2, 3, 0, 4, 2};
  int result_2 = s.removeElement(input_2, 2);
  // Output: 5: 0, 1, 3, 0, 4, ...
  cout << result_2 << ": ";
  for (int i = 0; i < input_2.size(); i++) {
    cout << input_2[i] << " ";
  }
  cout << endl;
  return 0;
}
