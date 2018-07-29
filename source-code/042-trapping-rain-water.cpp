#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  int trap(vector<int>& height) {
    int len = (int)height.size();
    if (len == 0) {
      return 0;
    }
    int max_heght = 0;
    int max_height_idx = -1;

    for (int i = 0; i < len; ++i) {
      if (height[i] > max_heght) {
        max_heght = height[i];
        max_height_idx = i;
      }
    }
    int count = 0;
    int current_height = 0;
    for (int i = 0; i < max_height_idx; ++i) {
      if (height[i] > current_height) {
        current_height = height[i];
      }
      count += current_height - height[i];
    }
    current_height = 0;

    for (int i = len - 1; i >= max_height_idx; --i) {
      if (height[i] > current_height) {
        current_height = height[i];
      }
      count += current_height - height[i];
    }

    return count;
  }
};

int main() {
  Solution s;
  vector<int> input_1{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  cout << s.trap(input_1) << endl;  // Output: 6
  return 0;
}
